#ifndef SHAPE_DRAWING_LIB_H
#define SHAPE_DRAWING_LIB_H

// Пространство имен библиотеки для рисования фигур (использует graphics_lib)
// Код библиотеки недоступен для изменения
#include "../graphics_lib/graphics_lib.h"

namespace shape_drawing_lib
{


struct Point
{
	int x;
	int y;
};


// Интерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib
class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib::ICanvas& canvas) const = 0;

	virtual ~ICanvasDrawable() = default;
};


class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point& p1, const Point& p2, const Point& p3)
	{
		// TODO: написать код конструктора
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: написать код рисования треугольника на холсте
	}

private:
	// TODO: дописать приватную часть
};


class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point& leftTop, int width, int height)
	{
		// TODO: написать код конструктора
	}

	void Draw(graphics_lib::ICanvas& canvas) const override
	{
		// TODO: написать код рисования прямоугольника на холсте
	}

private:
	// TODO: дописать приватную часть
};


// Художник, способный рисовать ICanvasDrawable-объекты на ICanvas
class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas& canvas)
	{
		// TODO: дописать конструктор класса
	}

	void Draw(const ICanvasDrawable& drawable)
	{
		// TODO: дописать код рисования ICanvasDrawable на canvas, переданном в конструктор
	}

private:
	// TODO: дописать приватную часть
};


} // namespace shape_drawing_lib

#endif // SHAPE_DRAWING_LIB_H
