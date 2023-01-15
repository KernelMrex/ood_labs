#ifndef LAB04_PAINTER_IDESIGNER_H
#define LAB04_PAINTER_IDESIGNER_H

#include "CPictureDraft.h"

class IDesigner
{
public:
	virtual std::unique_ptr<CPictureDraft> CreateDraft(std::istream& in) const = 0;

	virtual ~IDesigner() = default;
};

#endif // LAB04_PAINTER_IDESIGNER_H
