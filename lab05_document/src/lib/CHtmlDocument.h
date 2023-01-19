#ifndef LAB05_DOCUMENT_CHTMLDOCUMENT_H
#define LAB05_DOCUMENT_CHTMLDOCUMENT_H

#include "CParagraphNode.h"
#include "INode.h"
#include <memory>
#include <optional>
#include <vector>

class CHtmlDocument
{
public:
	CHtmlDocument()
		: m_nodes(std::vector<std::shared_ptr<INode>>())
	{
	}

	void InsertParagraph(const std::string& text, std::optional<std::size_t> position = std::nullopt)
	{
		auto node = std::make_shared<CParagraphNode>(text);

		if (!position.has_value())
		{
			m_nodes.push_back(node);
			return;
		}

		if (position.value() >= m_nodes.size())
		{
			throw std::range_error("cannot insert paragraph in given position");
		}

		m_nodes.insert(m_nodes.begin() + (long) position.value(), node);
	}

	[[nodiscard]]
	virtual std::size_t GetNodesCount() const
	{
		return m_nodes.size();
	}

	[[nodiscard]]
	virtual std::shared_ptr<INode> GetNode(std::size_t index) const
	{
		if (index >= m_nodes.size())
		{
			throw std::out_of_range("no such node");
		}

		return m_nodes[index];
	}

private:
	std::vector<std::shared_ptr<INode>> m_nodes;
};

#endif // LAB05_DOCUMENT_CHTMLDOCUMENT_H
