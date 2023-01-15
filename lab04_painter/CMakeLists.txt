cmake_minimum_required(VERSION 3.23)
project(lab04_painter)

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
        lab04_painter
        src/main.cpp
        src/lib/CPainter.h
        src/lib/CPictureDraft.h
        src/lib/CShape.h
        src/lib/IDesigner.h
        src/lib/IShapeFactory.h
        src/lib/CDesigner.h
        src/lib/Color.h
        src/lib/ICanvas.h
        src/lib/ConsoleCanvas.h
        src/lib/CShapeFactory.h
        src/lib/CClient.h
        src/lib/CEllipse.h
        src/lib/CRegularPolygon.h
        src/lib/CTriangle.h
        src/lib/CRectangle.h
        src/lib/Types.h
)

add_executable(
        lab04_painter_test
        src/lib/CPainter.h
        src/lib/CPictureDraft.h
        src/lib/CShape.h
        src/lib/IDesigner.h
        src/lib/IShapeFactory.h
        src/lib/CDesigner.h
        src/lib/Color.h
        src/lib/ICanvas.h
        src/lib/ConsoleCanvas.h
        src/lib/CShapeFactory.h
        src/lib/CClient.h
        src/lib/CEllipse.h
        src/lib/CRegularPolygon.h
        src/lib/CTriangle.h
        src/lib/CRectangle.h
        src/lib/Types.h

        test/lib/unit/ConsoleCanvasTest.cpp
        test/lib/unit/mock/MockCanvas.cpp
        test/lib/unit/CRectangleTest.cpp
        test/lib/unit/CTriangleTest.cpp
        test/lib/unit/CRegularPolygonTest.cpp
        test/lib/unit/CEllipseTest.cpp
        test/lib/unit/CShapeFactoryTest.cpp
        test/lib/unit/matcher/MatchersPoint2D.cpp
        test/lib/unit/CPictureDraftTest.cpp test/lib/unit/mock/MockShape.cpp)

target_link_libraries(lab04_painter_test gtest gtest_main gmock)
