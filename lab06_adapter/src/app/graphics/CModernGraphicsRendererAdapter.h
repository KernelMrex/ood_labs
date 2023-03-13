#ifndef CMODERNGRAPHICSRENDERERADAPTER_H
#define CMODERNGRAPHICSRENDERERADAPTER_H

#include "../../lib/modern_graphics_lib/modern_graphics_lib.h"
#include "../../lib/shape_drawing_lib/shape_drawing_lib.h"

namespace app
{

class CModernGraphicsRendererAdapter : public graphics_lib::ICanvas
{
public:
	CModernGraphicsRendererAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernGraphicsRenderer)
		: m_modernRenderer(modernGraphicsRenderer)
		, m_cursorPosition(0, 0)
	{}

	void MoveTo(int x, int y) override
	{
		m_cursorPosition.x = x;
		m_cursorPosition.y = x;
	}

	void LineTo(int x, int y) override
	{
		m_modernRenderer.DrawLine(m_cursorPosition, {x, y});
	}

private:
	modern_graphics_lib::CModernGraphicsRenderer& m_modernRenderer;
	modern_graphics_lib::CPoint m_cursorPosition;
};

} // namespace app

#endif // CMODERNGRAPHICSRENDERERADAPTER_H
