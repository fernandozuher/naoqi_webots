#include <math.h>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <signal.h>
#include <stdexcept>
#include <qi/application.hpp>
#include <qi/path.hpp>
#include <qi/os.hpp>
#include <alnaosim/alnaosim.h>
#include <alrobotmodel/alrobotmodel.h>
#include <alsimutils/sim_launcher.h>

#ifdef _WIN32
#include <windows.h> //Sleep
#undef max
#else
# include <sys/time.h>
#endif

void makeImage(
  const Sim::CameraSensor* camera,
  unsigned char* image,
  int bufferSize)
{
  int i = 0;
  if(camera->name() == "CameraTop" || camera->name() == "CameraRight" ||
    camera->name() == "CameraRightEye")
  {
    for(; i < bufferSize / 4 ; i+= 3)
    {
      image[i  ] = 0;
      image[i + 1] = 0;
      image[i + 2] = 0;
    }
    for(; i < 2 * bufferSize / 4; i += 3)
    {
      image[i  ] = 255;
      image[i + 1] = 0;
      image[i + 2] = 0;
    }
    for(; i < 3 * bufferSize / 4 ; i += 3)
    {
      image[i  ] = 0;
      image[i + 1] = 255;
      image[i + 2] = 0;
    }
    for(; i < bufferSize ; i += 3)
    {
      image[i  ] = 0;
      image[i + 1] = 0;
      image[i + 2] = 255;
    }
  }
  else if(camera->name() == "CameraBottom" || camera->name() == "CameraLeft" ||
    camera->name() == "CameraLeftEye")
  {
    for(; i < bufferSize / 4; i+= 3)
    {
      image[i  ] = 0;
      image[i + 1] = 0;
      image[i + 2] = 0;
    }
    for(; i < 2 * bufferSize / 4; i += 3)
    {
      image[i  ] = 255;
      image[i + 1] = 255;
      image[i + 2] = 0;
    }
    for(; i < 3 * bufferSize / 4 ; i += 3)
    {
      image[i  ] = 0;
      image[i + 1] = 255;
      image[i + 2] = 255;
    }
    for(; i < bufferSize; i += 3)
    {
      image[i  ] = 255;
      image[i + 1] = 0;
      image[i + 2] = 255;
    }
  }
}

void makeDepthImage(
  const Sim::CameraDepthSensor* camera,
  float* depthImage,
  int bufferSize)
{
  unsigned int i = 0;
  for(; i < bufferSize / sizeof(float) ; ++i)
    depthImage[i] = 1.f;
}



Sim::SimLauncher* sim = new Sim::SimLauncher();
Sim::Model* model = NULL;
Sim::HALInterface* hal = NULL;

void _termination_handler (int){
  delete sim;
  delete hal;
  delete model;
  exit(0);
}


