/**
* Copyright (c) 2011 Aldebaran Robotics  All Rights Reserved
* This is an API proposal for the alnaosim lib.
*/

#ifndef ALNAOSIM_H
#define ALNAOSIM_H
#include <qi/macro.hpp>

#ifdef alnaosim_EXPORTS
# define ALNAOSIM_API QI_EXPORT_API
#elif defined(alnaosim_IMPORTS)
# define ALNAOSIM_API QI_IMPORT_API
#else
# define ALNAOSIM_API
#endif

#include <string>
#include <vector>
#include "alnaosim_camera_definitions.h"

namespace Sim
{

  class AngleActuator;
  class AngleSensor;
  class AngleSpeedActuator;
  class AngleSpeedSensor;
  class ArrayDepthSensor;
  class BaseCamera;
  class BumperSensor;
  class TactileSensor;
  class CameraDepthSensor;
  class CameraSensor;
  class CameraDepthSensor;
  class CoupledActuator;
  class CoupledSensor;
  class FSRSensor;
  class InertialSensor;
  class SonarSensor;
  class Model;
  class TorqueActuator;
  class TorqueSensor;
  class WheelTorqueActuator;
  class WheelVelocityActuator;
  class WheelVelocitySensor;
  class LEDActuator;
  class SingleDepthSensor;

  typedef SingleDepthSensor DepthInfraredSensor;

/// \class HALInterface alnaosim.h
/// \brief HALInterface is responsible for reading and writing values into the
/// Hardware Abstraction Layer (HAL) of the robot.
/// \remarks Values from the HAL are read by NAOqi, so changing these values
/// allows you to simulate stimuli from the environment to NAOqi.
/// \remarks This lib uses NAOqi logging system (qi::log). The log system needs
/// to be initialized in the main of your application, see libqi documentation.
/// NAOqi launches this logging system, so you will see log messages if
/// you launch a NAOqi while using this lib.
class ALNAOSIM_API HALInterface
{
  public:
    /// \brief creates a HALInterface given a valid model.
    HALInterface(const Model* model, int NAOqiId = 9559);
    /// \brief destructor.
    ~HALInterface();

