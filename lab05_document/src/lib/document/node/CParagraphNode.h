#ifndef LAB05_DOCUMENT_CPARAGRAPHNODE_H
#define LAB05_DOCUMENT_CPARAGRAPHNODE_H

#include "INode.h"
#include <string>

class CParagraphNode : public INode
{
public:
	explicit CParagraphNode(std::string text)
		: m_text(std::move(text))
	{
	}

	void Render(INodeVisitor& renderer) const override;

	[[nodiscard]]
	NodeType Type() const override
	{
		return NodeType::PARAGRAPH;
	}

	[[nodiscard]]
	std::string Text() const
	{
		return m_text;
	}

private:
	std::string m_text;
};

#endif // LAB05_DOCUMENT_CPARAGRAPHNODE_H
