#include "CImageNode.h"
#include "IRenderer.h"

void CImageNode::Render(IRenderer& renderer) const
{
	renderer.RenderImage(*this);
}
