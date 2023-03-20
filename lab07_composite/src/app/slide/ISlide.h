#ifndef LAB07_COMPOSITE_ISLIDE_H
#define LAB07_COMPOSITE_ISLIDE_H

#include "../canvas/IDrawable.h"
#include "../figure/IFigure.h"
#include <memory>

class ISlide : public IDrawable
{
public:
	virtual uint Width() const = 0;

	virtual uint Height() const = 0;

	virtual void Add(std::shared_ptr<IFigure> figure) = 0;
};

#endif // LAB07_COMPOSITE_ISLIDE_H
