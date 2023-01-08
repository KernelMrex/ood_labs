#ifndef LAB04_PAINTER_ICANVAS_H
#define LAB04_PAINTER_ICANVAS_H

#include "Color.h"
#include "Types.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;

	virtual void Drawline(const Point2D& from, const Point2D& to) = 0;

	virtual void DrawEllipse(const Point2D& from, int horizontalRadius, int verticalRadius) = 0;
};

#endif // LAB04_PAINTER_ICANVAS_H
