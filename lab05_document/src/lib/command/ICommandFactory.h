#ifndef LAB05_DOCUMENT_ICOMMANDFACTORY_H
#define LAB05_DOCUMENT_ICOMMANDFACTORY_H

#include "ICommand.h"
#include <memory>
#include <string>

class ICommandFactory
{
public:
	[[nodiscard]]
	virtual std::unique_ptr<ICommand> CreateCommand(const std::string& description) const = 0;

	virtual ~ICommandFactory() = default;
};

#endif // LAB05_DOCUMENT_ICOMMANDFACTORY_H
