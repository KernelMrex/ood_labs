#ifndef LAB07_COMPOSITE_CFIGUREGROUP_H
#define LAB07_COMPOSITE_CFIGUREGROUP_H

#include "CPrimitive.h"
#include <limits>
#include <memory>

class CFigureGroup : public CPrimitive
{
public:
	CFigureGroup()
		: m_figures(std::vector<std::shared_ptr<IFigure>>())
	{
	}

	void Draw(ICanvas& canvas) const override
	{
		for (const auto& figure : m_figures)
		{
			figure->Draw(canvas);
		}
	}

	void Resize(uint width, uint height) override
	{
		auto currentFrame = Frame();
		auto resizingCoefficientX = ((double) width) / ((double) (currentFrame->rightBottom.x - currentFrame->leftTop.x));
		auto resizingCoefficientY = ((double) height) / ((double) (currentFrame->rightBottom.y - currentFrame->leftTop.y));

		for (const auto& figure : m_figures)
		{
			auto figureFrame = figure->Frame();
			auto figureAnchor = figureFrame->leftTop;
			figure->Resize(
				static_cast<uint>((figureFrame->rightBottom.x - figureFrame->leftTop.x) * resizingCoefficientX),
				static_cast<uint>((figureFrame->rightBottom.y - figureFrame->leftTop.y) * resizingCoefficientY)
			);
			figure->Move(
				static_cast<uint>(currentFrame->leftTop.x + (figureAnchor.x - currentFrame->leftTop.x) * resizingCoefficientX),
				static_cast<uint>(currentFrame->leftTop.y + (figureAnchor.y - currentFrame->leftTop.y) * resizingCoefficientY)
			);
		}
		CalculateFrame();
	}

	void Move(uint anchorX, uint anchorY) override
	{
		auto currentAnchor = Frame()->leftTop;

		long deltaX = anchorX - currentAnchor.x;
		long deltaY = anchorY - currentAnchor.y;

		for (const auto& figure : m_figures)
		{
			auto figureAnchor = figure->Frame()->leftTop;
			figure->Move(figureAnchor.x + deltaX, figureAnchor.y + deltaY);
		}
		CalculateFrame();
	}

	void Add(std::shared_ptr<IFigure> figure)
	{
		m_figures.emplace_back(std::move(figure));
		CalculateFrame();
	}

	void Remove(const std::shared_ptr<IFigure>& figure)
	{
		std::erase(m_figures, figure);
		CalculateFrame();
	}

private:
	std::vector<std::shared_ptr<IFigure>> m_figures;

	void CalculateFrame()
	{
		if (m_figures.empty())
		{
			Frame(std::nullopt);
			return;
		}

		uint minX = std::numeric_limits<uint>::max(),
			 minY = std::numeric_limits<uint>::max(),
			 maxX = std::numeric_limits<uint>::min(),
			 maxY = std::numeric_limits<uint>::min();

		for (const auto& figure : m_figures)
		{
			minX = std::min(minX, figure->Frame()->leftTop.x);
			minY = std::min(minY, figure->Frame()->leftTop.y);
			maxX = std::max(maxX, figure->Frame()->rightBottom.x);
			maxY = std::max(maxY, figure->Frame()->rightBottom.y);
		}

		Frame({ { { minX, minY }, { maxX, maxY } } });
	}
};

#endif // LAB07_COMPOSITE_CFIGUREGROUP_H
