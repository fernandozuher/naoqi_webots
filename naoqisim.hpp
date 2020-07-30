// Description: Interface between Webots and Nao simulation SDK

#include "common_library.hpp"

// C++ library
#include <exception> // std::exception
#include <boost/lexical_cast.hpp> // boost::lexical_cast<int>()

// Unix library
#include <unistd.h> // Unix systems: sleep()
//#include <windows.h> // Windows systems: sleep()

// NAO sdk
#include <qi/application.hpp>

// Written to this controller
#include "nao/Nao.hpp"
#include "nao/03_others/Mutex.hpp"

using std::exception;

//////////////////////////////////////////////////////////////////////////////

class naoqisim
{
    private:
        int argc;
        char **argv;

        bool use_cameras;
        int naoqi_port;
        Nao *nao;
                
        webots::Robot *robot;
        int time_step;
        string robot_model;

        void __init_use_cameras_and_naoqi_port();
        void __init_webots_stuff();
        void __singletons();
        void __init_nao_class();
        void __print_usage();

    public:
        naoqisim(int argc, char **argv);
        ~naoqisim();

        int get_time_step() const;
        bool get_use_cameras() const;
};