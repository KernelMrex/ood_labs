#ifndef LAB07_COMPOSITE_CRECTANGLE_H
#define LAB07_COMPOSITE_CRECTANGLE_H

#include "CPrimitive.h"

class CRectangle : public CPrimitive
{
public:
	CRectangle(const SPoint& leftTop, uint width, uint height)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
	{}

	void Draw(ICanvas& canvas) const override
	{
		std::vector<SPoint> vertices{
			m_leftTop,
			{ m_leftTop.x + m_width, m_leftTop.y },
			{ m_leftTop.x + m_width, m_leftTop.y + m_height },
			{ m_leftTop.x, m_leftTop.y + m_height },
		};

		auto borderStyle = BorderStyle();
		if (borderStyle.has_value())
		{
			std::vector<std::pair<SPoint, SPoint>> sides{
				{ vertices[0], vertices[1] },
				{ vertices[1], vertices[2] },
				{ vertices[2], vertices[3] },
				{ vertices[3], vertices[0] },
			};

			for (const auto& side : sides)
			{
				canvas.DrawLine(side.first, side.second, borderStyle->Color(), borderStyle->Thickness());
			}
		}

		auto fillStyle = FillStyle();
		if (fillStyle.has_value())
		{
			canvas.FillPolygon(vertices, fillStyle->Color());
		}
	}

	void Resize(uint width, uint height) override
	{
		// TODO
	}

private:
	SPoint m_leftTop;
	uint m_width, m_height;
};

#endif // LAB07_COMPOSITE_CRECTANGLE_H
