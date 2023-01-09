#ifndef LAB04_PAINTER_CTRIANGLE_H
#define LAB04_PAINTER_CTRIANGLE_H

#include "CShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(
		Color color,
		const Point2D& vertex1,
		const Point2D& vertex2,
		const Point2D& vertex3)
		: CShape(color)
		, m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3)
	{
	}

	void Draw(ICanvas& canvas) override
	{
		canvas.SetColor(GetColor());
		canvas.Drawline(m_vertex1, m_vertex2);
		canvas.Drawline(m_vertex2, m_vertex3);
		canvas.Drawline(m_vertex3, m_vertex1);
	}

	[[nodiscard]] Point2D GetVertex1() const
	{
		return m_vertex1;
	}

	[[nodiscard]] Point2D GetVertex2() const
	{
		return m_vertex2;
	}

	[[nodiscard]] Point2D GetVertex3() const
	{
		return m_vertex3;
	}

private:
	Point2D m_vertex1, m_vertex2, m_vertex3;
};

#endif // LAB04_PAINTER_CTRIANGLE_H
