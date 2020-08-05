#include "Nao.hpp"

Nao::Nao(bool use_cameras, int time_step, webots::Robot *robot) :
    use_cameras {use_cameras}, time_step {time_step}, robot {robot},
    model {Singletons::model()}
{
    __create_nao_body();
}

void Nao::__create_nao_body()
{
    __create_cameras();
    __create_inertial_unit();
    __create_sonars();            
    __create_bumpers();
    __create_fsrs();
    
    __create_motors();
    __create_hands();
}

void Nao::__create_cameras()
{
    // Create cameras
    if (use_cameras) {
        cout << "Webots cameras enabled.\n"
                "Add the '-nocam' option in 'controllerArgs' to disable the "
                "cameras and increase the simulator performance.\n";

        std::vector camera_sensors = model->cameraSensors();
        for (auto value : camera_sensors)
            m_devices.push_back(new Camera(value, time_step));
    }
}

void Nao::__create_inertial_unit()
{
    // Inertial Unit
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
    // Bumpers
    std::vector bumper_sensors = model->bumperSensors();
    for (auto value : bumper_sensors)
        m_devices.push_back(new Bumper(value, time_step));
}

void Nao::__create_fsrs()
{
    // FSRs
    std::vector fsr_sensors = model->fsrSensors();
    std::vector<const FSRSensor*> left_fsr_sensors;
    std::vector<const FSRSensor*> right_fsr_sensors;

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
    // Create motors
    std::vector angle_actuators = model->angleActuators();
    for (auto value : angle_actuators)
        if (value->name() != "LHipYawPitch" && value->name() != "RHipYawPitch")
            m_devices.push_back(new Motor(value, time_step));

    // special case for hip motor
    if (model->angleActuator("LHipYawPitch"))
        m_devices.push_back(new Hip_Motor(time_step));

/*
//////////////////////////////////////////////////////////////////////////////
    // Initialize actuators
    // Adapted from gazeboo plugin t omake NAO walk...
    HALInterface *hal {Singletons::hal()};
    for (auto value : angleActuators) {

        auto actuatorPosition = hal->fetchAngleActuatorValue(value);
        cout << "\nactuatorPosition 1: " << actuatorPosition << endl;
        cout << "\tactuatorPosition != actuatorPosition: " <<
                (actuatorPosition != actuatorPosition) << endl;

        if(actuatorPosition != actuatorPosition) {
            actuatorPosition = value->startValue();
            cout << "actuatorPosition 2: " << actuatorPosition << endl;
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
    while (robot->step(time_step) != -1) { // Main loop
        __check_real_time();
        for (auto i : m_devices)
            i->update();
    }
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
            cerr <<
                "The real-time has not been guaranteed during the first 10 " <<
                "second (speedometer = " << speedometer << "). The robot " <<
                "behavior may differ from the expected one." << endl;
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