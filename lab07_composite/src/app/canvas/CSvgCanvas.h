#ifndef LAB07_COMPOSITE_CSVGCANVAS_H
#define LAB07_COMPOSITE_CSVGCANVAS_H

#include "ICanvas.h"
#include <boost/format.hpp>
#include <ostream>

class CSvgCanvas : public ICanvas
{
public:
	CSvgCanvas(std::ostream& out, uint width, uint height)
		: m_out(out)
		, m_width(width)
		, m_height(height)
		, m_drawing(false)
	{
	}

	~CSvgCanvas() override
	{
		if (m_drawing)
		{
			EndDraw();
		}
	}

	void StartDraw()
	{
		if (m_drawing)
		{
			throw std::logic_error("Drawing already started!");
		}
		m_out << (boost::format(R"fmt(<svg height="%1%" width="%2%">)fmt") % m_height % m_width) << std::endl;
		m_drawing = true;
	}

	void EndDraw()
	{
		if (!m_drawing)
		{
			throw std::logic_error("Can not end drawing: drawing has not been started!");
		}
		m_out << "</svg>" << std::endl;
		m_drawing = false;
	}

	void DrawingMustBeStarted() const
	{
		if (!m_drawing)
		{
			throw std::logic_error("Drawing was not started!");
		}
	}

	void DrawLine(const SPoint& from, const SPoint& to) override
	{
		// TODO
	}

	void FillPolygon(const std::vector<SPoint>& vertices, SColor color) override
	{
		// TODO
	}

	void DrawEllipse(const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color, uint thickness) override
	{
		DrawingMustBeStarted();
		m_out << "  " << (boost::format(R"fmt(<ellipse cx="%1%" cy="%2%" rx="%3%" ry="%4%" fill-opacity="0" stroke="rgba(%5%, %6%, %7%, %8%)" stroke-width="%9%"/>)fmt")
			% center.x
			% center.y
			% horizontalRadius
			% verticalRadius
			% +color.red
			% +color.green
			% +color.blue
			% color.alpha
			% thickness)
			  << std::endl;
	}

	void FillEllipse(const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color) override
	{
		DrawingMustBeStarted();
		m_out << "  " << (boost::format(R"fmt(<ellipse cx="%1%" cy="%2%" rx="%3%" ry="%4%" fill="rgba(%5%, %6%, %7%, %8%)" stroke="none"/>)fmt")
			% center.x
			% center.y
			% horizontalRadius
			% verticalRadius
			% +color.red
			% +color.green
			% +color.blue
			% color.alpha)
			  << std::endl;
	}

private:
	std::ostream& m_out;
	uint m_width, m_height;
	bool m_drawing;
};

#endif // LAB07_COMPOSITE_CSVGCANVAS_H
