#include "CHtmlRenderer.h"

void CHtmlRenderer::Visit(const CImageNode& node)
{
	m_out << "<img src=\"" << node.Path().String() << "\" width=\"" << node.Width() << "\" height=\"" << node.Height() << "\">";
}

void CHtmlRenderer::Visit(const CParagraphNode& node)
{
	m_out << "<p>" << node.Text() << "</p>";
}