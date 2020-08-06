// Description: Abstract base class for all simulated devices in this project

#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "../../common_library.hpp"

class Device
{
    private:
        std::string m_name;
    
    public:
        Device(const std::string &name) : m_name {name} {}
        virtual ~Device() {}

        // Device name as in HAL
        const std::string& name() const { return m_name; }

        // Update the device: Webots -> HAL and HAL -> Webots
        virtual void update() = 0;
};

#endif
