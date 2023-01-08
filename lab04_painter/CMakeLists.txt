cmake_minimum_required(VERSION 3.23)
project(lab04_painter)

set(CMAKE_CXX_STANDARD 20)

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
        src/lib/CCanvas.h
        src/lib/CShapeFactory.h
        src/lib/CClient.h
        src/lib/CEllipse.h
        src/lib/CRegularPolygon.h
        src/lib/CTriangle.h
        src/lib/CRectangle.h
)
