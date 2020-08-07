/**
* Copyright (c) 2012 Aldebaran Robotics  All Rights Reserved
*/

#ifndef SIM_LAUNCHER_H
#define SIM_LAUNCHER_H

#include "alsimutils.h"
#include <string>
#include <vector>

namespace Sim
{

  class Model;
  class SimLauncherImpl;

/// \class SimLauncher sim_launcher.h
/// \brief SimLauncher allows launching the hal and naoqi binaries.
/// \remarks This lib uses NAOqi logging system (qi::log). The log system
/// needs to be initialized in the main of your application, see libqi
/// documentation. NAOqi launches this logging system, so you will see log
/// messages if you launch a NAOqi while using this library.

void ALSIMUTILS_API defaultInitFunc();

class ALSIMUTILS_API SimLauncher
{
public:
  typedef void (*InitSimulatorFunc)();
public:
  /// \brief Constructor
  SimLauncher();
  /// \brief Destructor
  ~SimLauncher();
  /// \brief launches a hal and a naoqi on the given model and port, with
  /// the given sdk.
  /// \param model the Sim::Model defines the robot model launched. See
  /// alrobotmodel.h for more information
  /// \param NAOqiId the NAOqiId allows to identify the hal and the NAOqi
  /// run launched by this call
  /// \param naoqiModuleWhiteList the naoqiModuleWhiteList, if not empty,
  /// allows to select the modules to be launched with naoqi
  /// \param initSimulatorFunc the initSimulatorFunc is a pointer to the
  /// function to be run once the hal has been launched.
  /// \remarks it is important that this function initializes all the sensors
  /// of the simulation, i.e. calls all the sendSensor values of alnaosim.h
  /// Otherwise the behavior of NAOqi will be undefined
  bool launch(
    const Model* model,
    int NAOqiId = 9559,
    const std::string& naoqiPath = "",
    const std::vector<std::string> & naoqiModuleWhiteList =
      std::vector<std::string>(),
    InitSimulatorFunc initSimulatorFunc = defaultInitFunc);
  /// \brief stops the hal and the naoqi which have the given id.
  bool stop(int id = 9559);

private:
  SimLauncherImpl* a_impl;
};

}

#endif // SIM_LAUNCHER_H
