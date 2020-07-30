#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

// Description: static environment for alsim
//              the Model contains a description of the robot model
//              the HALInterface is used to communicate with the sensors and
//                                                                  actuators

// C++ library
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
// boost::algorithm::to_upper(std::string), boost::erase_all(std::string, "c");
#include <boost/algorithm/string.hpp>

// Webots library
#include <webots/utils/system.h>

// naoqi sdk library
#include <alnaosim/alnaosim.h>
#include <alrobotmodel/alrobotmodel.h>
#include <alsimutils/sim_launcher.h>
#include <qi/os.hpp>
#include <qi/path.hpp>
#include <qi/qi.hpp>

namespace Sim {
    class SimLauncher;
}
using namespace Sim;

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::exception;

class Process;

class Singletons
{
    private:
        static Model *m_model;
        static HALInterface *m_hal;
        static SimLauncher *m_launcher;

    public:
        // Initialize and shutdown simulation environment
        static bool initialize(const string &model, int naoqi_port,
                                void (*halInitializedCallback)());
        static void shutdown();

        // Robot model
        static Model *model();

        // Hardware abstraction layer
        static HALInterface *hal();

        // dump model info on cout
        static void dump_model();
};

#endif
