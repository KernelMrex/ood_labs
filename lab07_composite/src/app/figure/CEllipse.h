#ifndef LAB07_COMPOSITE_CELLIPSE_H
#define LAB07_COMPOSITE_CELLIPSE_H

#include "CPrimitive.h"

class CEllipse : public CPrimitive
{
public:
	CEllipse(const SPoint& center, uint vr, uint hr)
		: m_center(center)
		, m_verticalRadius(vr)
		, m_horizontalRadius(hr)
	{
		Frame({ { { center.x - hr, center.y - vr }, { center.x + hr, center.y + vr } } });
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
		// TODO
	}

private:
	SPoint m_center;
	uint m_verticalRadius;
	uint m_horizontalRadius;
};

#endif // LAB07_COMPOSITE_CELLIPSE_H
