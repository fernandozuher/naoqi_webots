// Description: Simulated Force Sensitive Resistor (FSR) of the Nao robot

#ifndef FSR_HPP
#define FSR_HPP

#include "../../common_library.hpp"

// C++ library
#include <cassert>

// Webots library
#include <webots/touch_sensor.h>

// Written to this controller
// Others
#include "../03_others/Low_Pass_Filter.hpp"
#include "../03_others/util.hpp"

namespace Sim {
    class FSRSensor;
}

using namespace util;

static const double TO_KILOGRAMS = 1.0 / 9.81;

class Low_Pass_Filter;

class Fsr : public Device
{    
    private:
        WbDeviceTag m_tag;
        std::vector<Low_Pass_Filter*> m_filter;
        std::vector<const FSRSensor*> m_fsr_sensors;
        
        void __infer_values();

    public:
        Fsr(std::vector<const FSRSensor*> sensors, int step, string name);
        virtual ~Fsr();

        virtual void update();
};

#endif
