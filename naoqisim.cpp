// Description: Interface between Webots and Nao simulation SDK
#include "naoqisim.hpp"

int main(int argc, char *argv[])
{
    naoqisim obj {argc, argv};
    return 0;
}

//////////////////////////////////////////////////////////////////////////////

naoqisim::naoqisim(int argc, char **argv) :
                   argc {argc}, argv {argv}, use_cameras {true} 
{
    try {
        try {
            std::cout << "\n--------------------" << __FILE__ << "--------------------";
            std::cout << "\n(constructor) Initializing controller naoqisim:";

            std::cout << "\n\t1 - Checking command line arguments... " << std::flush;
            __check_command_line_arguments();
            std::cout << "ok!" << std::flush;

            // Initialize qi::os, naoqi C++ sdk
            std::cout << "\n\t2 - Initializing naoqi... " << std::flush;
            qi::Application(argc, argv);
            std::cout << "ok!" << std::flush;

            std::cout << "\n\t3 - Initializing webots stuff... " << std::flush;
            __init_webots_stuff();
            std::cout << "ok!" << std::flush;

            std::cout << "\n\t4 - Initializing Singletons... " << std::flush;
            __singletons();
            std::cout << "\n...............INITIALIZED Singletons!" << std::flush;

            // Main loop here
            std::cout << "\n\n(still inside constructor of naoqisim.cpp)\n";
            std::cout << "\n\t5 - Initializing NAO class... " << std::flush;
            __init_nao_class();
        }
        catch (std::string e) {
            std::cerr << e << std::flush;
            throw;
        }
        catch (boost::bad_lexical_cast e) {
            std::cerr << "ERROR: Invalid NAOQI_PORT_NUMBER specified in 'controllerArgs'\n"
                      << std::flush;
            throw;
        }
        catch (std::exception& e) {
            std::cerr << "ERROR, Standard exception: " << e.what() << std::endl << std::flush;
            throw;
        }
        catch (...) {
            std::cerr << "ERROR, Generic exception.\n" << std::flush;
            throw;
        }
    }
    catch (...) {
        __print_usage();
        exit(1);
    }
}
// Initialize use_cameras and naoqi_port attributes
void naoqisim::__check_command_line_arguments()
{
    if (argc != 2 && argc != 3)
        throw std::string {"ERROR: Number of command line arguments invalid.\n"};

    if (argc == 3 && (use_cameras = std::string{"-nocam"}.compare(std::string{argv[1]})))
        throw std::string{"ERROR: Invalid argument "} + argv[1] + "\n";

    // throw boost::bad_lexical_cast
    naoqi_port = boost::lexical_cast<int>(argv[argc - 1]);
}

void naoqisim::__init_webots_stuff()
{
    // Initialize Webots
    robot = new webots::Robot();

    // Get WorldInfo.basicTimeStep
    time_step = static_cast<int>(robot->getBasicTimeStep());

    // Wait for simulation to start or revert
    if (robot->step(time_step) == -1) {
        delete robot;
        exit(0);
    }

    // The robot model is hidden in the Robot.name field in the .proto file
    // robot_model = robot->getModel(); IT DOESN'T WORK. WHY???
    // I tried this: https://www.softwaretestinghelp.com/cpp-errors/
    // And this: https://stackoverflow.com/questions/12573816/what-is-an-undefined-reference-unresolved-external-symbol-error-and-how-do-i-fix
    // ...but with no success.
    robot_model = wb_robot_get_model();
}

void naoqisim::__singletons()
{
    // TODO: remove this case when Aldebaran release the fixed simulator-sdk
    // for Mac and Linux 64
    if (!Singletons::initialize(robot_model, naoqi_port, nullptr))
        throw std::string{"ERROR, LINE "} +
            boost::lexical_cast<std::string>(__LINE__) + ": Singletons.\n";
    sleep(1);
}

void naoqisim::__init_nao_class()
{
    nao = new Nao(use_cameras, robot, time_step);
    nao->run(); // Main loop is in this method
}

void naoqisim::__print_usage()
{
    std::cerr << "\nPlease specify the NAOQI_PORT_NUMBER in the 'controllerArgs'"
            " field of the Nao robot.\n" << std::flush;
    std::cerr << "Usage: controllerArgs \"[-nocam] NAOQI_PORT_NUMBER\"\n" << std::flush;
    std::cerr << "Note that each Nao robot should use a different port number.\n" << std::flush;
    std::cerr << "Options: -nocam, disable the simulated camera\n" << std::flush;
}

naoqisim::~naoqisim()
{
    delete nao;
    Singletons::shutdown();
    delete robot;
}