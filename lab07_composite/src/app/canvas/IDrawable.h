#ifndef LAB07_COMPOSITE_IDRAWABLE_H
#define LAB07_COMPOSITE_IDRAWABLE_H

#include "ICanvas.h"

class IDrawable
{
public:
	virtual void Draw(ICanvas& canvas) const = 0;

	virtual ~IDrawable() = default;
};

#endif // LAB07_COMPOSITE_IDRAWABLE_H
