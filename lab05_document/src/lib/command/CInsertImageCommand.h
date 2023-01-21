#ifndef LAB05_DOCUMENT_CINSERTIMAGECOMMAND_H
#define LAB05_DOCUMENT_CINSERTIMAGECOMMAND_H

#include <utility>

#include "../document/IDocument.h"
#include "ICommand.h"

class CInsertImageCommand : public ICommand
{
public:
	CInsertImageCommand(
		std::shared_ptr<IDocument> doc,
		CPath path,
		unsigned int width,
		unsigned int height,
		std::optional<std::size_t> position)
		: m_doc(std::move(doc))
		, m_path(std::move(path))
		, m_height(height)
		, m_width(width)
		, m_position(position)
	{
	}

	void Execute() override
	{
		m_doc->InsertImage(m_path, m_width, m_height, m_position);
	}

private:
	std::shared_ptr<IDocument> m_doc;
	CPath m_path;
	unsigned int m_height;
	unsigned int m_width;
	std::optional<std::size_t> m_position;
};

#endif // LAB05_DOCUMENT_CINSERTIMAGECOMMAND_H
