cmake_minimum_required(VERSION 3.0.0)

include(FetchContent)
FetchContent_Declare(
  HailoRT
  GIT_REPOSITORY https://github.com/hailo-ai/hailort.git
  GIT_TAG        master
  GIT_SHALLOW    True
)
find_package(HailoRT)

if(NOT HailoRT_FOUND)
    # If not found, fetch and build it
    FetchContent_MakeAvailable(HailoRT)
    add_library(HailoRT::libhailort ALIAS libhailort)
endif()