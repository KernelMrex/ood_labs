#ifndef LAB05_DOCUMENT_CUNDOCOMMAND_H
#define LAB05_DOCUMENT_CUNDOCOMMAND_H

#include "ICommand.h"
#include "ICommandHistory.h"

class CUndoCommand : public ICommand
{
public:
	explicit CUndoCommand(
		std::shared_ptr<ICommandHistory> commandHistory)
		: m_commandHistory(std::move(commandHistory))
	{
	}

	void Execute() override
	{
		auto command = m_commandHistory->Pop();
		if (command == nullptr)
		{
			return;
		}
		command->Undo();
	}

	void Undo() override
	{
	}

private:
	std::shared_ptr<ICommandHistory> m_commandHistory;
};

#endif // LAB05_DOCUMENT_CUNDOCOMMAND_H
