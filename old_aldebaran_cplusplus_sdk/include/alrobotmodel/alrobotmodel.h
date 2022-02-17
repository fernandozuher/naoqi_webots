/**
* Copyright (c) 2012 Aldebaran Robotics  All Rights Reserved
*/

#ifndef ALROBOTMODEL_H
#define ALROBOTMODEL_H

#include <almath/types/altransform.h>
#include <almath/types/alposition3d.h>
#include <string>

#include <qi/macro.hpp>

#ifdef alrobotmodel_EXPORTS
# define ALROBOTMODEL_API QI_EXPORT_API
#elif defined(alrobotmodel_IMPORTS)
# define ALROBOTMODEL_API QI_IMPORT_API
#else
# define ALROBOTMODEL_API
#endif

namespace Sim
{

  class Actuator;
  class ActuatorGroup;
  class AngleActuator;
  class AngleSensor;
  class AngleSpeedActuator;
  class AngleSpeedSensor;
  class ArrayDepthSensor;
  class BumperSensor;
  class CameraSensor;
  class CameraDepthSensor;
  class CoupledActuator;
  class CoupledSensor;
  class FSRSensor;
  class InertialSensor;
  class SonarSensor;
  class TactileSensor;
  class LEDActuator;
  class MicrophoneSensor;
  class Joint;
  class JointGroup;
  class JointSymmetry;
  class Link;
  class Sensor;
  class SingleDepthSensor;
  class TorqueActuator;
  class TorqueSensor;
  class WheelTorqueActuator;
  class WheelVelocityActuator;
  class WheelVelocitySensor;

  typedef SingleDepthSensor DepthInfraredSensor;

/// \class Model alrobotmodel.h
/// \brief Model is responsible of giving information of a physical robot
class ALROBOTMODEL_API Model
{
  public:

    /// \brief creates a Model with the file given. Throws if a problem occurs
    /// while parsing the file.
    /// \remarks This lib comes with a set of xml files describing robots. The
    /// file given should be the path to one of those!
    Model(const std::string& pathToModel);
    /// \brief destructor.
    ~Model();

    /// \brief gives the robot name.
    /// Use this to identify the type of the robot
    const std::string& name() const;

    /// \brief gives the displayable, beautiful robot name.
    /// \arg verbosity from 0 (default) to 2, gives a more precise name of the
    /// robot i.e. including its model (verbosity = 1) and its version
    /// (verbosity = 2).
    std::string prettyName(int verbosity = 0) const;

    /// \brief returns the content of the file used to create the model.
    /// \remarks The file returned is an xml defining the model.
    const std::string& configFile() const;

    /// \brief returns a vector containing pointers to all joints of the
    /// current model.
    std::vector<const Joint*> joints() const;
    /// \brief returns the joint named jointName, or a NULL pointer if the
    /// named joint has not been found.
    const Joint* joint(const std::string& jointName) const;

    /// \brief returns a vector containing pointers to all joint symmetries of
    /// current model.
    std::vector<const JointSymmetry*> jointSymmetries() const;
    /// \brief returns the JointSymmetry involving the given Joint, or NULL
    /// pointer if the given Joint has not been found.
    const JointSymmetry* jointSymmetry(const std::string& jointName) const;

    /// \brief returns a vector containing pointers to all predefined joint
    /// groups in the current model.
    std::vector<const JointGroup*> jointGroups() const;
    /// \brief returns the JointGroup named jointGroupName, or a NULL pointer if
    /// it has not been found.
    const JointGroup* jointGroup(const std::string& jointGroupName) const;
    /// \brief returns a vector containing pointers to all predefined joint
    /// groups containing the joint named jointName.
    /// \remarks the returned vector will be empty if the Joint does not belong
    /// to a JointGroup, or if the Joint does not exist.
    std::vector<const JointGroup*>
      jointGroupsOfJoint(const std::string& jointName) const;

    /// \brief returns a vector containing pointers to all links of the
    /// current model.
    std::vector<const Link*> links() const;
    /// \brief returns the link named linkName, or a NULL pointer if the
    /// named link has not been found.
    const Link* link(const std::string& linkName) const;
    /// \brief returns a pointer to the root link of the model, the base link
    /// of the Model.
    /// \remarks This link defines the global position of the model.
    const Link* rootLink() const;

