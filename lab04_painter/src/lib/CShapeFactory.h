#ifndef LAB04_PAINTER_CSHAPEFACTORY_H
#define LAB04_PAINTER_CSHAPEFACTORY_H

#include "CEllipse.h"
#include "CRectangle.h"
#include "CRegularPolygon.h"
#include "CTriangle.h"
#include "IShapeFactory.h"
#include <regex>

class CShapeFactory : public IShapeFactory
{
public:
	[[nodiscard]]
	std::unique_ptr<CShape> CreateShape(const std::string& description) const override
	{
		std::string shapeType;
		std::istringstream iss(description);

		iss >> shapeType;

		auto handler = m_shapeHandler.find(shapeType);
		if (handler == m_shapeHandler.end())
		{
			throw std::invalid_argument("invalid type in shape description");
		}

		std::ostringstream oss;
		oss << iss.rdbuf();

		return handler->second(oss.str());
	}

private:
	static std::unique_ptr<CShape> CreateRect(const std::string& description)
	{
		std::istringstream iss(description);

		std::string colorWord;
		Point2D leftTop{};
		Point2D rightBottom{};

		iss >> colorWord >> leftTop.x >> leftTop.y >> rightBottom.x >> rightBottom.y;

		return std::make_unique<CRectangle>(ParseColor(colorWord), leftTop, rightBottom);
	}

	static std::unique_ptr<CShape> CreatePolygon(const std::string& description)
	{
		std::istringstream iss(description);

		std::string colorWord;
		iss >> colorWord;

		std::vector<Point2D> vertices;
		while (!iss.eof() && iss.good())
		{
			Point2D vertex{};
			iss >> vertex.x >> vertex.y;
			vertices.push_back(vertex);
		}

		return std::make_unique<CRegularPolygon>(ParseColor(colorWord), vertices);
	}

	static std::unique_ptr<CShape> CreateTriangle(const std::string& description)
	{
		std::istringstream iss(description);

		std::string colorWord;
		Point2D vertex1{};
		Point2D vertex2{};
		Point2D vertex3{};

		iss >> colorWord
			>> vertex1.x >> vertex1.y
			>> vertex2.x >> vertex2.y
			>> vertex3.x >> vertex3.y;

		return std::make_unique<CTriangle>(ParseColor(colorWord), vertex1, vertex2, vertex3);
	}

	static std::unique_ptr<CShape> CreateEllipse(const std::string& description)
	{
		std::istringstream iss(description);

		std::string colorWord;
		Point2D center{};
		double verticalRadius;
		double horizontalRadius;

		iss >> colorWord >> center.x >> center.y >> verticalRadius >> horizontalRadius;

		return std::make_unique<CEllipse>(ParseColor(colorWord), center, verticalRadius, horizontalRadius);
	}

	static Color ParseColor(const std::string& raw)
	{
		auto it = m_colorMapping.find(raw);
		if (it == m_colorMapping.end())
		{
			throw std::invalid_argument("invalid color name in rectangle description");
		}
		return it->second;
	}

	inline static std::map<std::string, Color> m_colorMapping{
		{ "green", Color::GREEN },
		{ "red", Color::RED },
		{ "blue", Color::BLUE },
		{ "yellow", Color::YELLOW },
		{ "pink", Color::PINK },
		{ "black", Color::BLACK },
	};

	inline static std::map<std::string, std::function<std::unique_ptr<CShape>(const std::string&)>> m_shapeHandler{
		{ "rectangle", CreateRect },
		{ "polygon", CreatePolygon },
		{ "triangle", CreateTriangle },
		{ "ellipse", CreateEllipse },
	};
};

#endif // LAB04_PAINTER_CSHAPEFACTORY_H
