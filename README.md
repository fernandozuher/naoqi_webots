![Logo of the project](https://github.com/fernandozuher/naoqi_webots/blob/master/readme_images/logo.png)
 
# naoqi_webots
 
... This repository is a refactored version of the controller (Webots terminology) named *naoqisim*: https://github.com/cyberbotics/naoqisim

It aims to solve bugs and outdated pieces of code of the deprecated naoqi-c++-sdk used in it.

It works as a middleware allowing that Choregraphe and any code using "naoqi SDK SoftBank Robotics" be used with the simulated robot NAO in Webots.

## Getting started

### Dependences

It was tested on:
* Ubuntu 18.04.4
* Webots R2020a revision 1
* Choregraphe Version 2.8.6.23

...but it is supposed to work in later versions too:

#### Operating System: Linux.
This refactored version works only on Linux. The support for Windows and OSX were temporarily removed in order to improve readability and maintenance of the code.

#### Compiler: Standard gcc compiler suite.

#### Choregraphe: https://developer.softbankrobotics.com/nao6/downloads/nao6-downloads-linux

#### Webots: https://cyberbotics.com/
Set the WEBOTS_HOME environment variable to point to the Webots installation folder, as documented in the Webots user guide.

The last version of Webots (R2020b in August 2020) has a model of NAOv5. NAOv6 is not supported. So you should use v5 in Choregraphe too.

### Build

Download this repository, unpack it in a preferred working directory.

(Linux) Add WEBOTS_HOME/lib to your library path (e.g. export LD_LIBRARY_PATH=$WEBOTS_HOME/lib). To compile the naoqi_webots controller, type "make" in the controllers/naoqi_webots folder.

Start Webots, open the naoqi_webots/worlds/naoqi_webots.wbt world file.

Start Choregraphe. Choose Connection > Connect to or click the "Connect to" button. Click the "Wake Up" button (sun-like icon on the top right corner of the Choregraphe window) to make sure the stiffness is on.


## How to use
 
Here will be the images and descriptions. Principal content.
 

The controller:
1. Initializes naoqi process located in the folder "old_aldebaran_cplusplus_sdk".
2. Initializes Webots simulation.
3. Creates an abstract robot NAO that is connected to *naoqi* and *Webots*.
 
## Features
 
1. Program robot NAO using a standard SDK developed by its current developer SoftBank Robotics.
2. Use the robot in a well known robotic simulator, Webots.
    - Save time and your robot of falling by researching in a simulator.

 
## Links
 
  - Repository: https://github.com/fernandozuher/naoqi_webots
    - In case of sensitive bugs like security vulnerabilities, please contact
      fernando.zuher@gmail.com directly instead of using issue tracker. We value your effort to improve the security and privacy of this project!
 
 
## Versioning
 
beta-0.1
 
 
## Authors
 
* **Fernando Zuher**: @fernandozuher (https://github.com/fernandozuher)
 
Please follow github and join us!
Thanks to visiting me and good coding!
