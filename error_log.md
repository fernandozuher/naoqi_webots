***FIRST ERROR***:
    
    "
    [naoqisim]          - Instantiating model...
    [naoqisim] [E] 659 posture: PostureLibrary::loadLibraryFromFile: cannot open file ""
    [naoqisim]          ok!
    "

- FROM naoqisim-master/controllers/nao/03_others/Singletons.cpp:

        try {
            std::cout << "\n\t\t\t- Instantiating model...\n" << std::flush;
            m_model = new Sim::Model(wbu_system_short_path(path_to_model.c_str()));
            std::cout << "\t\t\tok!" << std::flush;
        }
        ...

***SECOND ERROR***:

    "
    [naoqisim]          - m_launcher->launch(...)...
    [naoqisim]               |
    [naoqisim]               V
    [naoqisim] [W] 668 qimessaging.transportsocket: connect: Connection refused
    [naoqisim] [I] 659 SimLauncher: Launching ../../aldebaran/simulator-sdk/bin/hal -s hal-ipc9559 -p HAL/Robot/Type:string=Nao -p HAL/Simulation:int=1 -p HAL/Time:int=0 -p HAL/CycleTime:int=0 -p DCM/Time:int=0 -p DCM/CycleTime:int=0 -p HAL/SimShmId:int=9559 -p HAL/Ack:int=0 -p HAL/Nack:int=0 -p HAL/Error:int=0 
    [naoqisim] Shared memory with identifier 'hal-ipc' already exists. Destroying and creating the shared memory
    [naoqisim] [I] 676 HAL: create sharedMemory : hal-ipc
    [naoqisim] [I] 676 xmlPreference::loadPreference: Load file /home/user/Desktop/Projeto_Natal/NAO/naoqisim-master/aldebaran/simulator-sdk/etc/hal/hal.xml
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/CycleTime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/Time in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/TargetCycleMinWait in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 8000
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/TargetCycleTime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 10
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/CycleTimeWarning in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 50
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/HeatLogPath in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: temperatureLog
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/I2Cpath in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: /dev/i2c-0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/Realtime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 1
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/RealtimePriority in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 60
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/hardnessMode in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: current_mode
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/CycleTime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Time in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/Simulation in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Robot/Type in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: Juliette
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Simulation in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Ack in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Nack in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Error in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/CycleTimeErrorCounter in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/CycleTimeErrorLastTime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0.000000
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/Error in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/CycleTimeErrorCounter in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/CycleTimeErrorLastTime in module Hal, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0.000000
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/CycleTime in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference DCM/Time in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Ack in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/CycleTime in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Error in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Nack in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/SimShmId in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 9559
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Simulation in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 1
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Time in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/Robot/Type in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: Nao
    [naoqisim] [I] 676 ModulePreference::add: Add preference HAL/ShmFile in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: hal-ipc
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: No previous BodyId. Force BodyId from bootloader
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: Use BodyId from bootloader
    [naoqisim] [E] 676 DeviceManager::specialIdsCase: No Module Body found
    [naoqisim] [3240820786] error  : usb: USB device not found
    [naoqisim] [E] 678 I2cThread: Unable to open /dev/i2c-head
    [naoqisim] [E] 678 I2cThread: Unable to open /dev/i2c-0
    [naoqisim] [3240820787] warning: halthread: can't setup realtime priority for I2C
    [naoqisim] [E] 676 xmlPreference::loadPreference: File Device_Local.xml not found
    [naoqisim] [I] 676 xLoadBufferFromChestBoard: loading prefs from chestboard.
    [naoqisim] [3240820787] warning: usb: Usb::BulkWrite: error: no device
    [naoqisim] [3240820787] warning: usb: Usb::BulkWrite: error: no device
    [naoqisim] [I] 676 xLoadBufferFromChestBoard: DCMSubPref : USB doRequest Failed
    [naoqisim] [I] 676 xmlPreference::loadPreference: Load file /media/internal/DeviceHeadInternalGeode.xml
    [naoqisim] [W] 676 Q7Eeprom::read: CGOS access not granted.
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/FullHeadId in module Head, value 
    [naoqisim] [I] 676 AttrGeneric::debug: ALDT*******0000
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/HeadId in module Head, value 
    [naoqisim] [I] 676 AttrGeneric::debug: ALDT*******0000
    [naoqisim] [I] 676 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
    [naoqisim] [I] 676 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
    [naoqisim] [I] 676 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: LowerBody (legs) will be configured for Maxxon motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
    [naoqisim] [I] 676 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: RobotConfig/Body/Device/RightArm/Version key not found check your config
    [naoqisim] [I] 676 InitNaoDevicesPlugin: UpperBody will be configured for Maxxon Motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: LowerBody (legs) will be configured for Maxxon motors
    [naoqisim] [I] 676 InitNaoDevicesPlugin: Left Hand motors will use maxons thermal model
    [naoqisim] [I] 676 InitNaoDevicesPlugin: Right Hand motors will use maxons thermal model
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: headIdKeyName : ALDT*******0000
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: fullHeadIdKeyName : ALDT*******0000
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: No previous BodyId. Force BodyId from bootloader
    [naoqisim] [I] 676 DeviceManager::specialIdsCase: Use BodyId from bootloader
    [naoqisim] [E] 676 DeviceManager::specialIdsCase: No BodyId from bootloader found
    [naoqisim] [E] 676 TestRobotVersionPlugin: No robot version
    [naoqisim] [I] 676 memberidentificationplugin: member identification on Nao
    [naoqisim] [I] 676 diagnosisPlugin: Board FaceBoard added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board EarLeds added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board InertialSensor added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board Battery added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board USBoard added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board ChestBoard added to the list
    [naoqisim] [I] 676 diagnosisPlugin: Board HeadBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board HeadBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board HeadBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board HeadBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board HeadBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftShoulderBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShoulderBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShoulderBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShoulderBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShoulderBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftArmBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftArmBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftArmBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftArmBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftArmBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftHandBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHandBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHandBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHandBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHandBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightShoulderBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShoulderBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShoulderBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShoulderBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShoulderBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightArmBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightArmBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightArmBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightArmBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightArmBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightHandBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHandBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHandBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHandBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHandBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightHipBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHipBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHipBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHipBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightHipBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightThighBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightThighBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightThighBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightThighBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightThighBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightShinBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShinBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShinBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShinBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightShinBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftHipBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHipBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHipBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHipBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftHipBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftThighBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftThighBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftThighBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftThighBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftThighBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftShinBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShinBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShinBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShinBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftShinBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board LeftFootBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftFootBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftFootBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftFootBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board LeftFootBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board RightFootBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board RightFootBoard : error 49 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightFootBoard : error 50 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightFootBoard : error 209 is only a warning, won't be logged
    [naoqisim] [W] 676 diagnosisPlugin: Board RightFootBoard : error 210 is only a warning, won't be logged
    [naoqisim] [I] 676 diagnosisPlugin: Board TouchBoard added to the list
    [naoqisim] [W] 676 diagnosisPlugin: Board Chest-Eeprom-80 : no log will be displayed
    [naoqisim] [W] 676 diagnosisPlugin: Board Chest-Eeprom-81 : no log will be displayed
    [naoqisim] [I] 676 diagnosisPlugin: Found 22 boards to log
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/HeadId in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 0000
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Device/Camera/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 2
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/BaseVersion in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: V5.0
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Device/TouchBoard/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 1
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Device/FaceBoard/Leds/Rotation in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 1
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/BaseVersion in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: V5.0
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/Hand/Left/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 7
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/Hand/Right/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 7
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/Foot/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 3
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/Legs/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 7
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/LeftArm/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 3
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Device/RightArm/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 3
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 5.0.0
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 5.0.0
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/Type in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: Nao
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Body/SoftwareRequirement in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 1.22.4
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Type in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: Nao
    [naoqisim] [I] 676 ModulePreference::add: Add preference Device/DeviceList/ChestBoard/BodyNickName in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: Nao0000
    [naoqisim] [I] 676 ModulePreference::add: Add preference Device/DeviceList/ChestBoard/BodyId in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 00000ALDR1008E000000
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Color in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: RedP185C
    [naoqisim] [I] 676 ModulePreference::add: Add preference RobotConfig/Head/Device/Micro/Version in module Local, value 
    [naoqisim] [I] 676 AttrGeneric::debug: 2
    [naoqisim] [E] 676 SimulationPlugin: SubDevice not found RHipYawPitch/Position/Sensor
    [naoqisim] [E] 676 SimulationPlugin: SubDevice not found RHipYawPitch/Position/Actuator
    [naoqisim] [3240820795] warning: halthread: can't setup realtime priority
    [naoqisim] [I] 676 DcmLostPlugin: Stiffness set to 0 due to DCM missing -- Leg
    [naoqisim] [I] 676 DcmLostPlugin: Stiffness set to 0 due to DCM missing -- Wheels
    [naoqisim] [W] 676 DcmLostPlugin: HAL stiffness decrease : HAL error set to 16
    [naoqisim] [I] 676 diagnosisPlugin: Comm lost (noCom)    on USBoard -- , ack 0, nack 0, no com. since 30000 ms
    [naoqisim] [W] 662 qimessaging.transportsocket: connect: Connection refused
    [naoqisim] [I] 659 SimLauncher: Launching ../../aldebaran/simulator-sdk/bin/naoqi-bin -p 9559 --writable-path /tmp/SimLauncherB0HZbEt 
    [naoqisim] [W] 661 qimessaging.transportsocket: connect: Connection refused
    [naoqisim] [I] 838 core.naoqi: ..::: starting NAOqi version 2.1.4 :::..
    [naoqisim] [I] 838 core.naoqi: Copyright (c) 2005-2013, Aldebaran Robotics
    [naoqisim] [I] 838 core.naoqi: Build tag: jenkins-release-2.1_simulator-sdk_linux64-13
    [naoqisim] [I] 838 qimessaging.servicedirectory: ServiceDirectory listener created on tcp://0.0.0.0:9559
    [naoqisim] [I] 838 qimessaging.transportserver: TransportServer will listen on: tcp://127.0.0.1:9559
    [naoqisim] [I] 838 qimessaging.transportserver: TransportServer will listen on: tcp://192.168.0.30:9559
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ServiceDirectory" (#1)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "LogManager" (#2)
    [naoqisim] [I] 838 core.lib.launcher: Loading "/home/user/Desktop/Projeto_Natal/NAO/naoqisim-master/aldebaran/simulator-sdk/etc/naoqi/autoload.ini"
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALFileManager" (#3)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALMemory" (#4)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALLogger" (#5)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALPreferences" (#6)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALLauncher" (#7)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALBonjour" (#8)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALServiceManager" (#9)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALDebug" (#10)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALPreferenceManager" (#11)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "DCM" (#12)
    [naoqisim] [I] 841 DCM.Thread: DcmThread connect to sharedMemory : hal-ipc
    [naoqisim] @@@@ Use relative clock @@@@
    [naoqisim] [W] 676 DcmLostPlugin: HAL stiffness decrease ended : HAL error back to 0 due to DCM start
    [naoqisim] [W] 676 ClientSyncPlugin: DCM detected
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALNotificationManager" (#13)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALResourceManager" (#14)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALRobotModel" (#15)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALSonar" (#16)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALFsr" (#17)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALSensors" (#18)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALBodyTemperature" (#19)
    [naoqisim] [W] 838 ALMotion.ALMotionConfigurator: DIAGNOSTIC_IS_OK: 1
    [naoqisim] [W] 838 ALMotion.ALMotionConfigurator: ENABLE_FOOT_CONTACT_PROTECTION: 1
    [naoqisim] [W] 838 ALMotion.ALMotionConfigurator: ENABLE_STIFFNESS_PROTECTION: 1
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALMotion" (#20)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALTouch" (#21)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALRobotPosture" (#22)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALRedBallTracker" (#23)
    [naoqisim] [W] 838 motion.balltracker: ALRedBallTracker is deprecated in version 1.16. Please use the module ALTracker instead.
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALMotionRecorder" (#24)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALLeds" (#25)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALWorldRepresentation" (#26)
    [naoqisim] [W] 838 packagemanager.sql.compat: Cannot check column install_time in packages
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "PackageManager" (#27)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALUserSession" (#28)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALAudioPlayer" (#29)
    [naoqisim] [W] 838 altts: Could not find plugin: aitalk
    [naoqisim] [W] 838 altts: Could not find plugin: acapela
    [naoqisim] [W] 838 altts: Could not find plugin: nuance
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALTextToSpeech" (#30)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALBattery" (#31)
    [naoqisim] [E] 838 behavior.ALFrameManager: ALPreferenceManager.getValue did not return a string, but returned: 
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALFrameManager" (#32)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALPythonBridge" (#33)
    [naoqisim] [I] 676 DcmLostPlugin: End decrease stiffness
    [naoqisim] [I] 838 python: ALPythonBridge: using naoqi from /home/user/Desktop/Projeto_Natal/NAO/naoqisim-master/aldebaran/simulator-sdk/lib/naoqi.pyc
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALVideoDevice" (#34)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALRedBallDetection" (#35)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALBehaviorManager" (#36)
    [naoqisim] [W] 838 audio.altexttospeech.main: enableNotifications() is now deprecated. 
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALAnimatedSpeech" (#37)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALColorBlobDetection" (#38)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALVisualSpaceHistory" (#39)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALTracker" (#55)
    [naoqisim] [W] 852 audio.DeviceManager: Could not find plugin: 
    [naoqisim] [E] 852 audio.DeviceManager: no suitable plugin found
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALModularity" (#56)
    "

- FROM naoqisim-master/controllers/nao/03_others/Singletons.cpp:

        m_launcher = new Sim::SimLauncher();
        // TODO: remove this case when Aldebaran release the fixed simulator-sdk
        // for Mac and Linux 64
        std::cout << "\n\t\t\t- m_launcher->launch(...)..." << std::flush;
        std::cout << "\n\t\t\t\t |" << std::flush;
        std::cout << "\n\t\t\t\t V\n" << std::flush;
        return m_launcher->launch(m_model, naoqi_port, sdk_prefix);

***THIRD ERROR***:

    "
    [naoqisim]      5.2 - void Nao::run() :
    [naoqisim]               |
    [naoqisim]               V
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALNavigation" (#57)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALMovementDetection" (#58)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALSegmentation3D" (#59)
    [naoqisim] [E] 838 modularity.private: Can't set data for source "FaceDetection_Status": source unknown.
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALPeoplePerception" (#60)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALSittingPeopleDetection" (#61)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALEngagementZones" (#62)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALGazeAnalysis" (#63)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALWavingDetection" (#64)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALCloseObjectDetection" (#65)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALFastPersonTracking" (#66)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALFindPersonHead" (#67)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALVisualCompass" (#68)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALLocalization" (#69)
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALPanoramaCompass" (#70)
    [naoqisim] [E] 838 Thinking: Error occurred during thinking while getting info of animation package animations:
    [naoqisim] Package animations does not exist in database.
    [naoqisim] [E] 838 UserSessionManager: Could not connect to either UserSession, BasicAwareness, or PeoplePerception. UserSessionManager will be inactive.
    [naoqisim] [W] 838 AutonomousLife: ALAutonomousMoves has not been found. Will not affect Autonomous Life.
    [naoqisim] [W] 838 AutonomousLife: ALBasicAwareness has not been found. Will run without advanced tracking and automatic user session.
    [naoqisim] [W] 838 AutonomousLife: ALDiagnosis has not been found. May not be able to properly enter safeguard state
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALAutonomousLife" (#77)
    [naoqisim] [I] 838 Dialog: Starting Dialog ...
    [naoqisim] [W] 838 Dialog: ALSpeechRecognition has not been found. Will run without voice recognition.
    [naoqisim] [I] 838 Dialog: Dialog will run in mode simulated
    [naoqisim] [W] 838 Dialog: AI client Module not found
    [naoqisim] [I] 838 Dialog.LongTermMemory: User database creation succeed
    [naoqisim] [I] 838 Dialog.preference: No dialog history management
    [naoqisim] [I] 838 Dialog.preference: AI system enabled
    [naoqisim] [I] 838 Dialog.preference: BNF confidence 0.5
    [naoqisim] [I] 838 Dialog.preference: REMOTE confidence 0.3
    [naoqisim] [I] 838 Dialog.preference: Serialization enabled
    [naoqisim] [I] 838 Dialog.preference: Upper SLM 1
    [naoqisim] [I] 838 Dialog.preference: Enable auto update
    [naoqisim] [I] 838 Dialog.preference: Push mode 2
    [naoqisim] [I] 838 Dialog.preference: Enable full speech recognition
    [naoqisim] [I] 838 Dialog.preference: Audio expression enabled
    [naoqisim] [I] 838 Dialog.preference: Smalldisplacement enabled
    [naoqisim] [I] 838 Dialog.preference: Breath enabled
    [naoqisim] [I] 838 Dialog.preference: No animated speech configuration
    [naoqisim] [I] 838 Dialog.preference: Default volume 0
    [naoqisim] [I] 838 Dialog.preference: No dialog history management
    [naoqisim] [I] 838 Dialog.preference: AI system enabled
    [naoqisim] [I] 838 Dialog.preference: BNF confidence 0.5
    [naoqisim] [I] 838 Dialog.preference: REMOTE confidence 0.3
    [naoqisim] [I] 838 Dialog.preference: Serialization enabled
    [naoqisim] [I] 838 Dialog.preference: Upper SLM 1
    [naoqisim] [I] 838 Dialog.preference: Enable auto update
    [naoqisim] [I] 838 Dialog.preference: Push mode 2
    [naoqisim] [I] 838 Dialog.preference: Enable full speech recognition
    [naoqisim] [I] 838 Dialog.preference: Audio expression enabled
    [naoqisim] [I] 838 Dialog.preference: Smalldisplacement enabled
    [naoqisim] [I] 838 Dialog.preference: Breath enabled
    [naoqisim] [I] 838 Dialog.preference: No animated speech configuration
    [naoqisim] [I] 838 Dialog.preference: Default volume 0
    [naoqisim] [I] 838 qimessaging.servicedirectory: Registered Service "ALDialog" (#78)
    [naoqisim] [I] 838 core.naoqi: NAOqi is ready...
    "

- FROM naoqisim-master/controllers/nao/Nao.cpp:

        void Nao::run()
        {
            ...
            // Main loop
            while (robot->step(time_step) != -1) {
                __check_real_time();
                for (auto i : m_devices)
                    i->update();
            }
            ...
        }

***I see all those logs are related to:***

- 2 lines in Singletons.cpp -> bool Singletons::initialize(...) :

        m_model = new Sim::Model(wbu_system_short_path(path_to_model.c_str()));

        return m_launcher->launch(m_model, naoqi_port, sdk_prefix);

- 1 loop in Nao.cpp -> void Nao::run():

        while (robot->step(time_step) != -1) {
            __check_real_time();
            for (auto i : m_devices)
                i->update();
        }

Are those code lines intrisically related to the communication with naoqi-sdk. Is it so?
