#ifndef LAB05_DOCUMENT_CIMAGENODE_H
#define LAB05_DOCUMENT_CIMAGENODE_H

#include <utility>

#include "../../file/CPath.h"
#include "INode.h"
#include "INodeVisitor.h"

class CImageNode : public INode
{
public:
	CImageNode(CPath path, unsigned int width, unsigned int height)
		: m_path(std::move(path))
		, m_width(width)
		, m_height(height)
	{
	}

	void Render(INodeVisitor& renderer) const override;

	[[nodiscard]]
	NodeType Type() const override
	{
		return NodeType::IMAGE;
	}

	[[nodiscard]]
	const CPath& Path() const
	{
		return m_path;
	}

	[[nodiscard]]
	unsigned int Width() const
	{
		return m_width;
	}

	[[nodiscard]]
	unsigned int Height() const
	{
		return m_height;
	}

private:
	CPath m_path;
	unsigned int m_width, m_height;
};

#endif // LAB05_DOCUMENT_CIMAGENODE_H
