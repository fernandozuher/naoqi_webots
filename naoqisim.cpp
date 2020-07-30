// Description: Interface between Webots and Nao simulation SDK
#include "naoqisim.hpp"

int main(int argc, char *argv[])
{
    naoqisim obj {argc, argv};
    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////

naoqisim::naoqisim(int argc, char **argv) :
                   argc {argc}, argv {argv}, use_cameras {true} 
{
    try {
        try {
            __init_use_cameras_and_naoqi_port();

            // Initialize qi::os
            qi::Application(argc, argv);

            __init_webots_stuff();
            __singletons();
            __init_nao_class();
        }
        catch (string e) {
            cerr << e;
            throw;
        }
        catch (boost::bad_lexical_cast e) {
            cerr << "ERROR: Invalid NAOQI_PORT_NUMBER specified in 'controllerArgs'\n";
            throw;
        }
        catch (exception& e) {
            cerr << "ERROR, Standard exception: " << e.what() << endl;
            throw;
        }
        catch (...) {
            cerr << "ERROR: Generic exception.\n";
            throw;
        }
    }
    catch (...) {
        __print_usage();
        exit(EXIT_FAILURE);
    }
}

void naoqisim::__init_use_cameras_and_naoqi_port()
{
    if (argc != 2 && argc != 3)
        throw string {"ERROR: Number of command line arguments invalid.\n"};

    if (argc == 3 && (use_cameras = string{"-nocam"}.compare(string{argv[1]})))
        throw string{"ERROR: Invalid argument "} + argv[1] + "\n";

    // throw boost::bad_lexical_cast
    naoqi_port = boost::lexical_cast<int>(argv[argc - 1]);
}

void naoqisim::__init_webots_stuff()
{
    // Initialize Webots
    robot = new webots::Robot();

    // Get WorldInfo.basicTimeStep
    time_step = static_cast<int>(robot->getBasicTimeStep());

    cout << "===== naoqisim controller started =====\n";

    // Wait for simulation to start or revert
    if (robot->step(time_step) == -1) {
        delete robot;
        exit(EXIT_SUCCESS);
    }

    // The robot model is hidden in the Robot.name field in the .proto file
    // string robotModel{robot->getModel()}; IT DOESN'T WORK. WHY???
    robot_model = wb_robot_get_model();
}

void naoqisim::__singletons()
{
    // TODO: remove this case when Aldebaran release the fixed simulator-sdk
    // for Mac and Linux 64
    if (!Singletons::initialize(robot_model, naoqi_port, NULL))
        throw string{"ERROR, LINE "} +
            boost::lexical_cast<string>(__LINE__) + ": Singletons.\n";
    sleep(1);
}

void naoqisim::__init_nao_class() // Create/run Nao
{
    nao = new Nao(use_cameras, time_step, robot);
    nao->run();
}

void naoqisim::__print_usage()
{
    cerr << "\nPlease specify the NAOQI_PORT_NUMBER in the 'controllerArgs'"
            " field of the Nao robot.\n";
    cerr << "Usage: controllerArgs \"[-nocam] NAOQI_PORT_NUMBER\"\n";
    cerr << "Note that each Nao robot should use a different port number.\n";
    cerr << "Options: -nocam, disable the simulated camera\n";
}

int naoqisim::get_time_step() const { return time_step; }

bool naoqisim::get_use_cameras() const { return use_cameras; }

naoqisim::~naoqisim()
{
    delete nao;
    Singletons::shutdown();
    delete robot;
}