#ifndef LAB05_DOCUMENT_CINSERTPARAGRAPHCOMMAND_H
#define LAB05_DOCUMENT_CINSERTPARAGRAPHCOMMAND_H

#include "../document/IDocument.h"
#include "ICommand.h"
#include <memory>
#include <optional>
#include <utility>

class CInsertParagraphCommand : public ICommand
{
public:
	CInsertParagraphCommand(
		const std::shared_ptr<IDocument>& doc,
		std::string text,
		std::optional<std::size_t> position)
		: m_doc(doc)
		, m_text(std::move(text))
		, m_position(position)
	{
	}

	void Execute() override
	{
		m_doc->InsertParagraph(m_text, m_position);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::string m_text;
	std::optional<std::size_t> m_position;
};

#endif // LAB05_DOCUMENT_CINSERTPARAGRAPHCOMMAND_H
