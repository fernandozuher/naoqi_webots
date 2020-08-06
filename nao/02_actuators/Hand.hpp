// Description: Class for controlling a Nao hand

#ifndef HAND_HPP
#define HAND_HPP

#include "../../common_library.hpp"

// C++ library
#include <boost/lexical_cast.hpp> // boost::lexical_cast<char*>()

// Webots library
#include <webots/motor.h>

namespace Sim {
    class CoupledActuator;
    class CoupledSensor;
}

#define PHALANX_MAX 8

class Hand : public Device
{
    private:
        WbDeviceTag m_tags[PHALANX_MAX];
        const Sim::CoupledActuator *m_actuator;
        const Sim::CoupledSensor *m_sensor;

    public:
        Hand(const Sim::CoupledActuator *actuator, int step);
        virtual ~Hand();

        virtual void update();
};

#endif
