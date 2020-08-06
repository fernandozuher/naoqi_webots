// Description: Foot bumper

#ifndef BUMPER_HPP
#define BUMPER_HPP

#include "../../common_library.hpp"

// Webots library
#include <webots/touch_sensor.h>

namespace Sim {
    class BumperSensor;
}

class Bumper : public Device
{
    private:
        WbDeviceTag m_tag;
        const Sim::BumperSensor *m_sensor;

    public:
        Bumper(const Sim::BumperSensor *sensor, int step);
        virtual ~Bumper();

        virtual void update();
};

#endif
