cmake_minimum_required(VERSION 3.0.0)

include(FetchContent)
FetchContent_Declare(
  OpenCV
  GIT_REPOSITORY https://github.com/opencv/opencv.git
  GIT_TAG        master
  GIT_SHALLOW    True
)
find_package(OpenCV)

if(NOT OpenCV_FOUND)
    # If not found, fetch and build it
    FetchContent_MakeAvailable(OpenCV)
endif()