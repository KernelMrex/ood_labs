#ifndef LAB07_COMPOSITE_ICANVAS_H
#define LAB07_COMPOSITE_ICANVAS_H

#include "../common/SColor.h"
#include "../common/SPoint.h"
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(const SPoint& from, const SPoint& to, const SColor& color, uint thickness) = 0;

	virtual void FillPolygon(const std::vector<SPoint>& vertices, const SColor& color) = 0;

	virtual void DrawEllipse(const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color, uint thickness) = 0;

	virtual void FillEllipse(const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color) = 0;

	virtual ~ICanvas() = default;
};

#endif // LAB07_COMPOSITE_ICANVAS_H
