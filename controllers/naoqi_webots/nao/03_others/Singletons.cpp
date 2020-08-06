#include "Singletons.hpp"

#define SEP "/"

Sim::Model *Singletons::m_model {nullptr};
Sim::HALInterface *Singletons::m_hal {nullptr};
Sim::SimLauncher* Singletons::m_launcher {nullptr};

bool Singletons::initialize(const std::string &model, int naoqi_port,
                            void (*hal_initialized_callback)())
{
    std::cout << "\n\n\t\t--------------------" << __FILE__ << "--------------------"
              << std::flush;
    std::cout << "\n\t\t4.1 - Singletons::initialize(robot_model, naoqi_port, nullptr) :"
              << std::flush;

    // Model file name to upper
    std::string robot_file_name {model};
    boost::algorithm::to_upper(robot_file_name);

    // Remove "_" in the file name
    boost::erase_all(robot_file_name, "_");

    // What is this???
    const std::string cdUp("..");

    // Get SDK prefix
    std::string sdk_prefix {wbu_system_getenv("WEBOTS_NAOSIM_PATH")};
    std::cout << "\n\t\t\t- sdk_prefix: " << sdk_prefix << std::flush;

    // SDK to model
    const std::string sdk_to_model {std::string{"share"} + SEP + std::string{"alrobotmodel"}
            + SEP + std::string{"models"} + SEP + robot_file_name + ".xml"};

    // Webots installed sdk
    const std::string path_to_naoqi_sdk {sdk_prefix + SEP};

    // Test if we use Aldebaran installed SDK
    std::string path_to_model {path_to_naoqi_sdk + sdk_to_model};

    // Instantiate model
    try {
        std::cout << "\n\t\t\t- Instantiating model...\n" << std::flush;
        m_model = new Sim::Model(wbu_system_short_path(path_to_model.c_str()));
        std::cout << "\t\t\tok!" << std::flush;
    }
    catch (const std::exception&) {
        std::cerr << "\n\t\t\tCER << Could not instantiate model with path: \""
             << path_to_model << "\"" << std::endl << std::flush;
    }

    try {
        std::cout << "\n\t\t\t- Instantiating HALInterface... " << std::flush;
        m_hal = new Sim::HALInterface(m_model, naoqi_port);
        std::cout << "ok!" << std::flush;
    }
    catch (const std::exception &e) {
        std::cerr << "\n\nException raised: " << e.what() << "\n"
             << "while calling HALInterface::HALInterface(" << m_model
             << ", " << naoqi_port << ")\n" << std::flush;
        return false;
    }

    m_launcher = new Sim::SimLauncher();
    // TODO: remove this case when Aldebaran release the fixed simulator-sdk
    // for Mac and Linux 64
    std::cout << "\n\t\t\t- m_launcher->launch(...)..." << std::flush;
    std::cout << "\n\t\t\t\t |" << std::flush;
    std::cout << "\n\t\t\t\t V\n" << std::flush;
    return m_launcher->launch(m_model, naoqi_port, sdk_prefix);
}

void Singletons::shutdown()
{
    std::cout << "\n=====(Singletons::shutdown()) Shutting down! =====\n"
              << std::flush;
    delete m_launcher;
    delete m_hal;
    delete m_model;
}

// Robot model
Sim::Model* Singletons::model()
{
    return m_model;
}

// Hardware abstraction layer
Sim::HALInterface* Singletons::hal()
{
    return m_hal;
}