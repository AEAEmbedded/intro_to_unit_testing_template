cmake_minimum_required(VERSION 3.16)
project(intro_unit_testing_exercise_2 C CXX)

# 0. Look into the option syntax
option(UNIT_TEST "Enable unit_testing otherwise build as standalone library" TRUE)

# 1. Add library that has the bit_manipulation sources


# 2. add include directories for library


# Conditionally check whether we are unit-testing
if(${UNIT_TEST})
    # 3. Enable unit-testing in cmake (see enable_testing())
  
    # 4. Automatically get and include the Catch2 framework into build, look into FetchContent

    # 5. Add target which builds your basic_test.cpp

    # 6. Link your target with Catch2


    # 7. Make the test discoverable by CTest, see: https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top

else()
    # 8. Add target for the example

    # 9. Link the example target with appropriate libraries

endif()