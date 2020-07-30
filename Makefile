space :=
space +=

# Compile .cpp in subdirectories as well
WEBOTS_HOME_PATH=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))

CXX_SOURCES := $(shell find . -name "*.cpp")

ifndef WEBOTS_NAOSIM_PATH
	WEBOTS_NAOSIM_PATH = ../../aldebaran/simulator-sdk
endif

# --------------------------C/C++ Options--------------------------

# Add include path from Aldebaran's simulation-sdk:
INCLUDE = -I"$(WEBOTS_NAOSIM_PATH)/include"

# Add libraries from Aldebaran's simulation-sdk:
# it is simpler to configure LD_LIBRARY_PATH rather than enumerating all libraries
LIBRARIES = -L"$(WEBOTS_NAOSIM_PATH)/lib" -Wl,-rpath,"$(WEBOTS_NAOSIM_PATH)/lib" -lalnaosim -lalrobotmodel -lqi -lalsimutils

include $(WEBOTS_HOME_PATH)/resources/Makefile.os.include

CFLAGS += -std=c++1z #C++17
CFLAGS += -D_GLIBCXX_USE_CXX11_ABI=0 # Ensure ABI compliance using GCC 5

INCLUDE += -I"$(WEBOTS_HOME)/include/controller/cpp"
DYNAMIC_LIBRARIES += -lCppController

USE_C_API = true # Use Webots C API

# This will can be dropped when Aldebaran will compile its libraries using
# libc++ (default in Mavericks 10.9)
USE_STD_CXX = true

# Do not modify: this includes Webots global Makefile.include
include $(WEBOTS_HOME_PATH)/resources/Makefile.include
