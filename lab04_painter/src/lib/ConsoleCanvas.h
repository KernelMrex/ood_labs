#ifndef LAB04_PAINTER_CONSOLECANVAS_H
#define LAB04_PAINTER_CONSOLECANVAS_H

#include "ICanvas.h"
#include "Color.h"
#include <ostream>
#include <iomanip>

class ConsoleCanvas : public ICanvas
{
public:
	explicit ConsoleCanvas(Color color, std::ostream& ostream)
		: m_color(color)
		, m_ostream(ostream)
	{
	}

	void SetColor(Color color) override
	{
		m_color = color;
	}

	void Drawline(const Point2D& from, const Point2D& to) override
	{
		m_ostream << "line from (" << from.x << ", " << from.y << ") to (" << to.x << ", " << to.y << ") with #" << fmtColorToHex(m_color) << std::endl;
	}

	void DrawEllipse(const Point2D& center, int horizontalRadius, int verticalRadius) override
	{
		m_ostream << "ellipse center (" << center.x << ", " << center.y << ") with hr: " << horizontalRadius << ", vr: " << verticalRadius << " with #" << fmtColorToHex(m_color) << std::endl;
	}

private:
	Color m_color;
	std::ostream& m_ostream;

	static std::string fmtColorToHex(const Color& color)
	{
		std::stringstream ss;
		ss << std::setfill('0') << std::setw(6) << std::hex << (int)color;
		return ss.str();
	}
};

#endif // LAB04_PAINTER_CONSOLECANVAS_H
