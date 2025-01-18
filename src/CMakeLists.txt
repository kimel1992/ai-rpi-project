cmake_minimum_required(VERSION 3.0.0)

find_package(HailoRT REQUIRED) # TODO: Replace with FetchContent
find_package(OpenCV REQUIRED COMPONENTS core imgproc video) # TODO: Replace with FetchContent

set(SOURCE_FILES main.cpp)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main PRIVATE
    HailoRT::libhailort
    opencv_core
    opencv_imgproc
    opencv_video)