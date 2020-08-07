## Copyright (C) 2011 Aldebaran Robotics

# Toolchain file to be passed to cmake, using:
# cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/sdk/toolchain-pc.cmake
# (or the "use a toolchain file" option from the cmake-gui)

# Warning ! This file is NOT usable for cross-compilation

# Set _SDK_ROOT_DIR to the dirname of this file (/path/to/sdk)
get_filename_component(_SDK_ROOT_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)

# Librairies are looked for in /path/to/sdk/lib,
# headers in /path/to/sdk/include, and so on.
set(qibuild_DIR "${_SDK_ROOT_DIR}/share/cmake/qibuild" CACHE INTERNAL "" FORCE)
find_package(qibuild)

# Enable backward compatibility:
set(TOOLCHAIN_DIR "" CACHE INTERNAL "" FORCE)
set(T001CHAIN_DIR "${_SDK_ROOT_DIR}/share/cmake/qibuild/compat/t001chain/" CACHE INTERNAL "" FORCE)
include(qibuild/compat/compat)
set(QI_WARN_DEPRECATED OFF CACHE INTERNAL "" FORCE)

# By default, generate output of the compilation in this SDK.
# This is useful for naoqi to find the module you've just compiled
set(QI_SDK_DIR "${_SDK_ROOT_DIR}" CACHE INTERNAL "" FORCE)
