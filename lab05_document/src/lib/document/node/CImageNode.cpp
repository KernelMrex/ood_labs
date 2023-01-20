#include "CImageNode.h"
#include "../render/IRenderer.h"

void CImageNode::Render(IRenderer& renderer) const
{
	renderer.RenderImage(*this);
}
