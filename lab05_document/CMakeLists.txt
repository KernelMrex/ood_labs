cmake_minimum_required(VERSION 3.23)
project(lab05_document)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
        lab05_document
        src/main.cpp
        src/lib/IRenderer.h
        src/lib/INode.h
        src/lib/CImageNode.h
        src/lib/CImageNode.cpp
        src/lib/CParagraphNode.h
        src/lib/CListRenderer.h
        src/lib/CPath.h
        src/lib/CImageNode.cpp
        src/lib/CParagraphNode.cpp
        src/lib/CListRenderer.cpp
)

add_executable(
        lab05_document_test
        src/lib/IRenderer.h
        src/lib/INode.h
        src/lib/CImageNode.h
        src/lib/CImageNode.cpp
        src/lib/CParagraphNode.h
        src/lib/CListRenderer.h
        src/lib/CPath.h
        src/lib/CImageNode.cpp
        src/lib/CParagraphNode.cpp
        src/lib/CListRenderer.cpp

        test/lib/CListRendererTest.cpp
)

target_link_libraries(lab05_document_test gtest gtest_main gmock)