# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Force target ONLY if not already defined


if(DEFINED ENV{IDF_PATH})
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(TEST_COMPONENTS bit_operation)
project(hello_world)
else()
project(hello_world C CXX)
enable_testing()
add_subdirectory(components/bit_operation)
endif()


