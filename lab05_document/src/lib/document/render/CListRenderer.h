#ifndef LAB05_DOCUMENT_CLISTRENDERER_H
#define LAB05_DOCUMENT_CLISTRENDERER_H

#include "IRenderer.h"
#include <ostream>

class CListRenderer : public IRenderer
{
public:
	explicit CListRenderer(std::ostream& out)
		: m_out(out){};

	void RenderImage(const CImageNode& node) override;

	void RenderParagraph(const CParagraphNode& node) override;

private:
	std::ostream& m_out;
};

#endif // LAB05_DOCUMENT_CLISTRENDERER_H
