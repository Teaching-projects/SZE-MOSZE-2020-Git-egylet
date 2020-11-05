cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test
# and the GTest and pthread library
add_library(functions ../Monster.cpp ../JSON.cpp)
add_executable(runTests unit_tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread functions)
target_compile_features(runTests PRIVATE cxx_std_17)
set_property(TARGET unit_tests.cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET unit_tests.cpp PROPERTY CXX_STANDARD_REQUIRED ON)

