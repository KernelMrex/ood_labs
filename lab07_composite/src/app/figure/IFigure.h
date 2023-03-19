#ifndef LAB07_COMPOSITE_IFIGURE_H
#define LAB07_COMPOSITE_IFIGURE_H

#include "../canvas/ICanvas.h"
#include <cstdlib>

class IFigure
{
public:
	virtual void Draw(ICanvas& canvas) = 0;

	virtual void Resize(uint width, uint height) = 0;

	virtual ~IFigure() = default;
};

#endif // LAB07_COMPOSITE_IFIGURE_H
