#include "Sonar.hpp"

Sonar::Sonar(const Sim::SonarSensor *sensor, int step) : Device(sensor->name()),
    m_tag {wb_robot_get_device(name().c_str())}, m_sensor {sensor}
{
    std::cout << "\n\t\t\t\t\t" << __FILE__ << ": Inside constructor.";

    if (!m_tag)
    std::cerr << "\nCERR << Webots DistanceSensor not found for Sim::SonarSensor: "
         << name() << "\n";
    else
        wb_distance_sensor_enable(m_tag, step);
}

void Sonar::update() {

    if (!m_tag)
        return;

    // send 10 echoe values, only the 1st one is used by the HAL
    if (m_sensor && 
        !Singletons::hal()->sendSonarSensorValues(m_sensor, 
        std::vector<float>(10, static_cast<float>(wb_distance_sensor_get_value(m_tag)))))
            std::cerr << "\nCERR << Sim::HALInterface::sendSonarSensorValues() failed.\n";
}

Sonar::~Sonar() { }