cmake_minimum_required(VERSION 3.0.0)

include(${PROJECT_SOURCE_DIR}/cmake/hailort.cmake)


add_subdirectory(frames)

set(SOURCE_FILES ${SOURCE_FILES} main.cpp)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main PRIVATE
    # For AI
    HailoRT::libhailort
    
    # For frames
    frames
)