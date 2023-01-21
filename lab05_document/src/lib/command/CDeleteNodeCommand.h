#ifndef LAB05_DOCUMENT_CDELETENODECOMMAND_H
#define LAB05_DOCUMENT_CDELETENODECOMMAND_H

#include "../document/IDocument.h"
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
		m_doc->DeleteNode(m_index);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::size_t m_index;
};

#endif // LAB05_DOCUMENT_CDELETENODECOMMAND_H
