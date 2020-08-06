// Description: Sonar sensor

#ifndef SONAR_HPP
#define SONAR_HPP

#include "../../common_library.hpp"

// Webots library
#include <webots/distance_sensor.h>

namespace Sim {
    class SonarSensor;
}

class Sonar : public Device
{
    private:
        WbDeviceTag m_tag;
        const Sim::SonarSensor *m_sensor;

    public:
        Sonar(const Sim::SonarSensor *sensor, int step);
        virtual ~Sonar();

        virtual void update();
};

#endif
