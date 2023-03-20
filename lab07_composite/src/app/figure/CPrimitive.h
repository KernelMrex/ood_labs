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
	std::optional<SFrame> Frame() const override
	{
		return m_frame;
	}

protected:
	void Frame(std::optional<SFrame> frame)
	{
		m_frame = frame;
	}

private:
	std::optional<CBorderStyle> m_borderStyle = std::nullopt;
	std::optional<CFillStyle> m_fillStyle = std::nullopt;
	std::optional<SFrame> m_frame = std::nullopt;
};

#endif // LAB07_COMPOSITE_CPRIMITIVE_H
