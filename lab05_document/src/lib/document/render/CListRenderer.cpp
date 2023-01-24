#include "CListRenderer.h"

void CListRenderer::Visit(const CImageNode& node)
{
	m_out << "Image: " << node.Width() << ' ' << node.Height() << ' ' << node.Path().String();
}

void CListRenderer::Visit(const CParagraphNode& node)
{
	m_out << "Paragraph: " << node.Text();
}
