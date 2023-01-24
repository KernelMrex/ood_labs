#include "CImageNode.h"
#include "INodeVisitor.h"

void CImageNode::Render(INodeVisitor& renderer) const
{
	renderer.Visit(*this);
}
