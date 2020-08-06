#include "Nao.hpp"

Nao::Nao(bool use_cameras, webots::Robot *robot, int time_step) :
    use_cameras {use_cameras}, robot {robot}, time_step {time_step},
    model {Singletons::model()}
{
    std::cout << "\n\n\t\t--------------------" << __FILE__ << "--------------------"
              << std::flush;
    __create_nao_body();
}

void Nao::__create_nao_body()
{
    std::cout << "\n\t\t5.1 - void Nao::__create_nao_body()";

    // Create sensors
    std::cout << "\n\n\t\t\t- INITIALIZING SENSORS:\n" << std::flush;
    
    std::cout << "\n\t\t\t\t- Cameras:" << std::flush;
    __create_cameras();
    
    std::cout << "\n\n\t\t\t\t- Inertial Unit: " << std::flush;
    __create_inertial_unit();
    
    std::cout << "\n\t\t\t\t- Sonars: " << std::flush;
    __create_sonars();
    
    std::cout << "\n\t\t\t\t- Bumpers: " << std::flush;
    __create_bumpers();

    std::cout << "\n\t\t\t\t- FSRs: " << std::flush;
    __create_fsrs();

    // Create actuators
    std::cout << "\n\n\t\t\t- INITIALIZING MOTORS:\n" << std::flush;

    std::cout << "\n\t\t\t\t- Motors: " << std::flush;
    __create_motors();
    
    std::cout << "\n\t\t\t\t- Hand: " << std::flush;
    __create_hands();
}

void Nao::__create_cameras()
{
    if (use_cameras) {
        std::cout << "\n\t\t\t\t\tWebots cameras enabled."
                     "\n\t\t\t\t\tAdd the '-nocam' option in 'controllerArgs' to "
                     "disable the cameras and increase the simulator "
                     "performance." << std::flush;

        std::vector camera_sensors = model->cameraSensors();
        for (auto value : camera_sensors)
            m_devices.push_back(new Camera(value, time_step));
    }
}

void Nao::__create_inertial_unit()
{
    std::vector inertial_sensors = model->inertialSensors();
    for (auto value : inertial_sensors)
        m_devices.push_back(new Inertial_Unit(value, time_step));
}

void Nao::__create_sonars()
{
    // Only the receiving sonars (2 and 4) should appear in this list
    std::vector sonar_sensors = model->sonarSensors();
    for (auto value : sonar_sensors)
        m_devices.push_back(new Sonar(value, time_step));
}

void Nao::__create_bumpers()
{
    std::vector bumper_sensors = model->bumperSensors();
    for (auto value : bumper_sensors)
        m_devices.push_back(new Bumper(value, time_step));
}

void Nao::__create_fsrs()
{
    std::vector fsr_sensors = model->fsrSensors();
    std::vector<const Sim::FSRSensor*> left_fsr_sensors;
    std::vector<const Sim::FSRSensor*> right_fsr_sensors;

    for (auto value : fsr_sensors)
        if (!value->name().substr(0, 5).compare("LFoot"))
            left_fsr_sensors.push_back(value);
        else if (!value->name().substr(0, 5).compare("RFoot"))
            right_fsr_sensors.push_back(value);
        else
            assert(0);

    assert(left_fsr_sensors.size() == 4);
    assert(right_fsr_sensors.size() == 4);

    m_devices.push_back(new Fsr(left_fsr_sensors, time_step, "LFsr"));
    m_devices.push_back(new Fsr(right_fsr_sensors, time_step, "RFsr"));
}

void Nao::__create_motors()
{
    std::vector angle_actuators = model->angleActuators();
    for (auto value : angle_actuators)
        if (value->name() != "LHipYawPitch" && value->name() != "RHipYawPitch")
            m_devices.push_back(new Motor(value, time_step));

    // Special case for hip motor
    if (model->angleActuator("LHipYawPitch"))
        m_devices.push_back(new Hip_Motor(time_step));

/*
//////////////////////////////////////////////////////////////////////////////
    // Initialize actuators
    // Adapted from gazeboo plugin to make NAO walk, but it didn't work...
    HALInterface *hal {Singletons::hal()};
    for (auto value : angleActuators) {

        auto actuatorPosition = hal->fetchAngleActuatorValue(value);
        std::cout << "\nactuatorPosition 1: " << actuatorPosition << std::endl;
        std::cout << "\tactuatorPosition != actuatorPosition: " <<
                (actuatorPosition != actuatorPosition) << std::endl;

        if(actuatorPosition != actuatorPosition) {
            actuatorPosition = value->startValue();
            std::cout << "actuatorPosition 2: " << actuatorPosition << std::endl;
        }

        auto sensor = model->angleSensor(value->name());
        hal->sendAngleSensorValue(sensor, actuatorPosition);
    }
//////////////////////////////////////////////////////////////////////////////
*/
}

void Nao::__create_hands()
{
    // Create hands
    std::vector coupled_actuators = model->coupledActuators();
    for (auto value : coupled_actuators)
        m_devices.push_back(new Hand(value, time_step));
}

void Nao::run()
{
    std::cout << "\n\n\t\t5.2 - void Nao::run() :" << std::flush;
    std::cout << "\n\t\t\t\t |" << std::flush;
    std::cout << "\n\t\t\t\t V\n" << std::flush;

    // Main loop
    while (robot->step(time_step) != -1) {
        __check_real_time();
        for (auto i : m_devices)
            i->update();
    }

    std::cout << "\n\nvoid Nao::run() is done." << std::flush;
}

void Nao::__check_real_time()
{
    static Timer timer;
    static double previous_virtual_time {};
    static int slice {};
    static const double time_gap {10.0}; // seconds

    if (timer.delta() >= time_gap) { // every 10 real seconds
        double virtual_time {robot->getTime()};
        double speedometer {(virtual_time - previous_virtual_time) / time_gap};

        // check that the second slice is in real-time
        if (slice == 1 && (speedometer < 0.9 || speedometer > 1.1))
            std::cerr <<
                "The real-time has not been guaranteed during the first 10 " <<
                "second (speedometer = " << speedometer << "). The robot " <<
                "behavior may differ from the expected one." << std::endl;
        slice++;
        previous_virtual_time = virtual_time;
        timer.reset();
    }
}

Nao::~Nao()
{
    for (auto& i : m_devices)
        delete i;
}