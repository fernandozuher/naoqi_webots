#include "Fsr.hpp"

Fsr::Fsr(std::vector<const Sim::FSRSensor*> sensors, int step, std::string name) :
         Device(name), m_filter(std::vector<Low_Pass_Filter *>(4))
{
    std::cout << "\n\t\t\t\t\t" << __FILE__ << ": Inside constructor.";
    
    m_fsr_sensors = sensors;
    m_tag = wb_robot_get_device(name.c_str());
    if (!m_tag)
        std::cerr << "\nCERR << Webots device not found for Sim::FSRSensor: "
        << name << "\n";
    else
        wb_touch_sensor_enable(m_tag, step);

    for (auto& filter : m_filter)
        filter = new Low_Pass_Filter(step, 60);
}

void Fsr::update()
{
    if (!m_tag)
        return;

    __infer_values();

    for (int i {0}, N {static_cast<int>(m_filter.size())}; i < N; i++)
        if (!Singletons::hal()->sendFSRSensorValue(m_fsr_sensors[i],
            static_cast<float>(m_filter[i]->filtered_value())))
                std::cerr << "\nCERR << Sim::HALInterface::sendFSRSensorValue() "
                        "failed.\n";
}

void Fsr::__infer_values()
{
    const double *fsv {wb_touch_sensor_get_values(m_tag)};
    std::vector<double> val;

    // The coefficients were calibrated against the real
    // robot so as to obtain realistic sensor values.
    val.push_back(fsv[2]/3.4 + 1.5*fsv[0] + 1.15*fsv[1]); // FL
    val.push_back(fsv[2]/3.4 + 1.5*fsv[0] - 1.15*fsv[1]); // FR
    val.push_back(fsv[2]/3.4 - 1.5*fsv[0] + 1.15*fsv[1]); // RL
    val.push_back(fsv[2]/3.4 - 1.5*fsv[0] - 1.15*fsv[1]); // RR

    for (int i {0}, N {static_cast<int>(m_filter.size())}; i < N; i++) {
        val[i] = util::clamp(val[i], 0, 25) * TO_KILOGRAMS;
        m_filter[i]->append_raw_value(val[i]);
    }
}

Fsr::~Fsr() { }