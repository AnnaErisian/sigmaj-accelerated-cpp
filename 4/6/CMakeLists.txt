cmake_minimum_required(VERSION 2.6)
project(Grader)
add_executable(Grader grader.cpp grade.cpp median.cpp student_info.cpp)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
