#ifndef LAB05_DOCUMENT_IRENDERER_H
#define LAB05_DOCUMENT_IRENDERER_H

#include "CImageNode.h"
#include "CParagraphNode.h"

class CImageNode;
class CParagraphNode;

class IRenderer
{
public:
	virtual void RenderImage(const CImageNode& node) = 0;
	virtual void RenderParagraph(const CParagraphNode& node) = 0;
	virtual ~IRenderer() = default;
};

#endif // LAB05_DOCUMENT_IRENDERER_H
