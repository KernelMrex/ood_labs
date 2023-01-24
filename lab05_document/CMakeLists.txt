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
        src/lib/document/node/INodeVisitor.h
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
        src/lib/command/ICommand.h
        src/lib/command/CInsertParagraphCommand.h
        src/lib/command/CInsertImageCommand.h
        src/lib/CApp.h
        src/lib/command/ICommandFactory.h
        src/lib/command/CDocumentCommandFactory.h
        src/lib/utils/Strings.h
        src/lib/command/CDeleteNodeCommand.h
        src/lib/command/CSaveCommand.h
        src/lib/command/CSetTitleCommand.h
        src/lib/command/CListCommand.h
        src/lib/command/CHelpCommand.h
        src/lib/command/ICommandHistory.h
        src/lib/command/CCommandHistory.h
        src/lib/command/CUndoCommand.h
        src/lib/document/node/NodeType.h
        src/lib/command/CSaveToHistoryCommandDecorator.h)

add_executable(
        lab05_document_test
        src/lib/document/node/INodeVisitor.h
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
        src/lib/command/ICommand.h
        src/lib/command/CInsertParagraphCommand.h
        src/lib/command/CInsertImageCommand.h
        src/lib/command/ICommandFactory.h
        src/lib/command/CDocumentCommandFactory.h
        src/lib/utils/Strings.h
        src/lib/command/CDeleteNodeCommand.h
        src/lib/command/CSaveCommand.h
        src/lib/command/CSetTitleCommand.h
        src/lib/command/CListCommand.h
        src/lib/command/CHelpCommand.h
        src/lib/command/ICommandHistory.h
        src/lib/command/CCommandHistory.h
        src/lib/command/CUndoCommand.h
        src/lib/document/node/NodeType.h
        src/lib/command/CSaveToHistoryCommandDecorator.h

        test/lib/document/render/CListRendererTest.cpp
        test/lib/document/render/CHtmlRendererTest.cpp
        test/lib/document/CHtmlDocumentTest.cpp
        test/lib/file/CPathTest.cpp
        test/lib/file/MockFileStorage.cpp
        test/lib/random/RandomTest.cpp
        test/lib/document/MockDocument.cpp
        test/lib/command/CInsertParagraphCommandTest.cpp
        test/lib/command/CInsertImageCommandTest.cpp
        test/lib/file/CPathMatchers.cpp src/lib/CApp.h
        test/lib/command/CDocumentCommandFactoryTest.cpp
        test/lib/utils/StringTest.cpp
        test/lib/command/CDeleteNodeCommandTest.cpp
        test/lib/command/CSaveCommandTest.cpp
        test/lib/command/CSetTitleCommandTest.cpp
        test/lib/command/CListCommandTest.cpp
        test/lib/document/node/MockNode.cpp
        test/lib/command/CHelpCommandTest.cpp
        test/lib/command/MockCommandHistory.cpp
)

target_link_libraries(lab05_document_test gtest gtest_main gmock)