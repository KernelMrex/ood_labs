#ifndef LAB05_DOCUMENT_CLISTRENDERER_H
#define LAB05_DOCUMENT_CLISTRENDERER_H

#include "IRenderer.h"

class CListRenderer : public IRenderer
{
public:
	void RenderImage(const CImageNode& node) override;

	void RenderParagraph(const CParagraphNode& node) override;


};

#endif // LAB05_DOCUMENT_CLISTRENDERER_H
