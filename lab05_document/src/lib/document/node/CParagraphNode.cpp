#include "CParagraphNode.h"
#include "../render/IRenderer.h"

void CParagraphNode::Render(IRenderer& renderer) const
{
	renderer.RenderParagraph(*this);
}
