#ifndef LAB04_PAINTER_CREGULARPOLYGON_H
#define LAB04_PAINTER_CREGULARPOLYGON_H

#include "CShape.h"
#include <vector>

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(
		Color color,
		const std::vector<Point2D>& vertices)
		: CShape(color)
		, m_vertices(vertices)
	{
	}

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(GetColor());
		for (std::size_t i = 0; i < m_vertices.size(); i++)
		{
			canvas.Drawline(m_vertices[i], m_vertices[(i + 1) % m_vertices.size()]);
		}
	}

	[[nodiscard]]
	unsigned int GetVertexCount() const
	{
		return m_vertices.size();
	}

	[[nodiscard]]
	Point2D GetCenter() const
	{
		Point2D centroid = { 0, 0 };
		double signedArea = 0.0;

		for (std::size_t i = 0; i < m_vertices.size(); i++)
		{
			Point2D currentVertex = m_vertices[i];
			Point2D nextVertex = m_vertices[(i + 1) % m_vertices.size()];

			double partialSignedArea = currentVertex.x * nextVertex.y - nextVertex.x * currentVertex.y;

			signedArea += partialSignedArea;
			centroid.x += (currentVertex.x + nextVertex.x) * partialSignedArea;
			centroid.y += (currentVertex.y + nextVertex.y) * partialSignedArea;
		}

		centroid.x /= (3.0 * signedArea);
		centroid.y /= (3.0 * signedArea);

		return centroid;
	}

private:
	std::vector<Point2D> m_vertices;
};

#endif // LAB04_PAINTER_CREGULARPOLYGON_H
