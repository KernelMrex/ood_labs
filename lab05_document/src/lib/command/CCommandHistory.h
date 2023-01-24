#ifndef LAB05_DOCUMENT_CCOMMANDHISTORY_H
#define LAB05_DOCUMENT_CCOMMANDHISTORY_H

#include "ICommandHistory.h"

#include <deque>

class CCommandHistory : public ICommandHistory
{
public:
	explicit CCommandHistory(std::size_t maxHistorySize = 10)
		: m_history(std::deque<std::shared_ptr<ICommand>>())
		, m_maxHistorySize(maxHistorySize){};

	void Push(std::shared_ptr<ICommand> command) override
	{
		if (m_history.size() > m_maxHistorySize)
		{
			m_history.pop_front();
		}

		m_history.push_back(command);
	}

	std::shared_ptr<ICommand> Pop() override
	{
		if (m_history.empty())
		{
			return nullptr;
		}

		std::shared_ptr<ICommand> cmd(m_history.back());
		m_history.pop_back();
		return cmd;
	}

	void Clear() override
	{
		m_history.clear();
	}

private:
	std::deque<std::shared_ptr<ICommand>> m_history;
	std::size_t m_maxHistorySize;
};

#endif // LAB05_DOCUMENT_CCOMMANDHISTORY_H
