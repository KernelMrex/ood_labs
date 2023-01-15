#ifndef LAB04_PAINTER_CELLIPSE_H
#define LAB04_PAINTER_CELLIPSE_H

#include "CShape.h"

class CEllipse : public CShape
{
public:
	CEllipse(
		Color color,
		const Point2D& center,
		double verticalRadius,
		double horizontalRadius)
		: CShape(color)
		, m_center(center)
		, m_verticalRadius(verticalRadius)
		, m_horizontalRadius(horizontalRadius)
	{
	}

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(GetColor());
		canvas.DrawEllipse(m_center, m_verticalRadius, m_horizontalRadius);
	}

	[[nodiscard]]
	std::unique_ptr<CShape> Clone() const override
	{
		return std::make_unique<CEllipse>(GetColor(), m_center, m_verticalRadius, m_horizontalRadius);
	}

	[[nodiscard]]
	Point2D GetCenter() const
	{
		return m_center;
	}

	[[nodiscard]]
	double GetVerticalRadius() const
	{
		return m_verticalRadius;
	}

	[[nodiscard]]
	double GetHorizontalRadius() const
	{
		return m_horizontalRadius;
	}

private:
	Point2D m_center;
	double m_verticalRadius, m_horizontalRadius;
};

#endif // LAB04_PAINTER_CELLIPSE_H
