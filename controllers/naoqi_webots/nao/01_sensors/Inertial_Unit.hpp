// Description: Simulate the Nao's inertial unit using Webots Accelerometer,
// Gyro, and Inertial_Unit

#ifndef INERTIAL_UNIT_HPP
#define INERTIAL_UNIT_HPP

#include "../../common_library.hpp"

// C++ library
#include <cmath>

// Webots library
#include <webots/inertial_unit.h>
#include <webots/accelerometer.h>
#include <webots/gyro.h>

// Written to this controller
// Others
#include "../03_others/Low_Pass_Filter.hpp"

namespace Sim {
    class InertialSensor;
}

class Low_Pass_Filter;

#define _USE_MATH_DEFINES

enum class DATA_IU {
    ANGLE_X, ANGLE_Y,
    ACC_X, ACC_Y, ACC_Z,
    GYR_X, GYR_Y
};

class Inertial_Unit : public Device
{
    private:
        WbDeviceTag m_inertial_unit, m_accelerometer, m_gyroscope;
        const Sim::InertialSensor *m_sensor;
        std::vector<Low_Pass_Filter*> m_filters;

    public:
        Inertial_Unit(const Sim::InertialSensor *sensor, int step);
        virtual ~Inertial_Unit();

        virtual void update();
};

#endif
