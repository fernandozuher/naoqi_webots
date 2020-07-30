#include "Bumper.hpp"

Bumper::Bumper(const BumperSensor *sensor, int step) :
    Device(sensor->name()), m_tag {wb_robot_get_device(sensor->name().c_str())},
    m_sensor {sensor}
{    
    if (!m_tag)
        cerr << "\nCERR << Webots device not found for Sim::BumperSensor: "
             << name() << "\n";
    else
        wb_touch_sensor_enable(m_tag, step);
}

void Bumper::update()
{
    if (!m_tag)
        return;
    if (!Singletons::hal()->sendBumperSensorValue(m_sensor,
        static_cast<float>(wb_touch_sensor_get_value(m_tag))))
        cerr << "\nCERR << Sim::HALInterface::sendBumperSensorValue() failed.\n";
}

Bumper::~Bumper() { }