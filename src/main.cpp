#include <hailo/hailort.hpp>

#include <iostream>

#include "frames/get_frames.hpp"

int main()
{
    auto dev = hailort::Device::scan().expect("Failed getting a device");
    std::cout << dev.size() << std::endl;

    auto cam = CameraCapture();

    return 0;
}