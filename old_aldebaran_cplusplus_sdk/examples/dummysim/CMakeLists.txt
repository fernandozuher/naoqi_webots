cmake_minimum_required(VERSION 2.6.4)
project(dummysim)
find_package(qibuild)

qi_create_bin(dummysim
  NO_INSTALL
  dummysim.cpp
)

qi_use_lib(dummysim ALNAOSIM ALSIMUTILS)
