cmake_minimum_required(VERSION 3.23)
project(lab07_composite)

set(CMAKE_CXX_STANDARD 20)

# googletest:begin
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# googletest:end

# boost:start
#find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
# boost:end

# app:start
add_executable(
        lab07_composite
        src/main.cpp
)
#target_link_libraries(lab06_adapter LINK_PUBLIC ${Boost_LIBRARIES})
# app:end

# unit_tests:start
#add_executable(
#        lab07_composite_test
#)
#target_link_libraries(lab06_adapter_test LINK_PUBLIC gtest gtest_main gmock ${Boost_LIBRARIES})
#target_link_libraries(lab06_adapter_test LINK_PUBLIC gtest gtest_main gmock)
# unit_tests:end