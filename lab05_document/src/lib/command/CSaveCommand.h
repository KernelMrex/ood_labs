#ifndef LAB05_DOCUMENT_CSAVECOMMAND_H
#define LAB05_DOCUMENT_CSAVECOMMAND_H

#include "../document/IDocument.h"

#include "ICommand.h"

class CSaveCommand : public ICommand
{
public:
	CSaveCommand(std::shared_ptr<IDocument> doc, CPath path)
		: m_doc(std::move(doc))
		, m_path(std::move(path))
	{
	}

	void Execute() override
	{
		m_doc->Save(m_path);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	CPath m_path;
};

#endif // LAB05_DOCUMENT_CSAVECOMMAND_H
