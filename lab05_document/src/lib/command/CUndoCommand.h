#ifndef LAB05_DOCUMENT_CUNDOCOMMAND_H
#define LAB05_DOCUMENT_CUNDOCOMMAND_H

#include "ICommand.h"
#include "ICommandHistory.h"

class CUndoCommand : public ICommand
{
public:
	explicit CUndoCommand(
		std::shared_ptr<ICommandHistory> commandHistory,
		std::shared_ptr<ICommandHistory> redoCommandHistory)
		: m_commandHistory(std::move(commandHistory))
		, m_redoCommandHistory(std::move(redoCommandHistory))
	{
	}

	void Execute() override
	{
		auto command = m_commandHistory->Pop();
		if (command == nullptr)
		{
			return;
		}
		m_redoCommandHistory->Push(command);
		command->Undo();
	}

	void Undo() override
	{
	}

private:
	std::shared_ptr<ICommandHistory> m_commandHistory;
	std::shared_ptr<ICommandHistory> m_redoCommandHistory;
};

#endif // LAB05_DOCUMENT_CUNDOCOMMAND_H
