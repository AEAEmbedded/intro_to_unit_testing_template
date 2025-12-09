# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

if(DEFINED ENV{IDF_PATH})
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
# "Trim" the build. Include the minimal set of components, main, and anything it depends on.
idf_build_set_property(MINIMAL_BUILD ON)
set(TEST_COMPONENTS bit_operation)
project(hello_world)
else()
project(hello_world C CXX)
enable_testing()
add_subdirectory(components/bit_operation)
endif()


