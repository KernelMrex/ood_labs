#ifndef LAB04_PAINTER_CSHAPEFACTORY_H
#define LAB04_PAINTER_CSHAPEFACTORY_H

#include "CRectangle.h"
#include "CRegularPolygon.h"
#include "CTriangle.h"
#include "IShapeFactory.h"
#include <regex>

class CShapeFactory : public IShapeFactory
{
public:
	[[nodiscard]] std::unique_ptr<CShape> CreateShape(const std::string& description) const override
	{
		std::regex regex(R"(^([a-z_]+)\s(.*)$)");
		std::smatch match;

		if (!std::regex_match(description, match, regex))
		{
			throw std::invalid_argument("invalid shape description");
		}

		auto handler = m_shapeHandler.find(match[1]);
		if (handler == m_shapeHandler.end())
		{
			throw std::invalid_argument("invalid type in shape description");
		}

		return handler->second(match[2]);
	}

private:
	static std::unique_ptr<CShape> CreateRect(const std::string& description)
	{
		std::regex regex(R"(^(\d\.\d)\s(\d\.\d)\s(\d\.\d)\s(\d\.\d)\s([a-z]+)$)");
		std::smatch match;

		if (!std::regex_match(description, match, regex))
		{
			throw std::invalid_argument("invalid rectangle description");
		}

		Point2D leftTop = {
			.x = std::stod(match[1]),
			.y = std::stod(match[2]),
		};

		Point2D rightBottom = {
			.x = std::stod(match[3]),
			.y = std::stod(match[4]),
		};

		Color color = ParseColor(match[5]);

		return std::make_unique<CRectangle>(color, leftTop, rightBottom);
	}

	static std::unique_ptr<CShape> CreatePolygon(const std::string& description)
	{
		std::regex regex(R"(^((?:\d+\.\d+\s\d+\.\d+\s)+)([a-z]+)$)");
		std::smatch match;

		if (!std::regex_match(description, match, regex))
		{
			throw std::invalid_argument("invalid polygon description");
		}

		Color color = ParseColor(match[2]);
		std::vector<Point2D> vertices = ParseVertices(match[1]);

		return std::make_unique<CRegularPolygon>(color, vertices);
	}

	static std::unique_ptr<CShape> CreateTriangle(const std::string& description)
	{
		std::regex regex(R"(^(\d+\.\d+)\s(\d+\.\d+)\s(\d+\.\d+)\s(\d+\.\d+)\s(\d+\.\d+)\s(\d+\.\d+)\s([a-z]+)$)");
		std::smatch match;

		if (!std::regex_match(description, match, regex))
		{
			throw std::invalid_argument("invalid polygon description");
		}

		Color color = ParseColor(match[7]);

		Point2D vertex1 = { .x = std::stod(match[1]), .y = std::stod(match[2])};
		Point2D vertex2 = { .x = std::stod(match[3]), .y = std::stod(match[4])};
		Point2D vertex3 = { .x = std::stod(match[5]), .y = std::stod(match[6])};

		return std::make_unique<CTriangle>(color, vertex1, vertex2, vertex3);
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

	static std::vector<Point2D> ParseVertices(std::string raw)
	{
		std::regex regex(R"((?:(\d+\.\d+)\s(\d+\.\d+))\s?)");
		std::smatch match;

		std::vector<Point2D> vertices;
		while (std::regex_search(raw, match, regex))
		{
			vertices.emplace_back(Point2D{
				.x = std::stod(match[1]),
				.y = std::stod(match[2])
			});

			raw = match.suffix();
		}

		return vertices;
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
		{ "triangle", CreateTriangle }
	};
};

#endif // LAB04_PAINTER_CSHAPEFACTORY_H
