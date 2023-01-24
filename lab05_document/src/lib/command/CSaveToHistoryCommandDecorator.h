#ifndef LAB05_DOCUMENT_CSAVETOHISTORYCOMMANDDECORATOR_H
#define LAB05_DOCUMENT_CSAVETOHISTORYCOMMANDDECORATOR_H

#include "ICommand.h"
#include "ICommandHistory.h"
#include <memory>

class CSaveToHistoryCommandDecorator : public ICommand
{
public:
	CSaveToHistoryCommandDecorator(
		std::shared_ptr<ICommand> wrappee,
		std::shared_ptr<ICommandHistory> commandHistory,
		std::shared_ptr<ICommandHistory> redoCommandHistory)
		: m_wrappee(std::move(wrappee))
		, m_commandHistory(std::move(commandHistory))
		, m_redoCommandHistory(std::move(redoCommandHistory))
	{
	}

	void Execute() override
	{
		m_commandHistory->Push(std::make_shared<CSaveToHistoryCommandDecorator>(
			m_wrappee, m_commandHistory, m_redoCommandHistory));
		m_redoCommandHistory->Clear();
		m_wrappee->Execute();
	}

	void Undo() override
	{
		m_wrappee->Undo();
	}

	[[nodiscard]]
	std::shared_ptr<ICommand> GetWrappee() const
	{
		return m_wrappee;
	}

private:
	std::shared_ptr<ICommand> m_wrappee;
	std::shared_ptr<ICommandHistory> m_commandHistory;
	std::shared_ptr<ICommandHistory> m_redoCommandHistory;
};

#endif // LAB05_DOCUMENT_CSAVETOHISTORYCOMMANDDECORATOR_H
