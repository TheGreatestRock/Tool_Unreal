cmake_minimum_required(VERSION 3.30.2)
project(UnrealPackagingTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add all source files
add_executable(UnrealPackagingTool
    Tool_Unreal.cpp
    src/show_info.cpp
    src/build.cpp
    src/package.cpp
    src/help.cpp
)
