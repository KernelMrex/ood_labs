#ifndef LAB04_PAINTER_CSHAPE_H
#define LAB04_PAINTER_CSHAPE_H

#include "Color.h"
#include "ICanvas.h"
#include <memory>

class CShape
{
public:
	virtual void Draw(ICanvas& canvas) const = 0;

	[[nodiscard]]
	Color GetColor() const
	{
		return m_color;
	}

	virtual ~CShape() = default;

protected:
	explicit CShape(Color color)
		: m_color(color)
	{
	}

private:
	Color m_color;
};

#endif // LAB04_PAINTER_CSHAPE_H
