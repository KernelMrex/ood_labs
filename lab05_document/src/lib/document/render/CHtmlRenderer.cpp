#include "CHtmlRenderer.h"

void CHtmlRenderer::RenderImage(const CImageNode& node)
{
	m_out << "<img src=\"" << node.Path().String() << "\" width=\"" << node.Width() << "\" height=\"" << node.Height() << "\">";
}

void CHtmlRenderer::RenderParagraph(const CParagraphNode& node)
{
	m_out << "<p>" << node.Text() << "</p>";
}