if(COMMAND idf_component_register)
    # ---- ESP-IDF build ----
    idf_component_register(
        SRCS "src/bit_manipulation.cpp"
        INCLUDE_DIRS "include"    
    )
else()
    # ---- Host / manual CMake build ----
    include(FetchContent)

    FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG         v3.8.1   # or latest stable
    )

    FetchContent_MakeAvailable(catch2)
    add_executable(test_host test/test_host/test_host.cpp)
    target_include_directories(test_host PUBLIC include)
    target_link_libraries(test_host PRIVATE Catch2::Catch2WithMain)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(CTest)
    include(Catch)
    catch_discover_tests(test_host)
endif()
