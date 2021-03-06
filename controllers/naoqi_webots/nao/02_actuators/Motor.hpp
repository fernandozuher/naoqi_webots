// Description: A class for interfacing any of the (active) motor including
// the wheels (of Pepper)

#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "../../common_library.hpp"

// Webots library
#include <webots/motor.h>
#include <webots/position_sensor.h>

// Written to this controller
// Others
#include "../03_others/util.hpp"

namespace Sim {
  class AngleActuator;
  class AngleSensor;
}

class Motor : public Device
{
    private:
        WbDeviceTag m_tag, m_sensor_tag;
        const Sim::AngleActuator *m_actuator;
        const Sim::AngleSensor *m_sensor;

        double m_max_position;
        double m_min_position;

    public:
        Motor(const Sim::AngleActuator *actuator, int step);
        virtual ~Motor();

        virtual void update();
};

#endif
