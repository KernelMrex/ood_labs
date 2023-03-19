#ifndef LAB07_COMPOSITE_CPRIMITIVE_H
#define LAB07_COMPOSITE_CPRIMITIVE_H

#include "../common/SFrame.h"
#include "IFigure.h"
#include "style/CBorderStyle.h"
#include "style/CFillStyle.h"
#include <optional>

class CPrimitive : public IFigure
{
public:
	[[nodiscard]]
	std::optional<CBorderStyle> BorderStyle() const
	{
		return m_borderStyle;
	}

	void BorderStyle(std::optional<CBorderStyle> borderStyle)
	{
		m_borderStyle = borderStyle;
	}

	[[nodiscard]]
	std::optional<CFillStyle> FillStyle() const
	{
		return m_fillStyle;
	}

	void FillStyle(std::optional<CFillStyle> fillStyle)
	{
		m_fillStyle = fillStyle;
	}

	[[nodiscard]]
	SFrame Frame() const
	{
		return m_frame;
	}

protected:
	void Frame(const SPoint& leftTop, const SPoint& rightBottom)
	{
		m_frame.leftTop = leftTop;
		m_frame.rightBottom = rightBottom;
	}

private:
	std::optional<CBorderStyle> m_borderStyle = std::nullopt;
	std::optional<CFillStyle> m_fillStyle = std::nullopt;
	SFrame m_frame;
};

#endif // LAB07_COMPOSITE_CPRIMITIVE_H
