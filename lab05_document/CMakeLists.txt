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
        src/lib/document/render/IRenderer.h
        src/lib/document/node/INode.h
        src/lib/document/node/CImageNode.h
        src/lib/document/node/CImageNode.cpp
        src/lib/document/node/CParagraphNode.h
        src/lib/document/render/CListRenderer.h
        src/lib/file/CPath.h
        src/lib/document/node/CImageNode.cpp
        src/lib/document/node/CParagraphNode.cpp
        src/lib/document/render/CListRenderer.cpp
        src/lib/document/IDocument.h
        src/lib/document/CHtmlDocument.h
        src/lib/file/IFileStorage.h
        src/lib/file/CFileSystemFileStorage.h
        src/lib/random/Random.h
        src/lib/document/render/CHtmlRenderer.cpp
        src/lib/document/render/CHtmlRenderer.h
)

add_executable(
        lab05_document_test
        src/lib/document/render/IRenderer.h
        src/lib/document/node/INode.h
        src/lib/document/node/CImageNode.h
        src/lib/document/node/CImageNode.cpp
        src/lib/document/node/CParagraphNode.h
        src/lib/document/render/CListRenderer.h
        src/lib/file/CPath.h
        src/lib/document/node/CImageNode.cpp
        src/lib/document/node/CParagraphNode.cpp
        src/lib/document/render/CListRenderer.cpp
        src/lib/document/IDocument.h
        src/lib/document/CHtmlDocument.h
        src/lib/file/IFileStorage.h
        src/lib/file/CFileSystemFileStorage.h
        src/lib/random/Random.h
        src/lib/document/render/CHtmlRenderer.cpp
        src/lib/document/render/CHtmlRenderer.h

        test/lib/document/render/CListRendererTest.cpp
        test/lib/document/render/CHtmlRendererTest.cpp
        test/lib/document/CHtmlDocumentTest.cpp
        test/lib/file/CPathTest.cpp
        test/lib/file/MockFileStorage.cpp
        test/lib/random/RandomTest.cpp
)

target_link_libraries(lab05_document_test gtest gtest_main gmock)