// Description: Interface between Webots and Nao simulation SDK

#ifndef NAOQI_WEBOTS_HPP
#define NAOQI_WEBOTS_HPP

#include "common_library.hpp"

// C++ library
#include <exception> // std::exception
#include <boost/lexical_cast.hpp> // boost::lexical_cast<int>()

// Unix library
#include <unistd.h> // Unix systems: sleep()
//#include <windows.h> // Windows systems: sleep()

// naoqi C++ sdk
#include <qi/application.hpp>

// Written to this controller
#include "nao/Nao.hpp"
#include "nao/03_others/Mutex.hpp"

//////////////////////////////////////////////////////////////////////////////

class naoqi_webots
{
    private:
        int argc;
        char **argv;

        // naoqi stuff
        int naoqi_port;

        // Webots stuff
        bool use_cameras;
        webots::Robot *robot;
        int time_step;
        std::string robot_model;

        // Controller stuff
        Nao *nao;

        // Initialize use_cameras and naoqi_port attributes
        void __check_command_line_arguments();

        void __init_webots_stuff();
        void __singletons();
        void __init_nao_class();
        void __print_usage();

    public:
        naoqi_webots(int argc, char **argv);
        ~naoqi_webots();
};

#endif