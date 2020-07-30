FIRST REFACTORING*: 30 July 2020 (Age of Corona)
    
BY: Fernando Zuher, São Paulo, Brazil

LAST EDITION: 30 July 2020.

*FROM: https://github.com/cyberbotics/naoqisim

TESTED ON:

    - Ubuntu 18.04.4

    - Webots R2020a revision 1

    - Choregraphe Version 2.8.6.23

It follows a summary of the refactoring:

    --------------
    From C to C++
        C code, inside the source code (C++ files), was translated to C++ whenever possible. It's better practice to avoid C in C++ files.

        In some methods it was not possible to translate because of some "undefined reference". Example:
            wb_camera_enable(m_tag, 5 * time_step) // camera.h

        I need more time to understand some of those particular interdependences.

    ------
    C++17
        Now part of the code uses C++17. Compilation just works with C++17 mode activated (make). A simple example used from C++17:        
            vector variable_name = new T; // Deduced vector type based on the called constructor.

    -----------
    OS support
        Removed all the Windows/OSX support in order to improve the readability and understand better the code. Now it just works with Linux (I tested on Ubuntu 18.04.4).

        When the controller is done to the last naoqi-sdk version, I may support the other OSs.

    ---------
    Makefile
        Edited to:
            - accept C++ webots libs aside C ones;
            - C++17 support;
            - compile C++ source code in subfolders;
            - removed support to Windows (just for a while ;-)

    ------------
    Compilation
        All warning logs during compilation (make) were solved. Now it compiles like a charm: without any ugliness.

    --------------
    Old naoqi-sdk
        I removed "boost" folder from "naoqisim-master/aldebaran/simulator-sdk/include" because it is outdated and in conflict with "boost C++ library" from my compiler (GNU Compiler Collection). It was causing warnings during "make".

    ------------------------
    camelCase -> snake_case
        Changed the camelCase style to snake_case whenever possible.

    ------------------------------------
    Controller source code organization

    The previous directory of the source code included all the naoqisim controller files in only one folder (naoqisim-master/controllers/naoqisim). The new directory is structured as:

        - build: .o and .d intermediate files generated during compilation.

        - common_library.hpp : Containing a list of header files and namespaces commonly used among the controler's files. This aims avoid repetition of "#include"s in most of the files.

        - Makefile: Used to compile the code with the command "make" typed in terminal.

        - nao: Source code about the implementation of an abstract NAO.
            
            - Nao.hpp / Nao.cpp: Initialize all code related to this abstraction (note: "abstract" here doesn't mean an "Abstract class").
                
            // Subfolders being included in NAO.hpp
            - 01_sensors: Files about NAO sensors.
            - 02_actuators: Files about NAO actuators.
            - 03_others: Other files not related to a particular set, but necessary to the whole stuff.
            
        - naoqisim.cpp : main controller
        - naoqisim.hpp : main controller
        - runtime.ini : Just for Makefile


There are things I need to understand better:
(Writting...)

    What is it for?
        File "Singletons.hpp" doesn't define: static void dump_model();


TO DO:

    - Replace some included C Webots libraries for theirs C++ ones. For example: <webots/robot.h>, <webots/camera.h>... -> <webots/Robot.hpp>, <webots/Camera.hpp>
        It's better practice to avoid C code in C++ whenever possible.
    
    - Handle the warnings and erros logs in Webots Console when the controller starts.

    - Replace naoqisim-master/aldebaran/simulator-sdk for the last version of naoqi-sdk.
        - Then edit the controller source code to fit with such updated naoqi-sdk

