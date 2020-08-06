#include "Inertial_Unit.hpp"

Inertial_Unit::Inertial_Unit(const Sim::InertialSensor *sensor, int step) :
    Device("Inertial_Unit"),
    m_inertial_unit {wb_robot_get_device("inertial unit")},
    m_accelerometer {wb_robot_get_device("accelerometer")},
    m_gyroscope {wb_robot_get_device("gyro")},
    m_sensor {sensor}, m_filters {std::vector<Low_Pass_Filter*>(7)}
{
    std::cout << "\n\t\t\t\t\t" << __FILE__ << ": Inside constructor.";
    
    if (m_inertial_unit)
        wb_inertial_unit_enable(m_inertial_unit, step);
    if (m_accelerometer)
        wb_accelerometer_enable(m_accelerometer, step);
    if (m_gyroscope)
        wb_gyro_enable(m_gyroscope, step);
    for (auto& value : m_filters)
        value = new Low_Pass_Filter(step, 60);
}

void Inertial_Unit::update()
{
    if (!m_inertial_unit && !m_accelerometer && !m_gyroscope)
        return;

    // Unknown values
    double angle_X {}, angle_Y {}, acc_X {}, acc_Y {}, acc_Z {}, gyr_X {}, gyr_Y {};

    if (m_inertial_unit) {
        // Roll/pitch/yaw angles in rad
        const double *rpy {wb_inertial_unit_get_roll_pitch_yaw(m_inertial_unit)};
        angle_X = rpy[0], angle_Y = -rpy[1]; // roll, -pitch
    }

    if (m_accelerometer) {
        // Linear acceleration in m/s^2
        const double *acc {wb_accelerometer_get_values(m_accelerometer)};
        acc_X = acc[0], acc_Y = acc[1], acc_Z = acc[2];
    }

    if (m_gyroscope) {
        // Angular velocity in rad/s
        const double *ang_vel {wb_gyro_get_values(m_gyroscope)};
        gyr_X = ang_vel[0], gyr_Y = ang_vel[1];
    }

    // Filter values
    std::vector angles {&angle_X, &angle_Y, &acc_X, &acc_Y, &acc_Z, &gyr_X, &gyr_Y};
    
    // yb: this is the data order expected by HAL according to the
    // dummysim.cpp example
    // In case there was a doubt, the order can be checked by using "monitor"
    // and following keys in the memory viewer
    std::vector<float> values;
    
    for (int i {0}; i < 7; i++) {
        m_filters[i]->append_raw_value(*angles[i]);
        values.push_back(static_cast<float>(m_filters[i]->filtered_value()));
        // Device/SubDeviceList/InertialSensor/Angle_X/Sensor/Value
        // Device/SubDeviceList/InertialSensor/Angle_Y/Sensor/Value
        // Device/SubDeviceList/InertialSensor/AccelerometerX/Sensor/Value
        // Device/SubDeviceList/InertialSensor/AccelerometerY/Sensor/Value
        // Device/SubDeviceList/InertialSensor/AccelerometerZ/Sensor/Value
        // Device/SubDeviceList/InertialSensor/GyroscopeX/Sensor/Value
        // Device/SubDeviceList/InertialSensor/GyroscopeY/Sensor/Value
    }

    if (! Singletons::hal()->sendInertialSensorValues(m_sensor, values))
        std::cerr << "\nCERR << Sim::HALInterface::sendInertialSensorValues() failed.\n";
}

Inertial_Unit::~Inertial_Unit()
{
    for (auto& value : m_filters)
        delete value;
}
