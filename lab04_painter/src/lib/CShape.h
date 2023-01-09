#ifndef LAB04_PAINTER_CSHAPE_H
#define LAB04_PAINTER_CSHAPE_H

#include "Color.h"
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color color)
		: m_color(color)
	{
	}

	virtual void Draw(ICanvas& canvas) = 0;

	Color GetColor()
	{
		return m_color;
	}

	virtual ~CShape() = default;

private:
	Color m_color;
};

#endif // LAB04_PAINTER_CSHAPE_H
