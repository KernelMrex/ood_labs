#ifndef LAB05_DOCUMENT_INODE_H
#define LAB05_DOCUMENT_INODE_H

class IRenderer;

class INode
{
public:
	virtual void Render(IRenderer& renderer) const = 0;
	virtual ~INode() = default;
};

#endif // LAB05_DOCUMENT_INODE_H
