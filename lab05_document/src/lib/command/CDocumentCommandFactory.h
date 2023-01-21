#ifndef LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H
#define LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H

#include <functional>
#include <map>
#include <sstream>
#include <utility>

#include "../document/IDocument.h"
#include "../utils/Strings.h"
#include "CInsertParagraphCommand.h"
#include "ICommandFactory.h"

using CommandCreationHandler = std::function<std::unique_ptr<ICommand>(const std::shared_ptr<IDocument>&, const std::string&)>;

class CDocumentCommandFactory : public ICommandFactory
{
public:
	explicit CDocumentCommandFactory(std::shared_ptr<IDocument> doc)
		: m_doc(std::move(doc)){};

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

		return handler->second(m_doc, Trim(oss.str()));
	}

private:
	std::shared_ptr<IDocument> m_doc;

	[[nodiscard]]
	static std::unique_ptr<ICommand> CreateInsertParagraphCommand(const std::shared_ptr<IDocument>& doc, const std::string& description)
	{
		std::istringstream iss(description);

		std::string rawPos;
		std::string text;

		iss >> rawPos;
		std::optional<std::size_t> position = (rawPos == "end") ? std::nullopt : std::optional{std::stoul(rawPos)};

		std::ostringstream textOSS;
		textOSS << iss.rdbuf();

		return std::make_unique<CInsertParagraphCommand>(doc, Trim(textOSS.str()), position);
	}

	inline static std::map<std::string, CommandCreationHandler> m_commandHandler {
		{ "InsertParagraph", CreateInsertParagraphCommand },
	};
};

#endif // LAB05_DOCUMENT_CDOCUMENTCOMMANDFACTORY_H
