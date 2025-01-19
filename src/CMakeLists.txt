cmake_minimum_required(VERSION 3.0.0)

include(${PROJECT_SOURCE_DIR}/cmake/hailort.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/opencv.cmake)

set(SOURCE_FILES ${SOURCE_FILES} main.cpp)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main PRIVATE
    HailoRT::libhailort
    ${OpenCV_LIBS}
)