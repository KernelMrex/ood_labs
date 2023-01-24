#ifndef LAB05_DOCUMENT_CAPP_H
#define LAB05_DOCUMENT_CAPP_H

#include "command/CCommandHistory.h"
#include "command/CDocumentCommandFactory.h"
#include "command/ICommand.h"
#include "command/ICommandHistory.h"
#include "document/CHtmlDocument.h"
#include <istream>
#include <memory>
#include <utility>

class CApp
{
public:
	CApp(
		std::istream& in,
		std::ostream& out,
		std::shared_ptr<IFileStorage> fileStorage)
		: m_in(in)
		, m_out(out)
		, m_fileStorage(std::move(fileStorage))
	{
	}

	void ListenAndServe()
	{
		auto doc = std::make_shared<CHtmlDocument>(m_fileStorage);
		auto undoCommandHistory = std::make_shared<CCommandHistory>();
		auto commandFactory = std::make_shared<CDocumentCommandFactory>(doc, m_out, undoCommandHistory);

		for (std::string line; std::getline(m_in, line);)
		{
			if (line.empty())
			{
				break;
			}

			std::shared_ptr<ICommand> command(commandFactory->CreateCommand(line).release());
			if (command == nullptr)
			{
				PrintInvalidCommandError();
				continue;
			}
			command->Execute();
		}
	}

private:
	std::istream& m_in;
	std::ostream& m_out;
	std::shared_ptr<IFileStorage> m_fileStorage;

	void PrintInvalidCommandError()
	{
		m_out << "Invalid command" << std::endl;
		m_out.flush();
	}
};

#endif // LAB05_DOCUMENT_CAPP_H
