#ifndef APP_H
#define APP_H

// Пространство имен приложения (доступно для модификации)
#include "../lib/graphics_lib/graphics_lib.h"
#include "../lib/modern_graphics_lib/modern_graphics_lib.h"
#include "../lib/shape_drawing_lib/shape_drawing_lib.h"
#include "graphics/CModernGraphicsRendererAdapter.h"

namespace app
{

void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
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

void PaintPictureOnModernGraphicsRenderer()
{
	app::CModernGraphicsRendererAdapter modernGraphicsAdapter(std::cout);

	modernGraphicsAdapter.BeginDraw();
	shape_drawing_lib::CCanvasPainter painter(modernGraphicsAdapter);
	PaintPicture(painter);
	modernGraphicsAdapter.EndDraw();
}

} // namespace app

#endif // APP_H
