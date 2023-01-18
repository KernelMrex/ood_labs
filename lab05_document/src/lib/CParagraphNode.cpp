#include "CParagraphNode.h"
#include "IRenderer.h"

void CParagraphNode::Render(IRenderer& renderer) const
{
	renderer.RenderParagraph(*this);
}