    /// \brief returns a vector containing pointers to all actuators of the
    /// current model.
    std::vector<const Actuator*> actuators() const;
    /// \brief returns the actuator named actuatorName, or a NULL pointer if
    /// the named actuator has not been found.
    const Actuator* actuator(const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all predefined actuator
    /// groups in the current model.
    std::vector<const ActuatorGroup*> actuatorGroups() const;
    /// \brief returns the ActuatorGroup named actuatorGroupName, or a NULL
    /// pointer if it has not been found.
    const ActuatorGroup* actuatorGroup(
      const std::string& actuatorGroupName) const;
    /// \brief returns a vector containing pointers to all predefined actuator
    /// groups containing the joint named jointName.
    /// \remarks the returned vector will be empty if the Joint is not attached
    /// to an Actuator belonging to an ActuatorGroup or if the Joint does not
    /// exist.
    std::vector<const ActuatorGroup*>
      actuatorGroupsOfJoint(const std::string& jointName) const;

    /// \brief returns a vector containing pointers to all angle actuators
    /// of the current model.
    std::vector<const AngleActuator*> angleActuators() const;
    /// \brief returns the angle actuator named actuatorName, or a NULL pointer
    /// if the named angle actuator has not been found.
    const AngleActuator* angleActuator(const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all coupled actuators
    /// of the current model.
    std::vector<const CoupledActuator*> coupledActuators() const;
    /// \brief returns the coupled actuator named actuatorName, or a NULL
    /// pointer if the named coupled actuator has not been found.
    const CoupledActuator* coupledActuator(
      const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all torque actuators
    /// of the current model.
    std::vector<const TorqueActuator*> torqueActuators() const;
    /// \brief returns the torque actuator named actuatorName, or a NULL
    /// pointer if the named torque actuator has not been found.
    const TorqueActuator* torqueActuator(
      const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all angle speed actuators
    /// of the current model.
    std::vector<const AngleSpeedActuator*> angleSpeedActuators() const;
    /// \brief returns the angle speed actuator named actuatorName, or a NULL
    /// pointer if the named angle speed actuator has not been found.
    const AngleSpeedActuator* angleSpeedActuator(
      const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all wheel torque
    /// actuators of the current model.
    std::vector<const WheelTorqueActuator*> wheelTorqueActuators() const;
    /// \brief returns the wheel torque actuator named actuatorName, or a NULL
    /// pointer if the named wheel torque actuator has not been found.
    const WheelTorqueActuator* wheelTorqueActuator(
      const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all wheel velocity
    /// actuators of the current model.
    std::vector<const WheelVelocityActuator*> wheelVelocityActuators() const;
    /// \brief returns the wheel velocity actuator named actuatorName, or a NULL
    /// pointer if the named wheel velocity actuator has not been found.
    const WheelVelocityActuator* wheelVelocityActuator(
      const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all LED actuators
    /// of the current model if groupName is empty, and to the LED actuators
    /// belonging to the group groupName otherwise
    /// \remarks The group names can be retrieved in the documentation.
    std::vector<const LEDActuator*> ledActuators(
      const std::string& groupName = std::string()) const;
    /// \brief returns the LE actuator named actuatorName, or a NULL
    /// pointer if the named LED actuator has not been found.
    const LEDActuator* ledActuator(const std::string& actuatorName) const;

    /// \brief returns a vector containing pointers to all sensors of the
    /// current model.
    std::vector<const Sensor*> sensors() const;
    /// \brief returns the sensor named sensorName, or a NULL pointer if
    /// the named sensor has not been found.
    const Sensor* sensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all angle sensors of the
    /// current model.
    std::vector<const AngleSensor*> angleSensors() const;
    /// \brief returns the angle sensor named sensorName, or a NULL pointer if
    /// the named angle sensor has not been found.
    const AngleSensor* angleSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all coupled  sensors of
    /// the current model.
    std::vector<const CoupledSensor*> coupledSensors() const;
    /// \brief returns the coupled sensor named sensorName, or a NULL pointer
    /// if the named coupled sensor has not been found.
    const CoupledSensor* coupledSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all torque sensors of
    /// the current model.
    std::vector<const TorqueSensor*> torqueSensors() const;
    /// \brief returns the torque sensor named sensorName, or a NULL pointer
    /// if the named torque sensor has not been found.
    const TorqueSensor* torqueSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all angle speed sensors
    /// of the current model.
    std::vector<const AngleSpeedSensor*> angleSpeedSensors() const;
    /// \brief returns the angle speed sensor named sensorName, or a NULL
    /// pointer if the named angle speed sensor has not been found.
    const AngleSpeedSensor* angleSpeedSensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all wheel velocity
    /// sensors of the current model.
    std::vector<const WheelVelocitySensor*> wheelVelocitySensors() const;
    /// \brief returns the wheel velocity sensor named sensorName, or a NULL
    /// pointer if the named wheel velocity sensor has not been found.
    const WheelVelocitySensor* wheelVelocitySensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all camera sensors of
    /// the current model.
    std::vector<const CameraSensor*> cameraSensors() const;
    /// \brief returns the camera sensor named sensorName, or a NULL pointer if
    /// the named camera sensor has not been found.
    const CameraSensor* cameraSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all camera depth sensors
    /// of the current model.
    std::vector<const CameraDepthSensor*> cameraDepthSensors() const;
    /// \brief returns the camera depth sensor named sensorName, or a NULL
    /// pointer if the named camera depth sensor has not been found.
    const CameraDepthSensor* cameraDepthSensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all FSR sensors of the
    /// current model.
    std::vector<const FSRSensor*> fsrSensors() const;
    /// \brief returns the FSR sensor named sensorName, or a NULL pointer if
    /// the named FSR sensor has not been found.
    const FSRSensor* fsrSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all inertial sensors of
    /// the current model.
    std::vector<const InertialSensor*> inertialSensors() const;
    /// \brief returns the inertial sensor named sensorName, or a NULL pointer
    /// if the named inertial sensor has not been found.
    const InertialSensor* inertialSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all sonar sensors of the
    /// current model.
    std::vector<const SonarSensor*> sonarSensors() const;
    /// \brief returns the sonar sensor named sensorName, or a NULL pointer if
    /// the named sonar sensor has not been found.
    const SonarSensor* sonarSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all bumper sensors of
    /// the current model.
    std::vector<const BumperSensor*> bumperSensors() const;
    /// \brief returns the bumper sensor named sensorName, or a NULL pointer if
    /// the named bumper sensor has not been found.
    const BumperSensor* bumperSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all tactile sensors of
    /// the current model.
    std::vector<const TactileSensor*> tactileSensors() const;
    /// \brief returns the tactile sensor named sensorName, or a NULL pointer if
    /// the named tactile sensor has not been found.
    const TactileSensor* tactileSensor(const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all the single depth
    /// sensors of the current model.
    std::vector<const SingleDepthSensor*> singleDepthSensors() const;
    /// \brief returns the single depth sensor named sensorName, or a NULL
    /// pointer if the named single depth sensor has not been found.
    const SingleDepthSensor* singleDepthSensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all the array depth
    /// sensors of the current model.
    std::vector<const ArrayDepthSensor*> arrayDepthSensors() const;
    /// \brief returns the array depth sensor named sensorName, or a NULL
    /// pointer if the named array depth sensor has not been found.
    const ArrayDepthSensor* arrayDepthSensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all depth infrared
    /// sensors of the current model.
    /// \deprecated use singleDepthSensors instead.
    std::vector<const DepthInfraredSensor*> depthInfraredSensors() const;
    /// \brief returns the single depth sensor named sensorName, or a NULL
    /// pointer if single named depth infrared sensor has not been found.
    /// \deprecated use singleDepthSensor instead.
    const DepthInfraredSensor* depthInfraredSensor(
      const std::string& sensorName) const;

    /// \brief returns a vector containing pointers to all the microphone
    /// sensors of the current model.
    std::vector<const MicrophoneSensor*> microphoneSensors() const;
    /// \brief returns the microphone sensor named sensorName, or a NULL
    /// pointer if the named microphone sensor has not been found.
    const MicrophoneSensor* microphoneSensor(
      const std::string& sensorName) const;

    /// \brief private implementation.
    class ModelImpl* a_impl;
};

/// \class JointSymmetry alrobotmodel.h
/// \brief JointSymmetry defines a symmetry between two joints
class ALROBOTMODEL_API JointSymmetry
{

  public:

    /// \brief creates an empty JointSymmetry, you should not use this.
    /// \warning The JointSymmetry being empty, every access to this object will
    /// throw.
    JointSymmetry();

    /// \brief destructor.
    ~JointSymmetry();

    /// \brief the symmetry can be direct or reversed
    enum SymmetryType
    {
      MIRROR_SYM,
      MIRROR_ANTISYM,
    };

    /// \brief returns the two symmetric joints.
    std::pair<const Joint*, const Joint*> symmetricJoints() const;

    /// \brief returns the symmetric Joint of the given Joint.
    const Joint* symmetricJoint(const Joint* joint) const;

    /// \brief returns the type of the symmetry.
    SymmetryType symmetryType() const;

    /// brief private implementation.
    class JointSymmetryImpl* a_impl;

};

/// \class JointGroup alrobotmodel.h
/// \brief JointGroup is a predefined and named ordered group of joints that
/// allow simpler calls of ALMotion API.
class ALROBOTMODEL_API JointGroup
{

  public:

    /// \brief creates an empty JointGroup, you should not use this.
    /// \warning The JointGroup created being empty, every access to this
    /// object will throw.
    JointGroup();

    /// \brief destructor.
    ~JointGroup();

    /// \brief name of the JointGroup.
    const std::string& name() const;

    /// \brief ordered vector of the joints of the JointGroup.
    std::vector<const Joint*> joints() const;

    /// \brief private implementation.
    class JointGroupImpl* a_impl;
};

/// \class Frame alrobotmodel.h
/// \brief Frame defines a position in space and has a name.
class ALROBOTMODEL_API Frame
{
  public:
    /// \brief creates an empty Frame, you should not use this.
    /// \warning The Frame being empty, every access to this object will throw.
    Frame();
    /// \brief destructor.
    ~Frame();
    /// \brief returns the name of the Frame.
    const std::string& name() const;
    /// \brief returns the position of the Frame.
    /// \remarks See the C++ reference of libalmath in Aldebaran's
    /// \deprecated
    /// Documentation for more details on AL::Math::Transform.
    const AL::Math::Transform& position() const;
    /// \brief returns the frame in which the position is defined.
    const Frame* parentFrame() const;
    /// \brief returns the position of the Frame frame in the parent Frame.
    /// \remarks See the C++ reference of libalmath in Aldebaran's
    /// Documentation for more details on AL::Math::Transform.
    const AL::Math::Transform& localPosition() const;
    /// \brief returns the position of the Frame frame in global Frame
    /// (generally robot's Torso).
    /// \remarks See the C++ reference of libalmath in Aldebaran's
    /// Documentation for more details on AL::Math::Transform.
    static AL::Math::Transform globalPosition(
      const Frame* frame);
    /// \brief private implementation.
    class FrameImpl* a_impl;
};

/// \class Joint alrobotmodel.h
/// \brief Joint defines an articulation of the robot.
class ALROBOTMODEL_API Joint
{
  public:
    /// \brief creates an empty Joint, you should not use this.
    /// \warning The Joint being empty, every access to this object will throw.
    Joint();
    /// \brief destructor.
    ~Joint();
    /// \brief returns the Frame of the Joint.
    /// \remarks The Frame of the Joint is defined so that the joint rotates
    /// around its Z-axis.
    const Frame* frame() const;
    /// \brief returns the name of the Joint.
    const std::string& name() const;
    /// \brief returns the parent link of the Joint. Joints always have a
    /// parent link.
    /// \remarks the Joint object is actually the articulation between its
    /// parent link and children link.
    const Link* parentLink() const;
    /// \brief returns the child link of the Joint. Joints always have a
    /// child link.
    /// \remarks the Joint object is actually the articulation between its
    /// parent link and children link.
    const Link* childLink() const;
    /// Private implementation
    class JointImpl* a_impl;
};

/// \brief This function returns if a friction coefficient (nil or positive)
/// between frictionMaterial1 and frictionMaterial2 has been found and stores
/// it in frictionCoeff if it returns true.
ALROBOTMODEL_API bool frictionCoeff(
  const std::string& frictionMaterial1,
  const std::string& frictionMaterial2,
  float& frictionCoeff);

/// \class MassData alrobotmodel.h
/// \brief MassData embeds information about the inertial mass of a
/// physical object.
class ALROBOTMODEL_API MassData
{
  public:
    /// \brief creates an empty MassData, you should not use this.
    /// \warning The MassData being empty, every access to this object will
    /// throw.
    MassData();
    /// \brief destructor.
    virtual ~MassData();
    /// \brief returns the mass in Kg.
    float mass() const;
    /// \brief returns the Center of Mass, relative to the frame of the object,
    /// defined in meters in a vector AL::Math::Position3D.
    /// \remarks See the C++ reference of libalmath in Aldebaran's
    /// Documentation for more details on AL::Math::Position3D.
    const AL::Math::Position3D& CoM() const;
    /// \brief Inertia matrix, see Motion's module reference in Aldebaran's
    /// Documentation to have more details.
    const std::vector<float>& inertiaMatrix() const;
    /// \brief Private implementation.
    class MassDataImpl* a_impl;
};

/// \class VisualData alrobotmodel.h
/// \brief VisualData embeds information about the visualization of a
/// physical object.
class ALROBOTMODEL_API VisualData
{
  public:
    /// \brief creates an empty VisualData, you should not use this.
    /// \warning The VisualData being empty, every access to this object will
    /// throw.
    VisualData();
    /// \brief destructor.
    virtual ~VisualData();
    /// \brief returns the relative path to the 3D representation of the
    /// Link.
    /// \remarks The root folder considered is
    /// 'simulator-sdk/share/alrobotmodel/meshes'.
    /// The meshes pointed this way are *.mesh files, made to be used with
    /// the free 3D Engine Ogre.
    const std::string& meshPath() const;
    /// \brief returns the transform between the link and the mesh provided
    /// by VisualData::meshPath()
    const AL::Math::Transform& meshTransform() const;
    /// \brief Private implementation.
    class VisualDataImpl* a_impl;
};

/// \class Link alrobotmodel.h
/// \brief Link defines a solid and mobile part of the robot.
class ALROBOTMODEL_API Link
{
  public:
    /// \brief link can be classic links as in Denavit-Hartenberg
    /// representation, or of specific kind
    enum LinkType
    {
      CLASSIC,
      WHEEL_OMNI,
    };
    /// \brief creates an empty Link, you should not use this.
    /// \warning The Link being empty, every access to this object will throw.
    Link();
    /// \brief destructor.
    virtual ~Link();
    /// \brief returns the Frame of the Link.
    /// \remarks The Frame of the Link allows defining mass and sensors
    /// position in a convenient way. Generally in this frame, the z-axis points
    /// up and x points forward. See Hardware section of Motion's documentation
    /// for more details.
    const Frame* frame() const;
    /// \brief returns the name of the Link.
    const std::string& name() const;
    /// \brief returns the parent joint of the link. Only the root link has no
    /// parent joint.
    const Joint* parentJoint() const;
    /// \brief returns the children joints of the link. A link can have 0 or
    /// more children links.
    const std::vector<const Joint*> childrenJoints() const;
    /// \brief returns the MassData of the Link.
    const MassData* mass() const;
    /// \brief returns the friction material of the Link.
    const std::string& frictionMaterial() const;
    /// \brief returns the VisualData of the Link.
    const VisualData* visual() const;
    /// \brief returns the link type.
    LinkType type() const;
    /// \brief private implementation.
    class LinkImpl* a_impl;
};

/// \class Actuator alrobotmodel.h
/// \brief Actuator is a generic class defining a robot owned object that have
/// an influence on it and/or its environment.
class ALROBOTMODEL_API Actuator
{
  public:
    /// \enum Type gives the type of the Actuator.
    enum Type
    {
      ANGLE_MOTOR,
      COUPLED_MOTOR,
      TORQUE_MOTOR,
      ANGLE_SPEED_MOTOR,
      WHEEL_TORQUE,
      WHEEL_VELOCITY,
      /// Not implemented yet.
      LED,

    };
    /// \brief private constructor.
    Actuator(class ActuatorImpl* impl);
    /// \brief copy constructor.
    Actuator(const Actuator& other);
    /// \brief destructor.
    ~Actuator();
    /// \brief returns the Frame of the Actuator.
    const Frame* frame() const;
    /// \brief returns the name of the Actuator.
    const virtual std::string& name() const;
    /// \brief returns the Type of the Actuator.
    Type type() const;
    /// \brief returns the size of the buffer of a command to the Actuator in
    /// bits.
    virtual int bufferSize() const = 0;
    /// \brief private implementation
    ActuatorImpl* a_impl;
};

/// \class ActuatorGroup alrobotmodel.h
/// \brief ActuatorSymmetry is a predefined and named ordered group of actuators
/// that allows simpler calls of ALMotion API.
class ALROBOTMODEL_API ActuatorGroup
{

  public:

    /// \brief creates an empty ActuatorGroup, you should not use this.
    /// \warning The ActuatorGroup created being empty, every access to this
    /// object will throw.
    ActuatorGroup();

    /// \brief destructor.
    ~ActuatorGroup();

    /// \brief name of the ActuatorGroup.
    const std::string& name() const;

    /// \brief parent of the actuator group if there is one, NULL otherwise.
    const ActuatorGroup * parent() const;

    /// \brief ordered vector of the actuators of the ActuatorGroup.
    std::vector<const Actuator*> actuators() const;

    /// \brief private implementation.
    class ActuatorGroupImpl* a_impl;

};

/// \class DCMActuator alrobotmodel.h
/// \brief DCMActuator defines a generic actuator which commands are
/// communicated through the DCM.
class ALROBOTMODEL_API DCMActuator: public Actuator
{
  public:
    /// \brief private constructor.
    DCMActuator(class DCMActuatorImpl* impl);
    /// \brief copy constructor.
    DCMActuator(const DCMActuator& other);
    /// \brief destructor
    ~DCMActuator();
    /// \brief returns a vector of the strings in the DCM concerning this
    /// actuator.
    const std::vector<std::string>& dcmKeys() const;
    /// \brief returns the maximum size of the buffer of a measure from the
    /// DCMActuator in bits.
    virtual int bufferSize() const = 0;
};

/// \class AngleActuator alrobotmodel.h
/// \brief AngleActuator is a class defining an angular motor. It is attached to
/// the joint that it can actuate.
class ALROBOTMODEL_API AngleActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    AngleActuator(class AngleActuatorImpl* impl);
    /// \brief copy constructor.
    AngleActuator(const AngleActuator& other);
    /// \brief destructor.
    ~AngleActuator();
    /// \brief returns the reflected symmetric Actuator, and NULL if it is not
    /// defined.
    const AngleActuator* reflectedSymmetric() const;
    /// \brief returns if the symmetric actuator is reversed w.r.t. to the
    /// current actuator, false if there is no symmetric actuator defined.
    bool reflectedSymmetricReversed() const;
    /// \brief returns true if the actuator is always reflected.
    bool reflectionForced() const;
    /// \brief returns the size of the buffer of a command to the AngleActuator
    /// in bits.
    virtual int bufferSize() const;
    /// \brief returns the start value of the AngleActuator in radians.
    float startValue() const;
    /// \brief returns the minimal value of the AngleActuator in radians.
    float minValue() const;
    /// \brief returns the maximal value of the AngleActuator in radians.
    float maxValue() const;
    /// \brief returns the maximal speed of the AngleActuator in radians per
    /// second.
    float maxSpeed() const;
    /// \brief returns the controlled joint by the AngleActuator.
    const Joint* controlledJoint() const;
};

/// \class CoupledActuator alrobotmodel.h
/// \brief CoupledActuator is a class defining a coupled motor. It is attached
/// to several joints and can actuate them. Its command is between 0 and 1.
class ALROBOTMODEL_API CoupledActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    CoupledActuator(class CoupledActuatorImpl* impl);
    /// \brief copy constructor.
    CoupledActuator(const CoupledActuator& other);
    /// \brief destructor.
    ~CoupledActuator();
    /// \brief returns the reflected symmetric Actuator, and NULL if it is not
    /// defined.
    const CoupledActuator* reflectedSymmetric() const;
    /// \brief returns if the symmetric actuator is reversed w.r.t. to the
    /// current actuator, false if there is no symmetric actuator defined.
    bool reflectedSymmetricReversed() const;
    /// \brief returns true if the actuator is always reflected.
    bool reflectionForced() const;
    /// \brief returns the size of the buffer of a command to the
    /// CoupledActuator in bits.
    virtual int bufferSize() const;
    /// \brief returns the start value of the CoupledActuator (between 0 and 1,
    /// no unit).
    float startValue() const;
    /// \brief returns the minimal value of the CoupledActuator (between 0 and
    /// 1, no unit).
    float minValue() const;
    /// \brief returns the maximal value of the CoupledActuator (between 0 and
    /// 1, no unit).
    float maxValue() const;
    /// \brief returns the maximal speed of the CoupledActuator in Hertz.
    float maxSpeed() const;
    /// \brief returns the controlled joints and the ratio of the rotation of
    /// the associated joint per the command.
    std::vector<std::pair<const Joint*, float> >
      controlledJointAndRatios() const;
};

/// \class TorqueActuator alrobotmodel.h
/// \brief TorqueActuator is a class defining a torque-controlled motor. It is
/// attached to one joint and can actuate it.
class ALROBOTMODEL_API TorqueActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    TorqueActuator(class TorqueActuatorImpl* impl);
    /// \brief copy constructor.
    TorqueActuator(const TorqueActuator& other);
    /// \brief destructor.
    ~TorqueActuator();
    /// \brief returns the reflected symmetric Actuator, and NULL if it is not
    /// defined.
    const TorqueActuator* reflectedSymmetric() const;
    /// \brief returns if the symmetric actuator is reversed w.r.t. to the
    /// current actuator, false if there is no symmetric actuator defined.
    bool reflectedSymmetricReversed() const;
    /// \brief returns the size of the buffer of a command to the TorqueActuator
    /// in bits.
    virtual int bufferSize() const;
    /// \brief returns the start value of the TorqueActuator (in Newton per
    /// meter).
    float startValue() const;
    /// \brief returns the minimal value of the TorqueActuator (in Newton per
    /// meter).
    float minValue() const;
    /// \brief returns the maximal value of the TorqueActuator (in Newton per
    /// meter).
    float maxValue() const;
    /// \brief returns the controlled joint by the TorqueActuator.
    const Joint* controlledJoint() const;
};

/// \class AngleSpeedActuator alrobotmodel.h
/// \brief AngleSpeedActuator is a class defining a speed-controlled motor. It
/// is attached to one joint and can actuate it.
class ALROBOTMODEL_API AngleSpeedActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    AngleSpeedActuator(class AngleSpeedActuatorImpl* impl);
    /// \brief copy constructor.
    AngleSpeedActuator(const AngleSpeedActuator& other);
    /// \brief destructor.
    ~AngleSpeedActuator();
    /// \brief returns the reflected symmetric Actuator, and NULL if it is not
    /// defined.
    const AngleSpeedActuator* reflectedSymmetric() const;
    /// \brief returns if the symmetric actuator is reversed w.r.t. to the
    /// current actuator, false if there is no symmetric actuator defined.
    bool reflectedSymmetricReversed() const;
    /// \brief returns the size of the buffer of a command to the
    /// AngleSpeedActuator in bits.
    virtual int bufferSize() const;
    /// \brief returns the start value of the AngleSpeedActuator (in radian per
    /// second).
    float startValue() const;
    /// \brief returns the minimal value of the AngleSpeedActuator (in radian
    /// per second).
    float minValue() const;
    /// \brief returns the maximal value of the AngleSpeedActuator (in radian
    /// per second).
    float maxValue() const;
    /// \brief returns the controlled joint by the AngleSpeedActuator.
    const Joint* controlledJoint() const;
};

/// \class WheelTorqueActuator alrobotmodel.h
/// \brief WheelTorqueActuator is a class defining an actuator that drives a
/// wheel.
class ALROBOTMODEL_API WheelTorqueActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    WheelTorqueActuator(class WheelTorqueActuatorImpl* impl);
    /// \brief copy constructor.
    WheelTorqueActuator(const WheelTorqueActuator& other);
      /// \brief destructor.
    ~WheelTorqueActuator();
    virtual int bufferSize() const;
    /// \brief returns the maximal torque of the WheelTorqueActuator (in
    // Newton per meter).
    float maxTorque() const;
    /// \brief returns the controlled joint by the WheelTorqueActuator
    const Joint* controlledJoint() const;
};

/// \class WheelVelocityActuator alrobotmodel.h
/// \brief WheelVelocityActuator is a class defining an actuator that drives a
/// wheel.
class ALROBOTMODEL_API WheelVelocityActuator: public DCMActuator
{
  public:
    /// \brief private constructor.
    WheelVelocityActuator(class WheelVelocityActuatorImpl* impl);
    /// \brief copy constructor.
    WheelVelocityActuator(const WheelVelocityActuator& other);
    /// \brief destructor.
    ~WheelVelocityActuator();
    /// \brief returns the size of the buffer of a command to the
    /// WheelVelocityActuator in bits.
    virtual int bufferSize() const;
    /// \brief returns the maximal torque of the WheelVelocityActuator (in
    /// Newton per meter).
    float maxVelocity() const;
    /// \brief returns the controlled joint by the WheelTorqueActuator
    const Joint* controlledJoint() const;
};

/// \class LEDActuator alrobotmodel.h
/// \brief LEDActuator is a class defining a LED actuator
class ALROBOTMODEL_API LEDActuator: public DCMActuator
{
  public:
    /// \brief color of the LED
    enum Color
    {
      RED,
      GREEN,
      BLUE
    };

  public:
    /// \brief private constructor.
    LEDActuator(class LEDActuatorImpl* impl);
    /// \brief copy constructor.
    LEDActuator(const LEDActuator& other);
    /// \brief destructor.
    ~LEDActuator();
    /// \brief returns the size of the buffer of a command to the
    /// LEDActuator in bits.
    virtual int bufferSize() const;
    /// \brief returns the shortname of the LED.
    const std::string& shortname() const;
    /// \brief returns the group names the LED belongs to.
    const std::vector<std::string>& groups() const;
    /// \brief Color of the LED.
    Color color() const;
};

/// \class Sensor alrobotmodel.h
/// \brief Sensor is a generic class defining a robot owned object that measure
/// a quantity about it or its environment.
class ALROBOTMODEL_API Sensor
{
  public:
    /// \enum Type gives the type of the Sensor.
    enum Type
    {
      ANGLE,
      COUPLED,
      SONAR,
      CAMERA,
      FSR,
      INERTIAL,
      BUMPER,
      TORQUE,
      ANGLE_SPEED,
      WHEEL_VELOCITY,
      TACTILE,
      DEPTH_INFRARED, // deprecated
      SINGLE_DEPTH,
      ARRAY_DEPTH,
      CAMERA_DEPTH,
      MICROPHONE,
      /// Not implemented yet
      /// TACTILE,
      /// LASER,
      /// MICROPHONE
      /// ...
    };
    /// \brief creates an empty Sensor, you should not use this.
    /// \warning The Sensor being empty, every access to this object will
    /// throw.
    Sensor();
    /// \brief destructor.
    ~Sensor();
    /// \brief returns the Frame of the Sensor.
    const Frame* frame() const;
    /// \brief returns the name of the Sensor.
    virtual const std::string& name() const;
    /// \brief returns the Type of the Sensor.
    Type type() const;
    /// \brief returns the maximum size of the buffer of a measure from the
    /// Sensor in bits.
    virtual int bufferSize() const = 0;
    /// \brief private implementation.
    class SensorImpl* a_impl;
};

/// \class DCMSensor alrobotmodel.h
/// \brief DCMSensor defines a generic sensor which values are communicated
/// through the DCM.
class ALROBOTMODEL_API DCMSensor: public Sensor
{
  public:
    /// \brief creates an empty DCMSensor, you should not use this.
    /// \warning The DCMSensor being empty, every access to this object will
    /// throw.
    DCMSensor();
    /// \brief destructor
    ~DCMSensor();
    /// \brief returns a vector of the full strings in the DCM concerning this
    /// sensor. This keys can be used directly to get data.
    const std::vector<std::string>& dcmKeys() const;
    /// \brief returns a vector of the full strings in the DCM concerning this
    /// \deprecated call dcmKeys instead
    std::vector<std::string> fullDcmKeys() const;
    /// \brief returns a vector of the strings in the DCM concerning the
    ///  state keys of this sensor.
    const std::vector<std::string>& dcmStateKeys() const;
    /// \brief returns a vector of the string in the DCM concerning the
    /// command keys of this sensor. These keys are useful to command the
    /// sensor
    const std::vector<std::string>& dcmCommandKeys() const;
    /// \brief returns the maximum size of the buffer of a measure from the
    /// DCMSensor in bits.
    virtual int bufferSize() const = 0;
};


/// \class AngleSensor alrobotmodel.h
/// \brief AngleSensor is a class defining an angular sensor. It is attached to
/// an angular motor (it has the same name) and can measure its rotation.
class ALROBOTMODEL_API AngleSensor: public DCMSensor
{
  public:
    /// \brief creates an empty AngleSensor, you should not use this.
    /// \warning The AngleSensor being empty, every access to this object will
    /// throw.
    AngleSensor();
    /// \brief destructor.
    ~AngleSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// AngleSensor in bits.
    virtual int bufferSize() const;
};

/// \class CoupledSensor alrobotmodel.h
/// \brief CoupledSensor is a class defining a coupled sensor.
class ALROBOTMODEL_API CoupledSensor: public DCMSensor
{
  public:
    /// \brief creates an empty CoupledSensor, you should not use this.
    /// \warning The CoupledSensor being empty, every access to this object
    /// will throw.
    CoupledSensor();
    /// \brief destructor.
    ~CoupledSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// CoupledSensor in bits.
    virtual int bufferSize() const;
};

/// \class TorqueSensor alrobotmodel.h
/// \brief TorqueSensor is a class defining an torque sensor. It is attached to
/// a torque motor (it has the same name) and can measure its torque.
class ALROBOTMODEL_API TorqueSensor: public DCMSensor
{
  public:
    /// \brief creates an empty TorqueSensor, you should not use this.
    /// \warning The TorqueSensor being empty, every access to this object will
    /// throw.
    TorqueSensor();
    /// \brief destructor.
    ~TorqueSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// TorqueSensor in bits.
    virtual int bufferSize() const;
};

/// \class AngleSpeedSensor alrobotmodel.h
/// \brief AngleSpeedSensor is a class defining an angle speed sensor. It is
/// attached to an angle speed motor (it has the same name) and can measure its
/// angle speed.
class ALROBOTMODEL_API AngleSpeedSensor: public DCMSensor
{
  public:
    /// \brief creates an empty AngleSpeedSensor, you should not use this.
    /// \warning The AngleSpeedSensor being empty, every access to this object
    /// will throw.
    AngleSpeedSensor();
    /// \brief destructor.
    ~AngleSpeedSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// AngleSpeedSensor in bits.
    virtual int bufferSize() const;
};

/// \class WheelVelocitySensor alrobotmodel.h
/// \brief WheelVelocitySensor is a class defining a wheel velocity sensor. It
/// is to a wheel velocity motor (it has the same name) and can measure its
/// wheel velocity.
class ALROBOTMODEL_API WheelVelocitySensor: public DCMSensor
{
  public:
    /// \brief creates an empty WheelVelocitySensor, you should not use this.
    /// \warning The WheelVelocitySensor being empty, every access to this
    /// object will throw.
    WheelVelocitySensor();
    /// \brief destructor.
    ~WheelVelocitySensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// WheelVelocitySensor in bits.
    virtual int bufferSize() const;
};

/// \class BaseCamera alrobotmodel.h
/// \brief BaseCamera is the base class of Camera classes.
class ALROBOTMODEL_API BaseCamera: public Sensor
{
  public:
    /// \brief creates an empty BaseCamera, you should not use this.
    /// \warning The Sensor being empty, every access to this object will
    /// throw.
    BaseCamera();
    /// \brief destructor
    ~BaseCamera();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// Sensor in bits.
    virtual int bufferSize() const = 0;
};

/// \class CameraSensor alrobotmodel.h
/// \brief CameraSensor is a class defining a camera.
class ALROBOTMODEL_API CameraSensor: public BaseCamera
{
  public:
    /// \brief creates an empty CameraSensor, you should not use this.
    /// \warning The CameraSensor being empty, every access to this object
    /// will throw.
    CameraSensor();
    /// \brief destructor.
    ~CameraSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// CameraSensor in bits.
    virtual int bufferSize() const;
    /// \brief maximum width of the image captured in pixels.
    int width() const;
    /// \brief maximum height of the image captured in pixels.
    int height() const;
};

/// \class CameraDepthSensor alrobotmodel.h
/// \brief CameraDepthSensor is a class defining a depth sensing camera.
class ALROBOTMODEL_API CameraDepthSensor: public BaseCamera
{
  public:
    /// \brief creates an empty CameraDepthSensor, you should not use this.
    /// \warning The CameraDepthSensor being empty, every access to this object
    /// will throw.
    CameraDepthSensor();
    /// \brief destructor.
    ~CameraDepthSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// CameraDepthSensor in bits.
    virtual int bufferSize() const;
    /// \brief maximum width of the image captured in pixels.
    int width() const;
    /// \brief maximum height of the image captured in pixels.
    int height() const;
};

/// \class FSRSensor alrobotmodel.h
/// \brief FSRSensor is a class defining a Force Sensitive Resistor sensor.
class ALROBOTMODEL_API FSRSensor: public DCMSensor
{
  public:
    /// \brief creates an empty FSRSensor, you should not use this.
    /// \warning The FSRSensor being empty, every access to this object
    /// will throw.
    FSRSensor();
    /// \brief destructor.
    ~FSRSensor();
    /// \brief returns the maximum size of the buffer of a measure from the FSRSensor
    /// in bits.
    virtual int bufferSize() const;
};

/// \class InertialSensor alrobotmodel.h
/// \brief InertialSensor is a class defining a inertial unit sensor.
class ALROBOTMODEL_API InertialSensor: public DCMSensor
{
  public:
    /// \brief creates an empty InertialSensor, you should not use this.
    /// \warning The InertialSensor being empty, every access to this object
    /// will throw.
    InertialSensor();
    /// \brief destructor.
    ~InertialSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// InertialSensor in bits.
    virtual int bufferSize() const;
};

/// \class SonarSensor alrobotmodel.h
/// \brief SonarSensor is a class defining a sonar sensor.
class ALROBOTMODEL_API SonarSensor: public DCMSensor
{
  public:
    /// \brief creates an empty SonarSensor, you should not use this.
    /// \warning The SonarSensor being empty, every access to this object
    /// will throw.
    SonarSensor();
    /// \brief destructor.
    ~SonarSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// SonarSensor in bits.
    virtual int bufferSize() const;
};

/// \class BumperSensor alrobotmodel.h
/// \brief BumperSensor is a class defining a bumper sensor.
class ALROBOTMODEL_API BumperSensor: public DCMSensor
{
  public:
    /// \brief creates an empty BumperSensor, you should not use this.
    /// \warning The BumperSensor being empty, every access to this object
    /// will throw.
    BumperSensor();
    /// \brief destructor.
    ~BumperSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// BumperSensor in bits.
    virtual int bufferSize() const;
};

/// \class TactileSensor alrobotmodel.h
/// \brief TactileSensor is a class defining a tactile sensor.
class ALROBOTMODEL_API TactileSensor: public DCMSensor
{
  public:
    /// \brief creates an empty TactileSensor, you should not use this.
    /// \warning The TactileSensor being empty, every access to this object
    /// will throw.
    TactileSensor();
    /// \brief destructor.
    ~TactileSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// TactileSensor in bits.
    virtual int bufferSize() const;
};

/// \class SingleDepthSensor alrobotmodel.h
/// \brief SingleDepthSensor is a class defining a sensor that provides a single
///  depth measurement.
class ALROBOTMODEL_API SingleDepthSensor: public DCMSensor
{
  public:
    /// \brief creates an empty SingleDepthSensor, you should not use this.
    /// \warning The SingleDepthSensor being empty, every access to this
    /// object will throw.
    SingleDepthSensor();
    /// \brief destructor.
    ~SingleDepthSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// SingleDepthSensor in bits.
    virtual int bufferSize() const;
};

/// \class ArrayDepthSensor alrobotmodel.h
/// \brief ArrayDepthSensor is a class defining a sensor made of an array of
/// depth sensors.
class ALROBOTMODEL_API ArrayDepthSensor: public DCMSensor
{
  public:
    /// \brief creates an empty ArrayDepthSensor, you should not use this.
    /// \warning The ArrayDepthSensor being empty, every access to this
    /// object will throw.
    ArrayDepthSensor();
    /// \brief destructor.
    ~ArrayDepthSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// ArrayDepthSensor in bits.
    virtual int bufferSize() const;
    /// \brief maximum width of the array captured in pixels.
    int width() const;
    /// \brief maximum height of the array captured in pixels.
    int height() const;
};

/// \class MicrophoneSensor alrobotmodel.h
/// \brief MicrophoneSensor is a class defining a microphone sensor.
class ALROBOTMODEL_API MicrophoneSensor: public Sensor
{
  public:
    /// \brief creates an empty MicrophoneSensor, you should not use this.
    /// \warning The MicrophoneSensor being empty, every access to this
    /// object will throw.
    MicrophoneSensor();
    /// \brief destructor.
    ~MicrophoneSensor();
    /// \brief returns the maximum size of the buffer of a measure from the
    /// ArrayDepthSensor in bits.
    virtual int bufferSize() const;
};

}

#endif // ALROBOTMODEL_H
