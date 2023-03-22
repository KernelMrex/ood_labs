#ifndef LAB07_COMPOSITE_IFIGURE_H
#define LAB07_COMPOSITE_IFIGURE_H

#include "../canvas/ICanvas.h"
#include "../canvas/IDrawable.h"
#include <cstdlib>
#include <optional>

class IFigure : public IDrawable
{
public:
	virtual void Resize(uint width, uint height) = 0;

	virtual void Move(uint anchorX, uint anchorY) = 0;

	[[nodiscard]]
	virtual std::optional<SFrame> Frame() const = 0;
};

#endif // LAB07_COMPOSITE_IFIGURE_H
