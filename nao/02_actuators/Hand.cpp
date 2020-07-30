#include "Hand.hpp"

Hand::Hand(const CoupledActuator *actuator, int step) :
           Device(actuator->name())
{
    m_actuator = actuator;

    string device_format;
    if (name() == "LHand")
        device_format = "LPhalanx";
    else if (name() == "RHand")
        device_format = "RPhalanx";
    else
        cerr << "CERR << Cannot create Hand for unknown Sim::CoupledSensor: "
             << name() << "\n";

    // Get phalanx motors: the real Nao has 1 motor for each hand
    // but in Webots we have 8 phalanx motors for each hand
    for (int i {0}; i < PHALANX_MAX; i++)
        m_tags[i] = wb_robot_get_device((device_format + std::to_string(i+1)).c_str());

    m_sensor = Singletons::model()->coupledSensor(name());
    if (!m_sensor)
        cerr << "\nCERR << Sim::CoupledSensor not found for CoupledActuator: "
             << name() << "\n";
}

void Hand::update()
{
    // Set target position
    double target {Singletons::hal()->fetchCoupledActuatorValue(m_actuator)};
    if (isnan(target))
        target = m_actuator->startValue();

    // We must activate the 8 phalanx motors
    for (int i {0}; i < PHALANX_MAX; i++)
        if (m_tags[i])
            wb_motor_set_position(m_tags[i], target);

    // Effective position feedback
    if (m_sensor &&
        !Singletons::hal()->sendCoupledSensorValue( \
        m_sensor, static_cast<float>(target)))
            cerr << "\nCERR << Sim::HALInterface::sendCoupledSensorValue() "
                    "failed.\n";
}

Hand::~Hand() { }