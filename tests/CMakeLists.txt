cmake_minimum_required(VERSION 2.6)

project(SZE-MOSZE-2020-Git-egylet)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link runTests with what we want to test
# and the GTest and pthread library
add_library(functions ../Monster.cpp ../JSON.cpp)
add_executable(runTests unit_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread functions)

