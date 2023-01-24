#ifndef LAB05_DOCUMENT_ICOMMANDHISTORY_H
#define LAB05_DOCUMENT_ICOMMANDHISTORY_H

#include "ICommand.h"
#include <memory>

class ICommandHistory
{
public:
	virtual void Push(std::shared_ptr<ICommand> command) = 0;

	virtual std::shared_ptr<ICommand> Pop() = 0;

	~ICommandHistory() = default;
};

#endif // LAB05_DOCUMENT_ICOMMANDHISTORY_H