    /// \brief returns the last command value (in radians) of the given
    /// angleActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchAngleActuatorValue(const AngleActuator* angleActuator);
    /// \brief returns the last command value (between 0 and 1, no unit) of the
    /// given coupledActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchCoupledActuatorValue(const CoupledActuator* coupledActuator);
    /// \brief returns the last command value (in Newton per meter) of the given
    /// torqueActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchTorqueActuatorValue(const TorqueActuator* torqueActuator);
    /// \brief returns the last command value (in radians per second) of the
    /// given angleSpeedActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchAngleSpeedActuatorValue(
      const AngleSpeedActuator* angleSpeedActuator);
    /// \brief returns the last command value (in Newton per meter) of the
    /// given wheelTorqueActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchWheelTorqueActuatorValue(
      const WheelTorqueActuator* wheelTorqueActuator);
    /// \brief returns the last command value (in radians per second) of the
    /// given wheelVelocityActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchWheelVelocityActuatorValue(
      const WheelVelocityActuator* wheelVelocityActuator);
    /// \brief returns the last command value (between 0 and 1) of the
    /// given ledActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return Nan.
    float fetchLEDActuatorValue(const LEDActuator* ledActuator);

    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given angleActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchAngleActuatorStiffness(const AngleActuator* angleActuator);
    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given coupledActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchCoupledActuatorStiffness(const CoupledActuator* coupledActuator);
    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given torqueActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchTorqueActuatorStiffness(const TorqueActuator* torqueActuator);
    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given angleSpeedActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchAngleSpeedActuatorStiffness(
      const AngleSpeedActuator* angleSpeedActuator);
    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given wheelTorqueActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchWheelTorqueActuatorStiffness(
      const WheelTorqueActuator* wheelTorqueActuator);
    /// \brief returns the last stiffness value (between 0 and 1, no unit) of
    /// the given wheelVelocityActuator.
    /// \remarks As long as the hal executable has not been launch, this will
    /// return NaN. This allows you to know when the simulation has started and
    /// gives meaningful position at start-up.
    float fetchWheelVelocityActuatorStiffness(
      const WheelVelocityActuator* wheelVelocityActuator);

    /// \brief sends value (in radians) to the given angleSensor.
    bool sendAngleSensorValue(
      const AngleSensor* angleSensor, float value);
    /// \brief sends value (between 0 and 1, no unit) to the given
    /// coupledSensor.
    bool sendCoupledSensorValue(
      const CoupledSensor* coupledSensor, float value);
    /// \brief sends value in Newton per meter to the given torqueSensor.
    bool sendTorqueSensorValue(
      const TorqueSensor* torqueSensor, float value);
    /// \brief sends value in radians per second to the given angleSpeedSensor.
    bool sendAngleSpeedSensorValue(
      const AngleSpeedSensor* angleSpeedSensor, float value);
    /// \brief sends value in radians per second to the given
    /// wheelVelocitySensor.
    bool sendWheelVelocitySensorValue(
      const WheelVelocitySensor* wheelVelocitySensor, float value);

    /// \brief sends the content of the buffer img to the given cameraSensor
    /// \remarks The image contained in img can be of different sizes: 160 *
    /// 120, 320 * 240 or 640 * 480 and is defined in RGB.
    /// \deprecated since 1.18, use sendCameraSensorValue with
    /// CameraResolution and CameraColorSpace instead.
    bool sendCameraSensorValue(
      const CameraSensor* cameraSensor, const unsigned char* img);
    /// \brief sends the content of the buffer img to the given cameraSensor
    /// \arg camResolution is the resolution of the buffer sent
    /// \arg camColorSpace is the color space of the buffer sent
    bool sendCameraSensorValue(
      const CameraSensor* cameraSensor,
      const unsigned char* img,
      CameraResolution camResolution,
      CameraColorSpace camColorSpace);

    /// \brief sends the content of the buffer depth to the given
    /// cameraDepthSensor.
    /// \remarks The depth map contained in buffer has a size given by
    /// cameraDepthSensorBufferSize. Each value defines in float the depth of
    /// pixel in meters.
    /// \deprecated since 1.18, use sendDepthCameraSensorValue with
    /// CameraResolution and CameraColorSpace instead.
    bool sendCameraDepthSensorValue(
      const CameraDepthSensor* cameraDepthSensor,
      const float* buffer);
    /// \brief sends the content of the buffer depth to the given
    /// cameraDepthSensor.
    /// \arg camResolution is the resolution of the buffer sent
    /// \arg camColorSpace is the color space of the buffer sent
    bool sendCameraDepthSensorValue(
      const CameraDepthSensor* cameraDepthSensor,
      const float* buffer,
      CameraResolution camResolution,
      CameraColorSpace camColorSpace);

    /// \brief sends value (in kilograms) to the given fsrSensor.
    bool sendFSRSensorValue(
      const FSRSensor* fsrSensor, float value);
    /// \brief sends value (between 0 and 1, no unit) to the given bumperSensor.
    bool sendBumperSensorValue(
      const BumperSensor* bumperSensor, float value);
    /// \brief sends value (between 0 and 1, no unit) to the given
    /// tactileSensor.
    bool sendTactileSensorValue(
      const TactileSensor* tactileSensor, float value);
    /// \brief sends value (in meters) to the given
    /// DepthInfraredSensor.
    /// \deprecated use sendSingleDepthSensor instead.
    bool sendDepthInfraredSensorValue(
      const DepthInfraredSensor* depthInfraredSensor, float value);
    /// \brief sends value (in meters) to the given
    /// SingleDepthSensor.
    bool sendSingleDepthSensorValue(
      const SingleDepthSensor* singleDepthSensor, float value);

    /// \brief sends values (see remarks) to the given inertialSensor.
    /// \remarks The values that you have to provide to this method are in the
    /// following order:  orientation around x-axis and y-axis (in radians),
    /// accelerations along x-axis x, y-axis and z-axis (in meter per second
    /// squared),  and rotational speed around x-axis and y-axis (in radian per
    /// second). For more details about the position and orientation of the
    /// axis, see the sensors Section of the Hardware documentation.
    bool sendInertialSensorValues(
      const InertialSensor* inertialSensor, const std::vector<float>& values);
    /// \brief sends values in meters to the given sonarSensor (see remarks).
    /// \remarks 10 values can be associated to a SonarSensor if it has a
    /// buffer size of 10 floats. These are the echoes received by the sonar,
    /// from the pulse signal sent by the emitter, which consists in a cone of
    /// nearly 80°. Currently only the first echo is taken into account by
    /// NAOqi, so you can fill in only the first value.
    /// You should not use this method on a sonar that has a buffer size of 1
    /// float, but if you do, only the first value will be taken into account.
    /// In 1.12, concerning NAO the emitting sonars (1 and 3) were detected as
    /// sensors in the model, this is not the case anymore, they are not taken
    /// into account.
    bool sendSonarSensorValues(
      const SonarSensor* sonarSensor, const std::vector<float>& values);
    /// \brief sends value in meters to the given sonarSensor (see remarks).
    /// \remarks if you use this method on a SonarSensor value that has a buffer
    /// size of 1, the space left in the array will be filled with 0s.
    bool sendSonarSensorValue(const SonarSensor* sonarSensor, float value);

    /// \brief sends values in meters to the given arrayDepthSensor
    bool sendArrayDepthSensorValues(
      const ArrayDepthSensor* arrayDepthSensor,
      const std::vector<float>& values);

    /// \brief gives the buffer size, width and height of the given camera
    /// \remarks The dimensions are expressed in pixels.
    void cameraBufferSize(
      const CameraSensor* camera,
      int* cameraBufferSize,
      int* width,
      int* height);
    /// \brief returns the buffer size of the camera.
    /// \remarks The value returned here is equal to width * height * 3. The
    /// dimensions are expressed in pixels. 3 corresponds to the 3 colors
    /// (RGB)
    /// \deprecated Since 1.18, use cameraBufferSize(camera, bufferSize, width,
    /// height) instead.
    int cameraBufferSize(const CameraSensor* camera);

    /// \brief gives the buffer size, width and height of the given depth
    /// camera.
    /// \remarks The dimensions are expressed in pixels.
    void cameraDepthBufferSize(
      const CameraDepthSensor* camera,
      int* cameraBufferSize,
      int* width,
      int* height);

    /// \brief gives the current resolution of the given CameraSensor
    CameraResolution cameraResolution(const BaseCamera* camera) const;
    /// \brief gives the current color space of the given CameraSensor
    CameraColorSpace cameraColorSpace(const BaseCamera* camera) const;

    /// Private implementation
    class HALInterfaceImpl* a_impl;
};


/// \brief get the associated width and height
void ALNAOSIM_API cameraResolution(CameraResolution camRes, int* width, int* height);

}
#endif // ALNAOSIM_H
