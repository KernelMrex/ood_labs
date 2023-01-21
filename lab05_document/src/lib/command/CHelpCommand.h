#ifndef LAB05_DOCUMENT_CHELPCOMMAND_H
#define LAB05_DOCUMENT_CHELPCOMMAND_H

#include "ICommand.h"

#include <ostream>

class CHelpCommand : public ICommand
{
public:
	explicit CHelpCommand(std::ostream& out)
		: m_out(out)
	{
	}

	void Execute() override
	{
		m_out << "InsertParagraph [<position>|end] <text>" << std::endl
			  << "InsertImage [<position>|end] <width> <height> <path>" << std::endl
			  << "SetTitle <text>" << std::endl
			  << "List" << std::endl
			  << "DeleteItem <position>" << std::endl
			  << "Help" << std::endl
			  << "Save <path>" << std::endl;
	}

private:
	std::ostream& m_out;
};

#endif // LAB05_DOCUMENT_CHELPCOMMAND_H
