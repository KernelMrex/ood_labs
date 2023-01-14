#ifndef LAB04_PAINTER_CSHAPEFACTORY_H
#define LAB04_PAINTER_CSHAPEFACTORY_H

#include "CRectangle.h"
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

		auto it = m_colorMapping.find(match[5]);
		if (it == m_colorMapping.end())
		{
			throw std::invalid_argument("invalid color name in rectangle description");
		}

		return std::make_unique<CRectangle>(it->second, leftTop, rightBottom);
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
	};
};

#endif // LAB04_PAINTER_CSHAPEFACTORY_H