int main(int argc, char* argv[])
{
  qi::Application(argc, argv);

  std::string pathToModel;
  if(argc > 1)
  {
    pathToModel = argv[1];
  }
  else
  {
    pathToModel = qi::path::findData("alrobotmodel", "models/NAOH25V50.xml");
  }

  int NAOqiId = 9559;
  if(argc > 2)
  {
    NAOqiId = atoi(argv[2]);
  }

  std::string NAOqiPath;
  if(argc > 3)
  {
    NAOqiPath = argv[3];
  }

#ifndef WIN32
  struct sigaction new_action;
  /* Set up the structure to specify the new action. */
  new_action.sa_handler = _termination_handler;
  sigemptyset(&new_action.sa_mask);
  new_action.sa_flags = 0;

  sigaction(SIGINT, &new_action, NULL);
  sigaction(SIGTERM, &new_action, NULL);
# else
  signal( SIGINT, _termination_handler );
#endif

  try
  {
    model = new Sim::Model(pathToModel);
    hal = new Sim::HALInterface(model, NAOqiId);
    if(!sim->launch(model, NAOqiId, NAOqiPath))
    {
      std::cerr << "Error: Fail to launch hal or NAOqi" << std::endl;
      _termination_handler(0);
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    /// @todo: Add a getLine to inform user on Windows
    return -1;
  }
  std::cout << "init successfull!" << std::endl;

  int counter = 0;
  while(true)
  {
    if(counter == std::numeric_limits<int>::max())
      counter = 0;
    counter++;

//    std::cout << "set angle sensors to angle actuators ..." << std::endl;
    std::vector<const Sim::AngleActuator*> angleActuators =
      model->angleActuators();
    for(std::vector<const Sim::AngleActuator*>::const_iterator it =
      angleActuators.begin() ;
      it != angleActuators.end() ;
      ++ it)
    {
      float actuatorPosition = hal->fetchAngleActuatorValue(*it);
      /// This test will fail if actuatorPosition is a NaN.
      if(actuatorPosition != actuatorPosition)
      {
        actuatorPosition = (*it)->startValue();
      }
      const Sim::AngleSensor* angleSensor = model->angleSensor((*it)->name());
      hal->sendAngleSensorValue(angleSensor, actuatorPosition);
//      std::cout << "setSensorValue : " << angleSensor->name() << " to " <<
//        actuatorPosition << std::endl;
    }
    std::vector<const Sim::CoupledActuator*> coupledActuators =
      model->coupledActuators();
    for(std::vector<const Sim::CoupledActuator*>::const_iterator it =
      coupledActuators.begin() ;
      it != coupledActuators.end() ;
      ++ it)
    {
      float actuatorPosition = hal->fetchCoupledActuatorValue(*it);
      const Sim::CoupledSensor* coupledSensor = model->coupledSensor((*it)->name());
      /// This test will fail if actuatorPosition is a NaN.
      if(actuatorPosition != actuatorPosition)
      {
        actuatorPosition = (*it)->startValue();
      }
      hal->sendCoupledSensorValue(coupledSensor, actuatorPosition);
//      std::cout << "setSensorValue : " << coupledSensor->name() << " to " <<
//        actuatorPosition << std::endl;
    }
    std::vector<const Sim::TorqueActuator*> torqueActuators =
      model->torqueActuators();
    for(std::vector<const Sim::TorqueActuator*>::const_iterator it =
      torqueActuators.begin() ;
      it != torqueActuators.end() ;
      ++ it)
    {
      float actuatorTorque = hal->fetchTorqueActuatorValue(*it);
      const Sim::TorqueSensor* torqueSensor = model->torqueSensor((*it)->name());
      /// This test will fail if actuatorPosition is a NaN.
      if(actuatorTorque != actuatorTorque)
      {
        actuatorTorque = (*it)->startValue();
      }
      hal->sendTorqueSensorValue(torqueSensor, actuatorTorque);
//      std::cout << "setSensorValue : " << torqueSensor->name() << " to " <<
//        actuatorTorque << std::endl;
    }
    std::vector<const Sim::AngleSpeedActuator*> angleSpeedActuators =
      model->angleSpeedActuators();
    for(std::vector<const Sim::AngleSpeedActuator*>::const_iterator it =
      angleSpeedActuators.begin() ;
      it != angleSpeedActuators.end() ;
      ++ it)
    {
      float actuatorAngleSpeed = hal->fetchAngleSpeedActuatorValue(*it);
      const Sim::AngleSpeedSensor* angleSpeedSensor = model->angleSpeedSensor((*it)->name());
      /// This test will fail if actuatorPosition is a NaN.
      if(actuatorAngleSpeed != actuatorAngleSpeed)
      {
        actuatorAngleSpeed = (*it)->startValue();
      }
      else
      {
//        std::cout << "Set a real value: " << actuatorAngleSpeed << std::endl;
      }
      hal->sendAngleSpeedSensorValue(angleSpeedSensor, actuatorAngleSpeed);
//      std::cout << "setSensorValue : " << angleSpeedSensor->name() << " to " <<
//        actuatorAngleSpeed << std::endl;
    }

    std::vector<const Sim::CameraSensor*> cameraSensors =
      model->cameraSensors();
    for(std::vector<const Sim::CameraSensor*>::const_iterator it =
      cameraSensors.begin() ;
      it != cameraSensors.end() ;
      ++it)
    {
      if((*it)->name() == "CameraRightEye" || (*it)->name() == "CameraLeftEye")
        continue;
      int width = 0;
      int height = 0;
      int bufferSize = 0;
      hal->cameraBufferSize(*it, &bufferSize, &width, &height);
      unsigned char* image = (unsigned char*) malloc(bufferSize);
      makeImage((*it), image, bufferSize);
      if(image)
        hal->sendCameraSensorValue((*it), image);
      free(image);
    }
    std::vector<const Sim::CameraDepthSensor*> cameraDepthSensors =
      model->cameraDepthSensors();
    for(std::vector<const Sim::CameraDepthSensor*>::const_iterator it =
      cameraDepthSensors.begin() ;
      it != cameraDepthSensors.end() ;
      ++it)
    {
      int width = 0;
      int height = 0;
      int bufferSize = 0;
      hal->cameraDepthBufferSize(*it, &bufferSize, &width, &height);
      float* depthImage = (float*) malloc(sizeof(float) * width * height);
      makeDepthImage((*it), depthImage, sizeof(float) * width * height);
      hal->sendCameraDepthSensorValue((*it), (const float*) depthImage);
      free(depthImage);
    }
    std::vector<const Sim::FSRSensor*> fsrSensors =
      model->fsrSensors();
    for(std::vector<const Sim::FSRSensor*>::const_iterator it =
      fsrSensors.begin() ;
      it != fsrSensors.end() ;
      ++it)
    {
      float value = 0.f;
      if(counter % 20 > 10)
        value = 0.f;
      else
        value = 10.f;
      hal->sendFSRSensorValue((*it), value);
//      std::cout << "Set FSR: " << (*it)->name() << " value: " << value <<
//        std::endl;
    }
    std::vector<const Sim::InertialSensor*> inertialSensors =
      model->inertialSensors();
    for(std::vector<const Sim::InertialSensor*>::const_iterator it =
      inertialSensors.begin() ;
      it != inertialSensors.end() ;
      ++it)
    {
      std::vector<float> inertialValues;
      float angleX = 0.f;
      float angleY = 0.1;
      float accX = 0.2;
      float accY = 0.3;
      float accZ = 0.4;
      float gyrX = 0.5;
      float gyrY = 0.6;
      inertialValues.push_back(angleX);
      inertialValues.push_back(angleY);
      inertialValues.push_back(accX);
      inertialValues.push_back(accY);
      inertialValues.push_back(accZ);
      inertialValues.push_back(gyrX);
      inertialValues.push_back(gyrY);
      hal->sendInertialSensorValues((*it), inertialValues);
//      std::cout << "Set Inertial: " << (*it)->name() << " values: " <<
//                   angleX << " " << angleY << " " << accX << " " <<
//                   accY << " " << accZ << " " << gyrX << " " << gyrY <<
//                   std::endl;
    }
    std::vector<const Sim::SonarSensor*> sonarSensors =
      model->sonarSensors();
    for(std::vector<const Sim::SonarSensor*>::const_iterator it =
      sonarSensors.begin() ;
      it != sonarSensors.end() ;
      ++it)
    {
      float value = 0.5;
      hal->sendSonarSensorValues((*it), std::vector<float>(10, value));
//      std::cout << "Set Sonar: " << (*it)->name() << " values: " << value <<
//                   std::endl;
    }
    std::vector<const Sim::BumperSensor*> bumperSensors =
      model->bumperSensors();
    for(std::vector<const Sim::BumperSensor*>::const_iterator it =
      bumperSensors.begin() ;
      it != bumperSensors.end() ;
      ++it)
    {
      float value = 0.f;
      if(counter % 20 > 10)
        value = 0.f;
      else
        value = 1.f;
      hal->sendBumperSensorValue((*it), value);
//      std::cout << "Set Bumpers: " << (*it)->name() << " value: " << value <<
//        std::endl;
    }
    std::vector<const Sim::SingleDepthSensor*> singleDepthSensors =
      model->singleDepthSensors();
    for(std::vector<const Sim::SingleDepthSensor*>::const_iterator it =
      singleDepthSensors.begin() ;
      it != singleDepthSensors.end() ;
      ++it)
    {
      float value = 0.f;
      if(counter % 20 > 10)
        value = 0.f;
      else
        value = 1.f;
      hal->sendSingleDepthSensorValue((*it), value);
//      std::cout << "Set SingleDepthSensor: " << (*it)->name() <<
//        " value: " << value << std::endl;
    }
    std::vector<const Sim::ArrayDepthSensor*> arrayDepthSensors =
      model->arrayDepthSensors();
    for(std::vector<const Sim::ArrayDepthSensor*>::const_iterator it =
      arrayDepthSensors.begin() ;
      it != arrayDepthSensors.end() ;
      ++it)
    {
      std::vector<float> values(((*it)->dcmKeys().size()), 0.f);
      for(unsigned int i = 0 ; i < values.size() ; i++)
        values[i] = (float) i / 10.f;
      hal->sendArrayDepthSensorValues((*it), values);
//      std::cout << "Set ArrayDepthSensor: " << (*it)->name() <<
//        " value: " << value << std::endl;
    }

  qi::os::sleep(1);

  }
#ifdef _WIN32
  _termination_handler(0);
#endif

  return 0;
}
