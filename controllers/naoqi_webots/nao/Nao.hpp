// Description: Class that represents a single Nao robot and its devices

#ifndef NAO_HPP
#define NAO_HPP

#include "../common_library.hpp"

// C++ library////////////////////////////////////////////////////////////////
#include <list>
#include <cmath>
#include <cassert>

// Written to this controller/////////////////////////////////////////////////
// Sensors
#include "01_sensors/Camera.hpp"
#include "01_sensors/Sonar.hpp"
#include "01_sensors/Bumper.hpp"
#include "01_sensors/Fsr.hpp"
#include "01_sensors/Inertial_Unit.hpp"
// Actuators
#include "02_actuators/Motor.hpp"
#include "02_actuators/Hip_Motor.hpp"
#include "02_actuators/Hand.hpp"
// Others
#include "03_others/Timer.hpp"
//////////////////////////////////////////////////////////////////////////////

class Device;

class Nao
{
    private:
        // Webots stuff
        bool use_cameras;
        webots::Robot *robot;
        int time_step;

        Sim::Model *model;
        std::vector<Device*> m_devices;

        void __create_nao_body();
            void __create_cameras();
            void __create_inertial_unit();
            void __create_sonars();            
            void __create_bumpers();
            void __create_fsrs();
            
            void __create_motors();
            void __create_hands();

        void __check_real_time();

    public:
        Nao(bool use_cameras, webots::Robot *robot, int time_step);
        virtual ~Nao();

        // run synchronization between simulated robot and HAL
        // this function returns when Webots simulation is terminated by the user
        void run();
};

#endif
