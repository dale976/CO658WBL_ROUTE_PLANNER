cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the headers directory to the include path
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add the source files
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

# Add the executable
add_executable(ROUTE_PLANNER ${SOURCES})