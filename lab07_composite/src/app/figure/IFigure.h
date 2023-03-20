#ifndef LAB07_COMPOSITE_IFIGURE_H
#define LAB07_COMPOSITE_IFIGURE_H

#include "../canvas/ICanvas.h"
#include <cstdlib>
#include <optional>

class IFigure
{
public:
	virtual void Draw(ICanvas& canvas) const = 0;

	virtual void Resize(uint width, uint height) = 0;

	[[nodiscard]]
	virtual std::optional<SFrame> Frame() const = 0;

	virtual ~IFigure() = default;
};

#endif // LAB07_COMPOSITE_IFIGURE_H
