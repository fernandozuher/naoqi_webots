// Description: Class for handling the special case of the hip HipYawPitch
// motors of the Nao robot. The LHipYawPitch and RHipYawPitch are in fact a
// single motor in the real Nao, but they are represented as two distinct
// Motors (motors) in the Webots models.

#ifndef HIP_MOTOR_HPP
#define HIP_MOTOR_HPP

#include "../../common_library.hpp"

// Webots library
#include <webots/motor.h>
#include <webots/position_sensor.h>

// Written to this controller
// Others
#include "../03_others/util.hpp"
using namespace util;

namespace Sim {
    class AngleActuator;
    class AngleSensor;
}

using namespace util;

class Hip_Motor : public Device
{    
    private:
        WbDeviceTag m_left_tag, m_right_tag;
        WbDeviceTag m_left_sensor_tag;
        
        const AngleActuator *m_actuator;
        const AngleSensor *m_sensor;

        double m_max_left_position;
        double m_min_left_position;
        double m_max_right_position;
        double m_min_right_position;

    public:
        Hip_Motor(int step);
        virtual ~Hip_Motor();

        virtual void update();
};

#endif
