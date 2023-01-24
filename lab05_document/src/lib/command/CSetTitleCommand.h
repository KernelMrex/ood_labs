#ifndef LAB05_DOCUMENT_CSETTITLECOMMAND_H
#define LAB05_DOCUMENT_CSETTITLECOMMAND_H

#include "../document/IDocument.h"
#include "ICommand.h"

class CSetTitleCommand : public ICommand
{
public:
	CSetTitleCommand(std::shared_ptr<IDocument> doc, std::string title)
		: m_doc(std::move(doc))
		, m_title(std::move(title))
	{
	}

	void Execute() override
	{
		m_prevTitle = m_doc->GetTitle();
		m_doc->SetTitle(m_title);
	}

	void Undo() override
	{
		m_doc->SetTitle(m_prevTitle);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::string m_title;
	std::string m_prevTitle;
};

#endif // LAB05_DOCUMENT_CSETTITLECOMMAND_H
