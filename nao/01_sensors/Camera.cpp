#include "Camera.hpp"

Camera::Camera(const CameraSensor *sensor, int time_step) :
               Device(sensor->name()), m_sensor {sensor}
{
    cout << "simulator-sdk max camera resolution: " << name() << ": " <<
            sensor->width() << "x" << sensor->height() << "\n";

    m_tag = wb_robot_get_device(name().c_str());
    if (!m_tag) {
        cerr << "Webots Camera not found for Sim::CameraSensor: " << name()
             << "\n";
        return;
    }

    // Enable Webots camera
    wb_camera_enable(m_tag, 5 * time_step);

    // Width and height of Webots camera images
    m_width = wb_camera_get_width(m_tag);
    m_height = wb_camera_get_height(m_tag);
    cout << "Webots camera resolution: " << name() << ": " << m_width << "x"
         << m_height << "\n";
}

void Camera::update()
{
    if (!m_tag)
        return;

    // find out the width and height expected by the HAL
    int buffer_size {}, width {}, height {};
    Singletons::hal()->cameraBufferSize(m_sensor, &buffer_size, &width, &height);
    if (!buffer_size || !width || !height)
        return;

    auto camera_resolution = Singletons::hal()->cameraResolution(m_sensor);
    auto camera_color_space = Singletons::hal()->cameraColorSpace(m_sensor);
    
    // Create image with Webots camera dimensions
    Image image(m_width, m_height, wb_camera_get_image(m_tag));

    // rescale Webots image to HAL image dimensions change format to RGB
    image.convert(width, height);

    // update HAL
    if (!Singletons::hal()->sendCameraSensorValue(m_sensor,
        (unsigned char *)image.data(), camera_resolution, camera_color_space))
            cerr << "Sim::HALInterface::sendCameraSensorValue() failed.\n";
}

Camera::~Camera() { }