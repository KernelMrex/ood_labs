#ifndef LAB05_DOCUMENT_CHTMLRENDERER_H
#define LAB05_DOCUMENT_CHTMLRENDERER_H

#include "IRenderer.h"
#include <ostream>

class CHtmlRenderer : public IRenderer
{
public:
	explicit CHtmlRenderer(std::ostream& out)
		: m_out(out)
	{}

	void RenderImage(const CImageNode& node) override;

	void RenderParagraph(const CParagraphNode& node) override;

private:
	std::ostream& m_out;
};

#endif // LAB05_DOCUMENT_CHTMLRENDERER_H
