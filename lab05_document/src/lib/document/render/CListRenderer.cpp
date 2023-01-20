#include "CListRenderer.h"

void CListRenderer::RenderImage(const CImageNode& node)
{
	m_out << "Image: " << node.Width() << ' ' << node.Height() << ' ' << node.Path().String();
}

void CListRenderer::RenderParagraph(const CParagraphNode& node)
{
	m_out << "Paragraph: " << node.Text();
}
