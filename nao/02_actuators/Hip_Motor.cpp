#include "Hip_Motor.hpp"

Hip_Motor::Hip_Motor(int step) : Device("HipYawPitch")
{
    m_actuator = Singletons::model()->angleActuator("LHipYawPitch");
    m_left_tag = wb_robot_get_device("LHipYawPitch");
    m_right_tag = wb_robot_get_device("RHipYawPitch");
    m_left_sensor_tag = wb_robot_get_device("LHipYawPitchS");

    if (m_left_tag) {
        m_max_left_position = wb_motor_get_max_position(m_left_tag);
        m_min_left_position = wb_motor_get_min_position(m_left_tag);
    }
    else {
        m_max_left_position = 0.0;
        m_min_left_position = 0.0;
    }

    if (m_left_sensor_tag)
        wb_position_sensor_enable(m_left_sensor_tag, step);

    if (m_right_tag) {
        m_max_right_position = wb_motor_get_max_position(m_right_tag);
        m_min_right_position = wb_motor_get_min_position(m_right_tag);
    } else {
        m_max_right_position = 0.0;
        m_min_right_position = 0.0;
    }

    m_sensor = Singletons::model()->angleSensor("LHipYawPitch");
    if (m_sensor)
        Singletons::hal()->sendAngleSensorValue(m_sensor, 0.0);
    else
        cerr << "\nCERR << Sim::AngleSensor not found for motor: LHipYawPitch\n";
}

void Hip_Motor::update()
{
    // Effective position feedback
    if (m_sensor) {
        double feedback {wb_position_sensor_get_value(m_left_sensor_tag)};
        if (!Singletons::hal()->sendAngleSensorValue(m_sensor,  
            static_cast<float>(feedback)))
                cerr << "\nCERR << Sim::HALInterface::sendAngleSensorValue() "
                        "failed.\n";
    }

    // Set target position
    double target {Singletons::hal()->fetchAngleActuatorValue(m_actuator)};
    if (isnan(target)) {
        target = m_actuator->startValue();
        cout << "\n\nNAN";
        cout << "\n\ttarget: \n\n" << target;
    }

    if (m_left_tag)
        wb_motor_set_position(m_left_tag, clamp(target, m_min_left_position, \
            m_max_left_position));

    if (m_right_tag)
        wb_motor_set_position(m_right_tag, clamp(target, m_min_right_position, \
            m_max_right_position));
}

Hip_Motor::~Hip_Motor() { }
