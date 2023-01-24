#ifndef LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H
#define LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H

#include <functional>
#include <map>
#include <sstream>
#include <utility>

#include "../document/IDocument.h"
#include "../utils/Strings.h"
#include "CDeleteNodeCommand.h"
#include "CHelpCommand.h"
#include "CInsertImageCommand.h"
#include "CInsertParagraphCommand.h"
#include "CListCommand.h"
#include "CRedoCommand.h"
#include "CSaveCommand.h"
#include "CSaveToHistoryCommandDecorator.h"
#include "CSetTitleCommand.h"
#include "CUndoCommand.h"
#include "ICommandFactory.h"

class CDocumentCommandFactory : public ICommandFactory
{
public:
	CDocumentCommandFactory(
		std::shared_ptr<IDocument> doc,
		std::ostream& out,
		std::shared_ptr<ICommandHistory> commandHistory,
		std::shared_ptr<ICommandHistory> redoCommandHistory)
		: m_doc(std::move(doc))
		, m_out(out)
		, m_commandHistory(std::move(commandHistory))
		, m_redoCommandHistory(std::move(redoCommandHistory))
	{
		m_commandHandlerMap = std::map<std::string, std::function<std::unique_ptr<ICommand>(const std::string&)>>{
			{ "InsertParagraph", [this](const std::string& description) { return CreateInsertParagraphCommand(description); } },
			{ "InsertImage", [this](const std::string& description) { return CreateInsertImageCommand(description); } },
			{ "DeleteNode", [this](const std::string& description) { return CreateDeleteNodeCommand(description); } },
			{ "Save", [this](const std::string& description) { return CreateSaveCommand(description); } },
			{ "SetTitle", [this](const std::string& description) { return CreateSetTitleCommand(description); } },
			{ "List", [this](const std::string& description) { return CreateListCommand(description); } },
			{ "Help", [this](const std::string& description) { return CreateHelpCommand(description); } },
			{ "Undo",  [this](const std::string& description) { return CreateUndoCommand(description); } },
			{ "Redo", [this](const std::string& description) { return CreateRedoCommand(description); } },
		};
	};

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateCommand(const std::string& description) const override
	{
		std::istringstream iss(description);

		std::string commandName;
		iss >> commandName;

		auto handler = m_commandHandlerMap.find(commandName);
		if (handler == m_commandHandlerMap.end())
		{
			return nullptr;
		}

		std::ostringstream oss;
		oss << iss.rdbuf();

		return handler->second(Trim(oss.str()));
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::ostream& m_out;
	std::shared_ptr<ICommandHistory> m_commandHistory;
	std::shared_ptr<ICommandHistory> m_redoCommandHistory;
	std::map<std::string, std::function<std::unique_ptr<ICommand>(const std::string&)>> m_commandHandlerMap;

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateInsertParagraphCommand(const std::string& description) {
		std::istringstream iss(description);

		std::string rawPos;
		iss >> rawPos;
		std::optional<std::size_t> position = (rawPos == "end") ? std::nullopt : std::optional{ std::stoul(rawPos) };

		std::ostringstream textOSS;
		textOSS << iss.rdbuf();

		return std::make_unique<CSaveToHistoryCommandDecorator>(
			std::make_shared<CInsertParagraphCommand>(m_doc, Trim(textOSS.str()), position),
			m_commandHistory,
			m_redoCommandHistory);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateInsertImageCommand(const std::string& description)
	{
		std::istringstream iss(description);

		std::string rawPos;
		iss >> rawPos;
		std::optional<std::size_t> position = (rawPos == "end") ? std::nullopt : std::optional{ std::stoul(rawPos) };

		unsigned int width, height;
		iss >> width >> height;

		std::ostringstream rawPathOSS;
		rawPathOSS << iss.rdbuf();

		return std::make_unique<CSaveToHistoryCommandDecorator>(
			std::make_unique<CInsertImageCommand>(m_doc, CPath(Trim(rawPathOSS.str())), width, height, position),
			m_commandHistory,
			m_redoCommandHistory);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateDeleteNodeCommand(const std::string& description)
	{
		std::istringstream iss(description);

		std::size_t index;
		iss >> index;

		return std::make_unique<CSaveToHistoryCommandDecorator>(
			std::make_unique<CDeleteNodeCommand>(m_doc, index),
			m_commandHistory,
			m_redoCommandHistory);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateSaveCommand(const std::string& description)
	{
		return std::make_unique<CSaveCommand>(m_doc, CPath(description));
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateSetTitleCommand(const std::string& description)
	{
		return std::make_unique<CSaveToHistoryCommandDecorator>(
			std::make_unique<CSetTitleCommand>(m_doc, description),
			m_commandHistory,
			m_redoCommandHistory);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateListCommand(const std::string&)
	{
		return std::make_unique<CListCommand>(m_doc, m_out);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateHelpCommand(const std::string&)
	{
		return std::make_unique<CHelpCommand>(m_out);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateUndoCommand(const std::string&)
	{
		return std::make_unique<CUndoCommand>(m_commandHistory, m_redoCommandHistory);
	}

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateRedoCommand(const std::string&)
	{
		return std::make_unique<CRedoCommand>(m_commandHistory, m_redoCommandHistory);
	}
};

#endif // LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H
