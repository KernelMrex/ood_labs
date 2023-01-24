#ifndef LAB05_DOCUMENT_CDELETENODECOMMAND_H
#define LAB05_DOCUMENT_CDELETENODECOMMAND_H

#include "../document/IDocument.h"
#include "../document/node/CImageNode.h"
#include "../document/node/CParagraphNode.h"
#include "ICommand.h"

#include <utility>

class CDeleteNodeCommand : public ICommand
{
public:
	CDeleteNodeCommand(
		std::shared_ptr<IDocument> doc,
		std::size_t index)
		: m_doc(std::move(doc))
		, m_index(index)
	{
	}

	void Execute() override
	{
		m_deletedNode = m_doc->GetNode(m_index);
		m_doc->DeleteNode(m_index);
	}

	void Undo() override
	{
		const auto nodeType = m_deletedNode->Type();

		if (nodeType == NodeType::PARAGRAPH)
		{
			auto paragraphNode = std::dynamic_pointer_cast<CParagraphNode>(m_deletedNode);
			if (paragraphNode == nullptr)
			{
				throw std::runtime_error("invalid node stored");
			}
			m_doc->InsertParagraph(paragraphNode->Text(), m_index);
		}
		else if (nodeType == NodeType::IMAGE)
		{
			auto imageNode = std::dynamic_pointer_cast<CImageNode>(m_deletedNode);
			if (imageNode == nullptr)
			{
				throw std::runtime_error("invalid node stored");
			}
			m_doc->InsertImage(imageNode->Path(), imageNode->Width(), imageNode->Height(), m_index);
		}
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::size_t m_index;
	std::shared_ptr<INode> m_deletedNode;
};

#endif // LAB05_DOCUMENT_CDELETENODECOMMAND_H
