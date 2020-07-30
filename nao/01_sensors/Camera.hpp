// Description: Class that simulates one camera of the robot

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../../common_library.hpp"

// Webots library
#include <webots/camera.h>

// Written to this controller
// Others
#include "../03_others/Image.hpp"

namespace Sim {
    class CameraSensor;
};

class Camera : public Device
{
    private:
        WbDeviceTag m_tag;
        const CameraSensor *m_sensor;
        int m_width, m_height;

    public:
        Camera(const CameraSensor *m_sensor, int time_step);
        virtual ~Camera();

        virtual void update();
};

#endif
