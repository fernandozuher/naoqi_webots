#ifndef ALNAOSIM_CAMERA_DEFINITIONS_H
#define ALNAOSIM_CAMERA_DEFINITIONS_H

namespace Sim {

/// \enum Different resolutions supported by cameras
enum CameraResolution
{
  RES_80_60,
  RES_160_120,
  RES_320_240,
  RES_640_480,
  RES_1280_960,
  RES_UNKNOWN
};

/// \enum Different color spaces supported by cameras
enum CameraColorSpace
{
  COL_SPACE_RGB, /// each buffer element is three bits long, one for each color
  COL_SPACE_DEPTH, ///  each buffer element is a depth given in meters
  COL_SPACE_UNKNOWN
};

} // ends namespace Sim

#endif // ALNAOSIM_CAMERA_DEFINITIONS_H
