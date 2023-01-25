#ifndef LAB05_DOCUMENT_CREPLACETEXTCOMMAND_H
#define LAB05_DOCUMENT_CREPLACETEXTCOMMAND_H

#include <utility>

#include "../document/IDocument.h"
#include "../document/node/CImageNode.h"
#include "ICommand.h"

class CReplaceTextCommand : public ICommand
{
public:
	CReplaceTextCommand(
		std::shared_ptr<IDocument> doc,
		std::size_t pos,
		std::string text)
		: m_doc(std::move(doc))
		, m_pos(pos)
		, m_text(std::move(text))
	{
	}

	void Execute() override
	{
		auto node = m_doc->GetNode(m_pos);
		auto nodeType = node->Type();
		if (nodeType == NodeType::PARAGRAPH)
		{
			auto paragraphNode = std::dynamic_pointer_cast<CParagraphNode>(node);
			if (paragraphNode == nullptr)
			{
				throw std::runtime_error("invalid node stored");
			}
			m_prevText = paragraphNode->Text();

			m_doc->DeleteNode(m_pos);
			m_doc->InsertParagraph(m_text, m_pos);
			return;
		}

		throw std::invalid_argument("node with given pos in not paragraph");
	}

	void Undo() override
	{
		auto node = m_doc->GetNode(m_pos);
		auto paragraphNode = std::dynamic_pointer_cast<CParagraphNode>(node);
		if (paragraphNode == nullptr)
		{
			throw std::runtime_error("invalid node stored");
		}
		m_doc->DeleteNode(m_pos);
		m_doc->InsertParagraph(m_prevText, m_pos);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::size_t m_pos;
	std::string m_text;
	std::string m_prevText;
};

#endif // LAB05_DOCUMENT_CREPLACETEXTCOMMAND_H
