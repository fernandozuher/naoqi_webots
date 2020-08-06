#include "Motor.hpp"

Motor::Motor(const Sim::AngleActuator *actuator, int step) :
             Device(actuator->name()), m_actuator {actuator}
{
    std::cout << "\n\t\t\t\t\t" << __FILE__ << ": Inside constructor.";
    
    m_tag = wb_robot_get_device(name().c_str());
    std::string sensor_name {name()};
    sensor_name.push_back('S');
    m_sensor_tag = wb_robot_get_device(sensor_name.c_str());

    if (!m_tag) {
        std::cerr << "\nCERR << Webots Motor not found for Sim::AngleActuator: " 
             << name() << std::endl;
        m_max_position = 0.0;
        m_min_position = 0.0;
    }
    else {
        m_max_position = wb_motor_get_max_position(m_tag);
        m_min_position = wb_motor_get_min_position(m_tag);
    }

    if (!m_sensor_tag)
        std::cerr << "\nCERR << Webots PositionSensor not found for "
             << "Sim::AngleSensor: " << name() << std::endl;
    else
        wb_position_sensor_enable(m_sensor_tag, step);

    m_sensor = Singletons::model()->angleSensor(name());
    if (!m_sensor)
        std::cerr << "\nCERR << Sim::AngleSensor not found for motor: " << name() << "\n";
}

void Motor::update()
{
    if (!m_tag)
        return;

    // Set target position
    double target {Singletons::hal()->fetchAngleActuatorValue(m_actuator)};
    if (isnan(target)) {
        target = m_actuator->startValue();
        std::cout << "\n\nisnan\n\n";
    }

    // Send target position to Webots
    wb_motor_set_position(m_tag, util::clamp(target, m_min_position, m_max_position));

    // Effective position feedback
    if (m_sensor) {
        double feedback {wb_position_sensor_get_value(m_sensor_tag)};
        
        if(isnan(feedback))
            return;
        if (!Singletons::hal()->sendAngleSensorValue(m_sensor, static_cast<float>(feedback)))
            std::cerr << "\nCERR << Sim::HALInterface::sendAngleSensorValue() failed.\n";
    }
}

Motor::~Motor() { }