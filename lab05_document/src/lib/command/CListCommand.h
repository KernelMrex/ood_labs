#ifndef LAB05_DOCUMENT_CLISTCOMMAND_H
#define LAB05_DOCUMENT_CLISTCOMMAND_H

#include "../document/IDocument.h"
#include "../document/render/CListRenderer.h"
#include "ICommand.h"

class CListCommand : public ICommand
{
public:
	CListCommand(std::shared_ptr<IDocument> doc, std::ostream& out)
		: m_doc(std::move(doc))
		, m_out(out)
	{}

	void Execute() override
	{
		CListRenderer renderer(m_out);

		m_out << "Title: " << m_doc->GetTitle() << std::endl;
		for (std::size_t i = 0; i < m_doc->GetNodesCount(); i++)
		{
			m_doc->GetNode(i)->Render(renderer);
			m_out << std::endl;
		}
	}

	void Undo() override
	{}

private:
	std::shared_ptr<IDocument> m_doc;
	std::ostream& m_out;
};

#endif // LAB05_DOCUMENT_CLISTCOMMAND_H
