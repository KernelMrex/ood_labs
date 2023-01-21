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
		m_doc->SetTitle(m_title);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::string m_title;
};

#endif // LAB05_DOCUMENT_CSETTITLECOMMAND_H
