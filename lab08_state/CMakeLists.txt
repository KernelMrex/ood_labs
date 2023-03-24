cmake_minimum_required(VERSION 3.23)
project(lab08_state)

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
find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
# boost:end

# app:start
add_executable(
        lab08_state
        src/main.cpp
        src/app/gum_ball_machine_with_state/IState.h
        src/app/gum_ball_machine_with_state/IGumballMachine.h
        src/app/gum_ball_machine_with_state/CGumballMachine.h
        src/app/gum_ball_machine_with_state/state/CSoldState.h
        src/app/gum_ball_machine_with_state/state/CSoldOutState.h
        src/app/gum_ball_machine_with_state/state/CHasQuarterState.h
        src/app/gum_ball_machine_with_state/state/CNoQuarterState.h
)
target_link_libraries(lab08_state LINK_PUBLIC ${Boost_LIBRARIES})
# app:end

# unit_tests:start
add_executable(
        lab08_state_test
        src/app/gum_ball_machine_with_state/IState.h
        src/app/gum_ball_machine_with_state/IGumballMachine.h
        src/app/gum_ball_machine_with_state/CGumballMachine.h
        src/app/gum_ball_machine_with_state/state/CSoldState.h
        src/app/gum_ball_machine_with_state/state/CSoldOutState.h
        src/app/gum_ball_machine_with_state/state/CHasQuarterState.h
        src/app/gum_ball_machine_with_state/state/CNoQuarterState.h
)
target_link_libraries(lab08_state_test LINK_PUBLIC gtest gtest_main gmock ${Boost_LIBRARIES})
# unit_tests:end