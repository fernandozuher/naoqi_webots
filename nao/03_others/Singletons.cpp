#include "Singletons.hpp"

#define SEP "/"

Model *Singletons::m_model = nullptr;
HALInterface *Singletons::m_hal = nullptr;
SimLauncher* Singletons::m_launcher = nullptr;

bool Singletons::initialize(const string &model, int naoqi_port,
                            void (*halInitializedCallback)())
{
    // Model file name to upper
    string robot_file_name {model};
    boost::algorithm::to_upper(robot_file_name);

    // Remove "_" in the file name
    boost::erase_all(robot_file_name, "_");

    cout << "===== starting alsim controller =====\n" << std::flush;

    // What is this???
    const string cdUp("..");

    // Get SDK prefix
    string sdk_prefix {wbu_system_getenv("WEBOTS_NAOSIM_PATH")};
    cout << "sdk_prefix: " << sdk_prefix << endl;

    // SDK to model
    const string sdk_to_model {string{"share"} + SEP + string{"alrobotmodel"}
            + SEP + string{"models"} + SEP + robot_file_name + ".xml"};

    // Webots installed sdk
    const string path_to_naoqi_sdk {sdk_prefix + SEP};

    // Test if we use Aldebaran installed SDK
    string path_to_model {path_to_naoqi_sdk + sdk_to_model};

    // Instantiate model
    try {
        m_model = new Model(wbu_system_short_path(path_to_model.c_str()));
    }
    catch (const exception&) {
        cerr << "CER << Could not instantiate model with path: \""
             << path_to_model << "\"" << endl;
    }

    try {
        m_hal = new HALInterface(m_model, naoqi_port);
    }
    catch (const exception &e) {
        cerr << "Exception raised: " << e.what() << "\n"
             << "while calling HALInterface::HALInterface(" << m_model
             << ", " << naoqi_port << ")\n";
        return false;
    }

    m_launcher = new SimLauncher();
    // TODO: remove this case when Aldebaran release the fixed simulator-sdk
    // for Mac and Linux 64
    return m_launcher->launch(m_model, naoqi_port, sdk_prefix);
}

void Singletons::shutdown()
{
    cout << "===== shutting down! =====\n" << std::flush;
    delete m_launcher;
    delete m_hal;
    delete m_model;
}

// Robot model
Model* Singletons::model()
{
    return m_model;
}

// Hardware abstraction layer
HALInterface* Singletons::hal()
{
    return m_hal;
}