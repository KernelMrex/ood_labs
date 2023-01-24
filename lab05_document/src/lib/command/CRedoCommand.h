#ifndef LAB05_DOCUMENT_CREDOCOMMAND_H
#define LAB05_DOCUMENT_CREDOCOMMAND_H

#include "ICommand.h"
#include "ICommandHistory.h"
#include <memory>

class CRedoCommand : public ICommand
{
public:
	CRedoCommand(
		std::shared_ptr<ICommandHistory> undoCommandHistory,
		std::shared_ptr<ICommandHistory> redoCommandHistory)
		: m_undoCommandHistory(std::move(undoCommandHistory))
		, m_redoCommandHistory(std::move(redoCommandHistory))
	{
	}

	void Execute() override
	{
		auto command = m_redoCommandHistory->Pop();
		if (command == nullptr)
		{
			return;
		}
		m_undoCommandHistory->Push(command);
		command->Execute();
	}

	void Undo() override
	{
	}

private:
	std::shared_ptr<ICommandHistory> m_undoCommandHistory;
	std::shared_ptr<ICommandHistory> m_redoCommandHistory;
};

#endif // LAB05_DOCUMENT_CREDOCOMMAND_H
