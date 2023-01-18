#ifndef LAB05_DOCUMENT_CPARAGRAPHNODE_H
#define LAB05_DOCUMENT_CPARAGRAPHNODE_H

#include "INode.h"

class CParagraphNode : public INode
{
public:
	void Render(IRenderer& renderer) const override;
};

#endif // LAB05_DOCUMENT_CPARAGRAPHNODE_H
