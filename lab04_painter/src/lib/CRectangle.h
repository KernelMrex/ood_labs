#ifndef LAB04_PAINTER_CRECTANGLE_H
#define LAB04_PAINTER_CRECTANGLE_H

#include "CShape.h"

class CRectangle : public CShape
{
public:
	CRectangle(
		Color color,
		const Point2D& leftTop,
		const Point2D& rightBottom
	)
		: CShape(color)
		, m_leftTop(leftTop)
		, m_rightBottom(rightBottom)
	{
	}

	void Draw(ICanvas& canvas) const override
	{
		Point2D rightTop{ .x = m_rightBottom.x, .y = m_leftTop.y};
		Point2D leftBottom{ .x = m_leftTop.x, .y = m_rightBottom.y};

		canvas.SetColor(GetColor());
		canvas.Drawline(m_leftTop, rightTop);
		canvas.Drawline(rightTop, m_rightBottom);
		canvas.Drawline(m_rightBottom, leftBottom);
		canvas.Drawline(leftBottom, m_leftTop);
	}

	[[nodiscard]] Point2D GetLeftTop() const
	{
		return m_leftTop;
	}

	[[nodiscard]] Point2D GetRightBottom() const
	{
		return m_rightBottom;
	}

private:
	Point2D m_leftTop, m_rightBottom;
};

#endif // LAB04_PAINTER_CRECTANGLE_H
