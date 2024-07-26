cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(MyProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the headers directory to the include path
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add the source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add the executable
add_executable(ROUTE_PLANNER ${SOURCES})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link GTest to the test target
target_link_libraries(ROUTE_PLANNER ${GTEST_LIBRARIES} pthread)

# Add tests subdirectory
add_subdirectory(tests)