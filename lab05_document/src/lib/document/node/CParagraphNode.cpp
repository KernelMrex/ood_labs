#include "CParagraphNode.h"
#include "INodeVisitor.h"

void CParagraphNode::Render(INodeVisitor& renderer) const
{
	renderer.Visit(*this);
}
