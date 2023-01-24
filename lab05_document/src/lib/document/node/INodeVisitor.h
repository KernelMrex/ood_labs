#ifndef LAB05_DOCUMENT_INODEVISITOR_H
#define LAB05_DOCUMENT_INODEVISITOR_H

#include "CImageNode.h"
#include "CParagraphNode.h"

class CImageNode;
class CParagraphNode;

class INodeVisitor
{
public:
	virtual void Visit(const CImageNode& node) = 0;
	virtual void Visit(const CParagraphNode& node) = 0;
	virtual ~INodeVisitor() = default;
};

#endif // LAB05_DOCUMENT_INODEVISITOR_H
