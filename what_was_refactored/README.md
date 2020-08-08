# Refactoring
##  FIRST REFACTORING: 30 July 2020 (Age of Corona)
- From *naoqisim*: https://github.com/cyberbotics/naoqisim

It follows a summary of the refactoring:

## From C to C++

C code, inside the source code (C++ files), was translated to C++ whenever possible. It's a good practice to avoid C in C++ files. Examples:
- = -> {} list-initializer
- ~~primitive types~~ -> auto (without {} list-initializer)
- ~~NULL~~ -> nullptr
- ~~traditional array~~ -> std::vector
- ~~malloc~~ -> new
- ~~traditional for-loop~~ -> range-based for-loop
- ~~"using 'namespace' X"~~ -> X::
- ...

It was not possible to translate some functions because of weird "undefined reference". For example:

```c++
std::string robot_model = wb_robot_get_model(); // from <webots/camera.h> works

// std::string robot_model = robot->getModel(); // from <webots/Robot.hpp> doesn't work
```

**Error**:
```shell
... # linking naoqi_webots
build/release/naoqi_webots.o: In function `naoqi_webots::__init_webots_stuff()':
naoqi_webots.cpp:(.text+0xb8): undefined reference to `webots::Robot::getModel() const'
collect2: error: ld returned 1 exit status
/usr/local/webots/resources/Makefile.include:483: recipe for target 'build/release/naoqi_webots' failed
make: *** [build/release/naoqi_webots] Error 1
```

I tried this: https://www.softwaretestinghelp.com/cpp-errors/

And this: https://stackoverflow.com/questions/12573816/what-is-an-undefined-reference-unresolved-external-symbol-error-and-how-do-i-fix

...but without success. It might be a not well written Makefile or another obscure thing...

## C++17

Now part of the code uses C++17. Compilation just works with C++17 mode activated (make). A simple example used from C++17:

```cpp
#include <vector>
std::vector variable_name = new T; // Deduced vector type based on the called constructor.
```

## OS support

Removed all the Windows/OSX support in order to improve the readability and to understand better the code. Now it just works with Linux (I tested on Ubuntu 18.04.4).

When the controller is done to the last naoqi-sdk version, I may support the other OSs.

## Makefile

Edited to:
- Accept C++ Webots libs aside C ones;
- C++17 support;
- Compile C++ source code in subfolders;
- Support only Linux (just for a while ;-)

## Old naoqi-sdk

I removed "boost" folder from "naoqi_webots-master/old_aldebaran_cplusplus_sdk/include" because it is outdated and in conflict with "boost C++ library" from my compiler (GNU Compiler Collection). It was causing warnings during compilation (make).

## Compilation

All warning logs during compilation (make) were solved. Now it compiles like a charm: without any ugliness.

## naoqi_webots.wbt

From the "Webots world" naoqi_webots-master/worlds/naoqi_webots.wbt, I removed:

```    
removed PointLight {
  ambientIntensity 1
  intensity 0.6
  location 2 0.9 0
}
```

...because it was written for Webots 2018. In the recent versions that code generates a warning in the Webots console:

```shell
WARNING: PointLight: A quadratic 'attenuation' should be preferred to have a realistic simulation of light. Only the third component of the 'attenuation' field should be greater than 0.
```

## Webots console

I formated the log of the running-controller displayed in the "Webots console" window. That helped me to identify 3 error spots inside the controller. Look the file [error_log.md](../blob/master/what_was_refactored/error_log.md) in this directory.

## camelCase -> snake_case

Changed the camelCase style to snake_case whenever possible.

## Controller source code organization

The previous directory of the source code included all the naoqi_webots controller files in only one folder (naoqi_webots-master/controllers/naoqi_webots). The new directory is structured as:

- common_library.hpp : Containing a list of header files and namespaces commonly used among the controler's files. This aims avoid repetition of "#include"s in most of the files.

- naoqi_webots.hpp : main controller

- naoqi_webots.cpp : main controller

- nao: Directory about source code of an abstract NAO implementation (note: "abstract" here doesn't mean an "Abstract class").
    
    - Nao.hpp / Nao.cpp: Initialize all code related to this abstraction.    
    - 01_sensors: Files about NAO sensors included in NAO.hpp.
    - 02_actuators: Files about NAO actuators included in NAO.hpp.
    - 03_others: Other files not related to a particular category, but necessary to the whole controller.
    
- Makefile: Used to compile the code with the command "make" typed in terminal.

- runtime.ini : Just for Makefile

## TO DO:

- Replace some included C Webots libraries for theirs C++ ones. For example:

    ```c++
    <webots/robot.h>, <webots/camera.h>... -> <webots/Robot.hpp>, <webots/Camera.hpp>
    ```

    It's a good practice to avoid C code in C++ whenever possible.

- Handle the warnings and erros logs in Webots Console when the controller starts.

- Replace naoqi_webots-master/old_aldebaran_cplusplus_sdk for the last version of naoqi-sdk.
    - Then edit the controller source code to fit with such updated naoqi-sdk.

