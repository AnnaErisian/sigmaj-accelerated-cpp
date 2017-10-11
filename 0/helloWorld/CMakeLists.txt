CMake_minimum_required(VERSION 2.6)
project(HelloWorld)

#Set the version number
set (HelloWorld_VERSION_MAJOR 0)
set (HelloWorld_VERSION_MINOR 1)

#Configures a header file to pass some info to the program
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

#Apparently the header is a binary?  THat's odd vocabulary
include_directories("${PROJECT_BINARY_DIR}")

add_executable(HelloWorld hw.cpp)
