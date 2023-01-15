#ifndef LAB04_PAINTER_CDESIGNER_H
#define LAB04_PAINTER_CDESIGNER_H

#include "IDesigner.h"
#include "IShapeFactory.h"
#include <istream>

class CDesigner : public IDesigner
{
public:
	explicit CDesigner(std::unique_ptr<IShapeFactory> shapeFactory)
		: m_shapeFactory(std::move(shapeFactory))
	{
	}

	std::unique_ptr<CPictureDraft> CreateDraft(std::istream& in) const override
	{
		std::vector<std::shared_ptr<CShape>> shapes;
		std::string line;
		while (std::getline(in, line))
		{
			if (line.empty())
			{
				break;
			}
			shapes.push_back(m_shapeFactory->CreateShape(line));
		}

		return std::make_unique<CPictureDraft>(shapes);
	}

private:
	std::unique_ptr<IShapeFactory> m_shapeFactory;
};

#endif // LAB04_PAINTER_CDESIGNER_H
