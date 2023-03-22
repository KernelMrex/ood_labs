#ifndef LAB07_COMPOSITE_CELLIPSE_H
#define LAB07_COMPOSITE_CELLIPSE_H

#include "CPrimitive.h"
#include <cmath>

class CEllipse : public CPrimitive
{
public:
	CEllipse(const SPoint& center, uint vr, uint hr)
		: m_center(center)
		, m_verticalRadius(vr)
		, m_horizontalRadius(hr)
	{
		CalculateFrame();
	}

	void Draw(ICanvas& canvas) const override
	{
		auto borderStyle = BorderStyle();
		if (borderStyle.has_value())
		{
			canvas.DrawEllipse(m_center, m_verticalRadius, m_horizontalRadius, borderStyle->Color(), borderStyle->Thickness());
		}

		auto fillStyle = FillStyle();
		if (fillStyle.has_value())
		{
			canvas.FillEllipse(m_center, m_verticalRadius, m_horizontalRadius, fillStyle->Color());
		}
	}

	void Resize(uint width, uint height) override
	{
		auto xDeltaCoefficient = ((double) width) / ((double) m_horizontalRadius * 2);
		auto yDeltaCoefficient = ((double) height) / ((double) m_verticalRadius * 2);

		m_center = { static_cast<uint>(m_center.x * xDeltaCoefficient), static_cast<uint>(m_center.y * yDeltaCoefficient) };
		m_horizontalRadius = static_cast<uint>(m_horizontalRadius * xDeltaCoefficient);
		m_verticalRadius = static_cast<uint>(m_verticalRadius * yDeltaCoefficient);
		CalculateFrame();
	}

	void Move(uint anchorX, uint anchorY) override
	{
		m_center.x = anchorX + m_horizontalRadius;
		m_center.y = anchorY + m_verticalRadius;
		CalculateFrame();
	}

private:
	SPoint m_center;
	uint m_verticalRadius;
	uint m_horizontalRadius;

	inline void CalculateFrame()
	{
		Frame({ { { m_center.x - m_horizontalRadius, m_center.y - m_verticalRadius }, { m_center.x + m_horizontalRadius, m_center.y + m_verticalRadius } } });
	}
};

#endif // LAB07_COMPOSITE_CELLIPSE_H
