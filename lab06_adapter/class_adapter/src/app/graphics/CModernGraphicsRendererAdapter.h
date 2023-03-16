#ifndef CMODERNGRAPHICSRENDERERADAPTER_H
#define CMODERNGRAPHICSRENDERERADAPTER_H

#include "../../lib/modern_graphics_lib/modern_graphics_lib.h"
#include "../../lib/shape_drawing_lib/shape_drawing_lib.h"

namespace app
{

class CModernGraphicsRendererAdapter : public graphics_lib::ICanvas, public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CModernGraphicsRendererAdapter(std::ostream& out)
		: modern_graphics_lib::CModernGraphicsRenderer(out)
		, m_cursorPosition(0, 0)
	{}

	void MoveTo(int x, int y) override
	{
		m_cursorPosition.x = x;
		m_cursorPosition.y = y;
	}

	void LineTo(int x, int y) override
	{
		DrawLine(m_cursorPosition, {x, y});
	}

private:
	modern_graphics_lib::CPoint m_cursorPosition;
};

} // namespace app

#endif // CMODERNGRAPHICSRENDERERADAPTER_H
