#ifndef LAB07_COMPOSITE_CBORDERSTYLE_H
#define LAB07_COMPOSITE_CBORDERSTYLE_H

#include "../../common/SColor.h"
#include <cstdlib>

class CBorderStyle
{
public:
	CBorderStyle(uint8_t red, uint8_t green, uint8_t blue, double alpha, uint thickness)
		: m_color({red, green, blue, alpha})
		, m_thickness(thickness)
	{}

	CBorderStyle()
		: m_color({0, 0, 0, 1.0})
		, m_thickness(1)
	{}

	[[nodiscard]]
	SColor Color() const
	{
		return m_color;
	}

	[[nodiscard]]
	uint Thickness() const
	{
		return m_thickness;
	}

private:
	SColor m_color;
	uint m_thickness;
};

#endif // LAB07_COMPOSITE_CBORDERSTYLE_H
