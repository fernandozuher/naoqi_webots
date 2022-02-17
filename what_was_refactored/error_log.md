# ERRORS

FROM naoqi_webots-master/controllers/nao/03_others/Singletons.cpp:

## FIRST ERROR

```c++
try {
    std::cout << "\n\n\t\t\t- Instantiating model...\n" << std::flush;
    m_model = new Sim::Model(wbu_system_short_path(path_to_model.c_str()));
    std::cout << "\t\t\tok!" << std::flush;
}
...
try {
    std::cout << "\n\t\t\t- Instantiating HALInterface...\n" << std::flush;
    m_hal = new Sim::HALInterface(m_model, naoqi_port);
    std::cout << "\t\t\tok!" << std::flush;
}
...
```

Error (Error and Warning):

```shell
[naoqi_webots]          - Instantiating model...
[naoqi_webots] [E] 2777 posture: PostureLibrary::loadLibraryFromFile: cannot open file ""
[naoqi_webots]          ok!
[naoqi_webots]          - Instantiating HALInterface...
[naoqi_webots] [W] 2783 qimessaging.transportsocket: connect: Connection refused
[naoqi_webots]          ok!
```

## SECOND ERROR

```c++
m_launcher = new Sim::SimLauncher();
// TODO: remove this case when Aldebaran release the fixed simulator-sdk
// for Mac and Linux 64
std::cout << "\n\t\t\t- m_launcher->launch(...)..." << std::flush;
std::cout << "\n\t\t\t\t |" << std::flush;
std::cout << "\n\t\t\t\t V\n" << std::flush;
return m_launcher->launch(m_model, naoqi_port, sdk_prefix);
```

Error (Infos, Warnings, Errors):

