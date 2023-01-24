#ifndef LAB05_DOCUMENT_INODE_H
#define LAB05_DOCUMENT_INODE_H

#include "NodeType.h"

class IRenderer;

class INode
{
public:
	virtual void Render(IRenderer& renderer) const = 0;

	[[nodiscard]]
	virtual NodeType Type() const = 0;

	virtual ~INode() = default;
};

#endif // LAB05_DOCUMENT_INODE_H
