## Copyright (c) 2012-2015 Aldebaran Robotics. All rights reserved.
## Use of this source code is governed by a BSD-style license that can be
## found in the COPYING file.

###############################################
# Auto-generated file.                        #
# Do not edit                                 #
# This file is part of the qiBuild project    #
###############################################

set(BOOTSTRAP_VERSION 6)

#we use t00lchain, when we have a toolchain_file and t00chain_dir is set
if (CMAKE_TOOLCHAIN_FILE AND TOOLCHAIN_DIR)
  set(T001CHAIN_DIR ${TOOLCHAIN_DIR} CACHE PATH "" FORCE)
  include("${T001CHAIN_DIR}/cmake/general.cmake")
  return()
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/qibuild.cmake)
  set(QI_T001CHAIN_COMPAT   ON   CACHE INTERNAL "" FORCE)
  set(QI_WARN_DEPRECATED    OFF  CACHE INTERNAL "" FORCE)
  include(${CMAKE_CURRENT_SOURCE_DIR}/qibuild.cmake)
endif()
