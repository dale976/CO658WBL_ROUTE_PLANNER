# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add include directories for your project headers
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add a testing executable
add_executable(runUnitTests stack_test.cpp)  # Replace with your test files

# Link GTest to your test executable
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)

# Register test
add_test(NAME unit_tests COMMAND runUnitTests)