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
#include "CSaveCommand.h"
#include "CSetTitleCommand.h"
#include "ICommandFactory.h"

using CommandCreationHandler = std::function<std::unique_ptr<ICommand>(const std::shared_ptr<IDocument>&, std::ostream&, const std::string&)>;

class CDocumentCommandFactory : public ICommandFactory
{
public:
	CDocumentCommandFactory(std::shared_ptr<IDocument> doc, std::ostream& out)
		: m_doc(std::move(doc))
		, m_out(out) {};

	[[nodiscard]]
	std::unique_ptr<ICommand> CreateCommand(const std::string& description) const override
	{
		std::istringstream iss(description);

		std::string commandName;
		iss >> commandName;

		auto handler = m_commandHandler.find(commandName);
		if (handler == m_commandHandler.end())
		{
			return nullptr;
		}

		std::ostringstream oss;
		oss << iss.rdbuf();

		return handler->second(m_doc, m_out, Trim(oss.str()));
	}

private:
	std::shared_ptr<IDocument> m_doc;
	std::ostream& m_out;

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateInsertParagraphCommand(const std::shared_ptr<IDocument>& doc, std::ostream& _, const std::string& description)
	{
		std::istringstream iss(description);

		std::string rawPos;
		iss >> rawPos;
		std::optional<std::size_t> position = (rawPos == "end") ? std::nullopt : std::optional{std::stoul(rawPos)};

		std::ostringstream textOSS;
		textOSS << iss.rdbuf();

		return std::make_unique<CInsertParagraphCommand>(doc, Trim(textOSS.str()), position);
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateInsertImageCommand(const std::shared_ptr<IDocument>& doc, std::ostream& _, const std::string& description)
	{
		std::istringstream iss(description);

		std::string rawPos;
		iss >> rawPos;
		std::optional<std::size_t> position = (rawPos == "end") ? std::nullopt : std::optional{std::stoul(rawPos)};

		unsigned int width, height;
		iss >> width >> height;

		std::ostringstream rawPathOSS;
		rawPathOSS << iss.rdbuf();

		return std::make_unique<CInsertImageCommand>(doc, CPath(Trim(rawPathOSS.str())), width, height, position);
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateDeleteNodeCommand(const std::shared_ptr<IDocument>& doc, std::ostream& _, const std::string& description)
	{
		std::istringstream iss(description);

		std::size_t index;
		iss >> index;

		return std::make_unique<CDeleteNodeCommand>(doc, index);
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateSaveCommand(const std::shared_ptr<IDocument>& doc, std::ostream& _, const std::string& description)
	{
		return std::make_unique<CSaveCommand>(doc, CPath(description));
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateSetTitleCommand(const std::shared_ptr<IDocument>& doc, std::ostream& _, const std::string& description)
	{
		return std::make_unique<CSetTitleCommand>(doc, description);
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateListCommand(const std::shared_ptr<IDocument>& doc, std::ostream& out, const std::string& _)
	{
		return std::make_unique<CListCommand>(doc, out);
	}

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateHelpCommand(const std::shared_ptr<IDocument>& _0, std::ostream& out, const std::string& _1)
	{
		return std::make_unique<CHelpCommand>(out);
	}

	inline static std::map<std::string, CommandCreationHandler> m_commandHandler {
		{ "InsertParagraph", CreateInsertParagraphCommand },
		{ "InsertImage", CreateInsertImageCommand },
		{ "DeleteNode", CreateDeleteNodeCommand },
		{ "Save", CreateSaveCommand },
		{ "SetTitle", CreateSetTitleCommand },
		{ "List", CreateListCommand },
		{ "Help", CreateHelpCommand },
	};
};

#endif // LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H
