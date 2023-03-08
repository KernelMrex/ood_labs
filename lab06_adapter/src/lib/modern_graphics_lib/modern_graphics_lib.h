#ifndef GRAPHICS_LIB_H
#define GRAPHICS_LIB_H

// Пространство имен современной графической библиотеки (недоступно для изменения)
#include <iostream>
#include <boost/format.hpp>

namespace modern_graphics_lib
{

class CPoint
{
public:
	CPoint(int x, int y) :x(x), y(y) {}

	int x;
	int y;
};

// Класс для современного рисования графики
class CModernGraphicsRenderer
{
public:
	CModernGraphicsRenderer(std::ostream & strm) : m_out(strm)
	{
	}

	~CModernGraphicsRenderer()
	{
		if (m_drawing) // Завершаем рисование, если оно было начато
		{
			EndDraw();
		}
	}

	// Этот метод должен быть вызван в начале рисования
	void BeginDraw()
	{
		if (m_drawing)
		{
			throw std::logic_error("Drawing has already begun");
		}
		m_out << "<draw>" << std::endl;
		m_drawing = true;
	}

	// Выполняет рисование линии
	void DrawLine(const CPoint & start, const CPoint & end)
	{
		if (!m_drawing)
		{
			throw std::logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
		}

		m_out << boost::format(R"(  <line fromX="%1%" fromY="%2" toX="%3%" toY="%4%"/>)")
			  << std::endl;
	}

	// Этот метод должен быть вызван в конце рисования
	void EndDraw()
	{
		if (!m_drawing)
		{
			throw std::logic_error("Drawing has not been started");
		}
		m_out << "</draw>" << std::endl;
		m_drawing = false;
	}

private:
	std::ostream & m_out;
	bool m_drawing = false;
};

}

#endif // GRAPHICS_LIB_H