```shell
[naoqi_webots]          - m_launcher->launch(...)...
[naoqi_webots]               |
[naoqi_webots]               V
[naoqi_webots] [I] 2777 SimLauncher: Launching ../../old_aldebaran_cplusplus_sdk/bin/hal -s hal-ipc9559 -p HAL/Robot/Type:string=Nao -p HAL/Simulation:int=1 -p HAL/Time:int=0 -p HAL/CycleTime:int=0 -p DCM/Time:int=0 -p DCM/CycleTime:int=0 -p HAL/SimShmId:int=9559 -p HAL/Ack:int=0 -p HAL/Nack:int=0 -p HAL/Error:int=0 
[naoqi_webots] [I] 2798 HAL: create sharedMemory : hal-ipc
[naoqi_webots] [I] 2798 xmlPreference::loadPreference: Load file /home/user/Desktop/git/naoqi_webots/old_aldebaran_cplusplus_sdk/etc/hal/hal.xml
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/CycleTime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/Time in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/TargetCycleMinWait in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 8000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/TargetCycleTime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 10
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/CycleTimeWarning in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 50
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/HeatLogPath in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: temperatureLog
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/I2Cpath in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: /dev/i2c-0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/Realtime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 1
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/RealtimePriority in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 60
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/hardnessMode in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: current_mode
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/CycleTime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Time in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/Simulation in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Robot/Type in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: Juliette
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Simulation in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Ack in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Nack in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Error in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/CycleTimeErrorCounter in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/CycleTimeErrorLastTime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0.000000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/Error in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/CycleTimeErrorCounter in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/CycleTimeErrorLastTime in module Hal, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0.000000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/CycleTime in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference DCM/Time in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Ack in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/CycleTime in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Error in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Nack in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/SimShmId in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 9559
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Simulation in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 1
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Time in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/Robot/Type in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: Nao
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference HAL/ShmFile in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: hal-ipc
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: No previous BodyId. Force BodyId from bootloader
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: Use BodyId from bootloader
[naoqi_webots] [E] 2798 DeviceManager::specialIdsCase: No Module Body found
[naoqi_webots] [3592182075] error  : usb: USB device not found
[naoqi_webots] [E] 2801 I2cThread: Unable to open /dev/i2c-head
[naoqi_webots] [E] 2801 I2cThread: Unable to open /dev/i2c-0
[naoqi_webots] [3592182075] warning: halthread: can't setup realtime priority for I2C
[naoqi_webots] [E] 2798 xmlPreference::loadPreference: File Device_Local.xml not found
[naoqi_webots] [I] 2798 xLoadBufferFromChestBoard: loading prefs from chestboard.
[naoqi_webots] [3592182076] warning: usb: Usb::BulkWrite: error: no device
[naoqi_webots] [3592182076] warning: usb: Usb::BulkWrite: error: no device
[naoqi_webots] [I] 2798 xLoadBufferFromChestBoard: DCMSubPref : USB doRequest Failed
[naoqi_webots] [I] 2798 xmlPreference::loadPreference: Load file /media/internal/DeviceHeadInternalGeode.xml
[naoqi_webots] [W] 2798 Q7Eeprom::read: CGOS access not granted.
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/FullHeadId in module Head, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: ALDT*******0000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/HeadId in module Head, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: ALDT*******0000
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: LowerBody (legs) will be configured for Maxxon motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: LowerBody (legs) will be configured for Maxxon motors
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: Left Hand motors will use maxons thermal model
[naoqi_webots] [I] 2798 InitNaoDevicesPlugin: Right Hand motors will use maxons thermal model
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: headIdKeyName : ALDT*******0000
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: fullHeadIdKeyName : ALDT*******0000
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: No previous BodyId. Force BodyId from bootloader
[naoqi_webots] [I] 2798 DeviceManager::specialIdsCase: Use BodyId from bootloader
[naoqi_webots] [E] 2798 DeviceManager::specialIdsCase: No BodyId from bootloader found
[naoqi_webots] [E] 2798 TestRobotVersionPlugin: No robot version
[naoqi_webots] [I] 2798 memberidentificationplugin: member identification on Nao
[naoqi_webots] [I] 2798 diagnosisPlugin: Board FaceBoard added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board EarLeds added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board InertialSensor added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board Battery added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board USBoard added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board ChestBoard added to the list
[naoqi_webots] [I] 2798 diagnosisPlugin: Board HeadBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board HeadBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board HeadBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board HeadBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board HeadBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftShoulderBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShoulderBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShoulderBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShoulderBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShoulderBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftArmBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftArmBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftArmBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftArmBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftArmBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftHandBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHandBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHandBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHandBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHandBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightShoulderBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShoulderBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShoulderBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShoulderBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShoulderBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightArmBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightArmBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightArmBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightArmBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightArmBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightHandBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHandBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHandBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHandBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHandBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightHipBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHipBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHipBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHipBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightHipBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightThighBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightThighBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightThighBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightThighBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightThighBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightShinBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShinBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShinBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShinBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightShinBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftHipBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHipBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHipBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHipBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftHipBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftThighBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftThighBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftThighBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftThighBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftThighBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftShinBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShinBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShinBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShinBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftShinBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board LeftFootBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftFootBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftFootBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftFootBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board LeftFootBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board RightFootBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightFootBoard : error 49 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightFootBoard : error 50 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightFootBoard : error 209 is only a warning, won't be logged
[naoqi_webots] [W] 2798 diagnosisPlugin: Board RightFootBoard : error 210 is only a warning, won't be logged
[naoqi_webots] [I] 2798 diagnosisPlugin: Board TouchBoard added to the list
[naoqi_webots] [W] 2798 diagnosisPlugin: Board Chest-Eeprom-80 : no log will be displayed
[naoqi_webots] [W] 2798 diagnosisPlugin: Board Chest-Eeprom-81 : no log will be displayed
[naoqi_webots] [I] 2798 diagnosisPlugin: Found 22 boards to log
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/HeadId in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 0000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Device/Camera/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 2
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/BaseVersion in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: V5.0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Device/TouchBoard/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 1
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Device/FaceBoard/Leds/Rotation in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 1
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/BaseVersion in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: V5.0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/Hand/Left/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 7
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/Hand/Right/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 7
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/Foot/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 3
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/Legs/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 7
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/LeftArm/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 3
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Device/RightArm/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 3
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 5.0.0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 5.0.0
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/Type in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: Nao
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Body/SoftwareRequirement in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 1.22.4
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Type in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: Nao
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference Device/DeviceList/ChestBoard/BodyNickName in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: Nao0000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference Device/DeviceList/ChestBoard/BodyId in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 00000ALDR1008E000000
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Color in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: RedP185C
[naoqi_webots] [I] 2798 ModulePreference::add: Add preference RobotConfig/Head/Device/Micro/Version in module Local, value 
[naoqi_webots] [I] 2798 AttrGeneric::debug: 2
[naoqi_webots] [E] 2798 SimulationPlugin: SubDevice not found RHipYawPitch/Position/Sensor
[naoqi_webots] [E] 2798 SimulationPlugin: SubDevice not found RHipYawPitch/Position/Actuator
[naoqi_webots] [3592182081] warning: halthread: can't setup realtime priority
[naoqi_webots] [I] 2798 DcmLostPlugin: Stiffness set to 0 due to DCM missing -- Leg
[naoqi_webots] [I] 2798 DcmLostPlugin: Stiffness set to 0 due to DCM missing -- Wheels
[naoqi_webots] [W] 2798 DcmLostPlugin: HAL stiffness decrease : HAL error set to 16
[naoqi_webots] [I] 2798 diagnosisPlugin: Comm lost (noCom)    on USBoard -- , ack 0, nack 0, no com. since 30000 ms
[naoqi_webots] [W] 2779 qimessaging.transportsocket: connect: Connection refused
[naoqi_webots] [W] 2784 qimessaging.transportsocket: connect: Connection refused
[naoqi_webots] [I] 2777 SimLauncher: Launching ../../old_aldebaran_cplusplus_sdk/bin/naoqi-bin -p 9559 --writable-path /tmp/SimLauncher6SPrDJJ 
[naoqi_webots] [I] 2967 core.naoqi: ..::: starting NAOqi version 2.1.4 :::..
[naoqi_webots] [I] 2967 core.naoqi: Copyright (c) 2005-2013, Aldebaran Robotics
[naoqi_webots] [I] 2967 core.naoqi: Build tag: jenkins-release-2.1_simulator-sdk_linux64-13
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: ServiceDirectory listener created on tcp://0.0.0.0:9559
[naoqi_webots] [I] 2967 qimessaging.transportserver: TransportServer will listen on: tcp://127.0.0.1:9559
[naoqi_webots] [I] 2967 qimessaging.transportserver: TransportServer will listen on: tcp://192.168.0.30:9559
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ServiceDirectory" (#1)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "LogManager" (#2)
[naoqi_webots] [I] 2967 core.lib.launcher: Loading "/home/user/Desktop/git/naoqi_webots/old_aldebaran_cplusplus_sdk/etc/naoqi/autoload.ini"
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALFileManager" (#3)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALMemory" (#4)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALLogger" (#5)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALPreferences" (#6)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALLauncher" (#7)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALBonjour" (#8)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALServiceManager" (#9)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALDebug" (#10)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALPreferenceManager" (#11)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "DCM" (#12)
[naoqi_webots] [I] 2970 DCM.Thread: DcmThread connect to sharedMemory : hal-ipc
[naoqi_webots] @@@@ Use relative clock @@@@
[naoqi_webots] [W] 2798 DcmLostPlugin: HAL stiffness decrease ended : HAL error back to 0 due to DCM start
[naoqi_webots] [W] 2798 ClientSyncPlugin: DCM detected
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALNotificationManager" (#13)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALResourceManager" (#14)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALRobotModel" (#15)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALSonar" (#16)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALFsr" (#17)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALSensors" (#18)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALBodyTemperature" (#19)
[naoqi_webots] [W] 2967 ALMotion.ALMotionConfigurator: DIAGNOSTIC_IS_OK: 1
[naoqi_webots] [W] 2967 ALMotion.ALMotionConfigurator: ENABLE_FOOT_CONTACT_PROTECTION: 1
[naoqi_webots] [W] 2967 ALMotion.ALMotionConfigurator: ENABLE_STIFFNESS_PROTECTION: 1
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALMotion" (#20)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALTouch" (#21)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALRobotPosture" (#22)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALRedBallTracker" (#23)
[naoqi_webots] [W] 2967 motion.balltracker: ALRedBallTracker is deprecated in version 1.16. Please use the module ALTracker instead.
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALMotionRecorder" (#24)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALLeds" (#25)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALWorldRepresentation" (#26)
[naoqi_webots] [W] 2967 packagemanager.sql.compat: Cannot check column install_time in packages
[naoqi_webots] [I] 2798 DcmLostPlugin: End decrease stiffness
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "PackageManager" (#27)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALUserSession" (#28)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALAudioPlayer" (#29)
[naoqi_webots] [W] 2967 altts: Could not find plugin: aitalk
[naoqi_webots] [W] 2967 altts: Could not find plugin: acapela
[naoqi_webots] [W] 2967 altts: Could not find plugin: nuance
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALTextToSpeech" (#30)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALBattery" (#31)
[naoqi_webots] [E] 2967 behavior.ALFrameManager: ALPreferenceManager.getValue did not return a string, but returned: 
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALFrameManager" (#32)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALPythonBridge" (#33)
[naoqi_webots] [I] 2967 python: ALPythonBridge: using naoqi from /home/user/Desktop/git/naoqi_webots/old_aldebaran_cplusplus_sdk/lib/naoqi.pyc
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALVideoDevice" (#34)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALRedBallDetection" (#35)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALBehaviorManager" (#36)
[naoqi_webots] [W] 2967 audio.altexttospeech.main: enableNotifications() is now deprecated. 
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALAnimatedSpeech" (#37)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALColorBlobDetection" (#38)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALVisualSpaceHistory" (#39)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALTracker" (#55)
[naoqi_webots] [W] 2985 audio.DeviceManager: Could not find plugin: 
[naoqi_webots] [E] 2985 audio.DeviceManager: no suitable plugin found
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALModularity" (#56)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALNavigation" (#57)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALMovementDetection" (#58)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALSegmentation3D" (#59)
[naoqi_webots] [E] 2967 modularity.private: Can't set data for source "FaceDetection_Status": source unknown.
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALPeoplePerception" (#60)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALSittingPeopleDetection" (#61)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALEngagementZones" (#62)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALGazeAnalysis" (#63)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALWavingDetection" (#64)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALCloseObjectDetection" (#65)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALFastPersonTracking" (#66)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALFindPersonHead" (#67)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALVisualCompass" (#68)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALLocalization" (#69)
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALPanoramaCompass" (#70)
[naoqi_webots] [E] 2967 Thinking: Error occurred during thinking while getting info of animation package animations:
[naoqi_webots] Package animations does not exist in database.
[naoqi_webots] [E] 2967 UserSessionManager: Could not connect to either UserSession, BasicAwareness, or PeoplePerception. UserSessionManager will be inactive.
[naoqi_webots] [W] 2967 AutonomousLife: ALAutonomousMoves has not been found. Will not affect Autonomous Life.
[naoqi_webots] [W] 2967 AutonomousLife: ALBasicAwareness has not been found. Will run without advanced tracking and automatic user session.
[naoqi_webots] [W] 2967 AutonomousLife: ALDiagnosis has not been found. May not be able to properly enter safeguard state
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALAutonomousLife" (#77)
[naoqi_webots] [I] 2967 Dialog: Starting Dialog ...
[naoqi_webots] [W] 2967 Dialog: ALSpeechRecognition has not been found. Will run without voice recognition.
[naoqi_webots] [I] 2967 Dialog: Dialog will run in mode simulated
[naoqi_webots] [W] 2967 Dialog: AI client Module not found
[naoqi_webots] [I] 2967 Dialog.LongTermMemory: User database creation succeed
[naoqi_webots] [I] 2967 Dialog.preference: No dialog history management
[naoqi_webots] [I] 2967 Dialog.preference: AI system enabled
[naoqi_webots] [I] 2967 Dialog.preference: BNF confidence 0.5
[naoqi_webots] [I] 2967 Dialog.preference: REMOTE confidence 0.3
[naoqi_webots] [I] 2967 Dialog.preference: Serialization enabled
[naoqi_webots] [I] 2967 Dialog.preference: Upper SLM 1
[naoqi_webots] [I] 2967 Dialog.preference: Enable auto update
[naoqi_webots] [I] 2967 Dialog.preference: Push mode 2
[naoqi_webots] [I] 2967 Dialog.preference: Enable full speech recognition
[naoqi_webots] [I] 2967 Dialog.preference: Audio expression enabled
[naoqi_webots] [I] 2967 Dialog.preference: Smalldisplacement enabled
[naoqi_webots] [I] 2967 Dialog.preference: Breath enabled
[naoqi_webots] [I] 2967 Dialog.preference: No animated speech configuration
[naoqi_webots] [I] 2967 Dialog.preference: Default volume 0
[naoqi_webots] [I] 2967 Dialog.preference: No dialog history management
[naoqi_webots] [I] 2967 Dialog.preference: AI system enabled
[naoqi_webots] [I] 2967 Dialog.preference: BNF confidence 0.5
[naoqi_webots] [I] 2967 Dialog.preference: REMOTE confidence 0.3
[naoqi_webots] [I] 2967 Dialog.preference: Serialization enabled
[naoqi_webots] [I] 2967 Dialog.preference: Upper SLM 1
[naoqi_webots] [I] 2967 Dialog.preference: Enable auto update
[naoqi_webots] [I] 2967 Dialog.preference: Push mode 2
[naoqi_webots] [I] 2967 Dialog.preference: Enable full speech recognition
[naoqi_webots] [I] 2967 Dialog.preference: Audio expression enabled
[naoqi_webots] [I] 2967 Dialog.preference: Smalldisplacement enabled
[naoqi_webots] [I] 2967 Dialog.preference: Breath enabled
[naoqi_webots] [I] 2967 Dialog.preference: No animated speech configuration
[naoqi_webots] [I] 2967 Dialog.preference: Default volume 0
[naoqi_webots] [I] 2967 qimessaging.servicedirectory: Registered Service "ALDialog" (#78)
[naoqi_webots] [I] 2967 core.naoqi: NAOqi is ready...
```

---
All those logs are related to:

- bool Singletons::initialize(...) :

```c++
m_model = new Sim::Model(wbu_system_short_path(path_to_model.c_str()));
...
m_hal = new Sim::HALInterface(m_model, naoqi_port);
...
return m_launcher->launch(m_model, naoqi_port, sdk_prefix);
```

Those code lines are intrinsically related to the communication with naoqi-sdk.