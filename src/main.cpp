#include <hailo/hailort.hpp>
#include <iostream>

int main()
{
    auto dev = hailort::Device::scan().expect("Failed getting a device");
    std::cout << dev.size() << std::endl;

    return 0;
}