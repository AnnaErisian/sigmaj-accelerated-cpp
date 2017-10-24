cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_STANDARD 11)
project(Grader)
add_executable(Grader grader.cpp grade.cpp median.cpp student_info.cpp)
