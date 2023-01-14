#ifndef LAB04_PAINTER_ISHAPEFACTORY_H
#define LAB04_PAINTER_ISHAPEFACTORY_H

#include "CShape.h"
#include <memory>
#include <string>

class IShapeFactory
{
public:
	[[nodiscard]]
	virtual std::unique_ptr<CShape> CreateShape(const std::string& description) const = 0;
};

#endif // LAB04_PAINTER_ISHAPEFACTORY_H
