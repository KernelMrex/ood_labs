#ifndef LAB04_PAINTER_CPAINTER_H
#define LAB04_PAINTER_CPAINTER_H

#include "CPictureDraft.h"
#include <memory>

class CPainter
{
public:
	static void DrawPicture(const CPictureDraft& draft, ICanvas& canvas)
	{
		for (std::size_t i = 0; i < draft.GetShapeCount(); i++)
		{
			draft.GetShape(i)->Draw(canvas);
		}
	}
};

#endif // LAB04_PAINTER_CPAINTER_H
