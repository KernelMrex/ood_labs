#ifndef LAB07_COMPOSITE_CFILLSTYLE_H
#define LAB07_COMPOSITE_CFILLSTYLE_H

#include "../../common/SColor.h"

class CFillStyle
{
public:
	CFillStyle(uint8_t red, uint8_t green, uint8_t blue, double alpha)
		: m_color({red, green, blue, alpha})
	{
	}

	CFillStyle()
		: m_color({0, 0, 0, 1.0})
	{
	}

	[[nodiscard]]
	SColor Color() const
	{
		return m_color;
	}

private:
	SColor m_color;
};

#endif // LAB07_COMPOSITE_CFILLSTYLE_H
