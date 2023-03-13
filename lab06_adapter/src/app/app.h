#ifndef APP_H
#define APP_H

// Пространство имен приложения (доступно для модификации)
#include "../lib/shape_drawing_lib/shape_drawing_lib.h"

namespace app
{

void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(rectangle);
	painter.Draw(triangle);
}


void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

}

#endif // APP_H
