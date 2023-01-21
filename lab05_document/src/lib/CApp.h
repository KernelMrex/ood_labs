#ifndef LAB05_DOCUMENT_CAPP_H
#define LAB05_DOCUMENT_CAPP_H

#include "command/ICommand.h"
#include "command/CDocumentCommandFactory.h"
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
		auto commandFactory = std::make_shared<CDocumentCommandFactory>(doc);

		for (std::string line; std::getline(m_in, line);)
		{
			if (line.empty())
			{
				break;
			}

			auto command = commandFactory->CreateCommand(line);
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
