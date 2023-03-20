#ifndef LAB07_COMPOSITE_CSLIDE_H
#define LAB07_COMPOSITE_CSLIDE_H

#include "ISlide.h"

class CSlide : public ISlide
{
public:
	CSlide(uint width, uint height)
		: m_figures(std::vector<std::shared_ptr<IFigure>>())
		, m_width(width)
		, m_height(height)
	{}

	void Add(std::shared_ptr<IFigure> figure) override
	{
		m_figures.emplace_back(std::move(figure));
	}

	void Draw(ICanvas& canvas) const override
	{
		for (const auto& figure : m_figures)
		{
			figure->Draw(canvas);
		}
	}

	[[nodiscard]]
	uint Width() const override
	{
		return m_width;
	}

	[[nodiscard]]
	uint Height() const override
	{
		return m_height;
	}

private:
	std::vector<std::shared_ptr<IFigure>> m_figures;
	uint m_width, m_height;
};

#endif // LAB07_COMPOSITE_CSLIDE_H
