
cmake_minimum_required(VERSION 3.1)

set(project_name ci) ## rename your project here

project(${project_name} VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

## add executables

add_executable(${project_name} src/main.cpp)


