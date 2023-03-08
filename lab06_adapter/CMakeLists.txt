cmake_minimum_required(VERSION 3.23)
project(lab06_adapter)

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
        lab06_adapter
        src/main.cpp
        src/lib/graphics_lib/graphics_lib.h
        src/lib/modern_graphics_lib/modern_graphics_lib.h
        src/lib/shape_drawing_lib/shape_drawing_lib.h
        src/app/app.h
)
target_link_libraries(lab06_adapter LINK_PUBLIC ${Boost_LIBRARIES})
# app:end

# unit_tests:start
add_executable(
        lab06_adapter_test
        src/lib/graphics_lib/graphics_lib.h
        src/lib/modern_graphics_lib/modern_graphics_lib.h
        test/unit/lib/graphics_lib/CanvasTest.cpp
        test/unit/lib/modern_graphics_lib/CModernGraphicsRendererTest.cpp
)
target_link_libraries(lab06_adapter_test LINK_PUBLIC gtest gtest_main gmock ${Boost_LIBRARIES})
# unit_tests:end