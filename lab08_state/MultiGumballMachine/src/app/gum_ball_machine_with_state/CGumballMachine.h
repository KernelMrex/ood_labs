#ifndef LAB08_STATE_CGUMBALLMACHINE_H
#define LAB08_STATE_CGUMBALLMACHINE_H

#include "IGumballMachine.h"
#include "IState.h"
#include "state/CHasQuarterState.h"
#include "state/CMaxQuarterState.h"
#include "state/CNoQuarterState.h"
#include "state/CSoldOutState.h"
#include "state/CSoldState.h"
#include <boost/format.hpp>
#include <iostream>
#include <memory>

class CGumballMachine : public IGumballMachine
{
public:
	explicit CGumballMachine(unsigned numBalls, unsigned maxQuartersCount)
		: m_ballsCount(numBalls)
		, m_maxQuartersCount(maxQuartersCount)
	{
		if (m_ballsCount > 0)
		{
			m_currentState = std::make_unique<CNoQuarterState>(*this);
		}
		else
		{
			m_currentState = std::make_unique<CSoldOutState>(*this);
		}
	}

	void EjectQuarter()
	{
		m_currentState->EjectQuarter();
	}

	void InsertQuarter()
	{
		m_currentState->InsertQuarter();
	}

	void TurnCrank()
	{
		m_currentState->TurnCrank();
		m_currentState->Dispense();
	}

	[[nodiscard]]
	std::string ToString()const
	{
		auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: %1% gumball%2%
Quarters buffer: %3% out of %4%
Machine is %5%
)");

		auto formatted = fmt
			% m_ballsCount % (m_ballsCount != 1 ? "s" : "")
			% m_quartersCount % m_maxQuartersCount
			% m_currentState->ToString();

		return formatted.str();
	}

private:
	[[nodiscard]]
	unsigned GetBallCount() const override
	{
		return m_ballsCount;
	}

	[[nodiscard]]
	unsigned int GetQuartersCount() const override
	{
		return m_quartersCount;
	}

	void ReleaseBall() override
	{
		if (m_ballsCount != 0)
		{
			std::cout << "A gumball comes rolling out the slot...\n";
			--m_ballsCount;
		}
	}

	void ReleaseQuarters(unsigned int amount) override
	{
		m_quartersCount -= std::min(amount, GetQuartersCount());
	}

	void AddQuarter() override
	{
		m_quartersCount++;
	}

	void SetSoldOutState() override
	{
		m_currentState = std::make_unique<CSoldOutState>(*this);
	}

	void SetNoQuarterState() override
	{
		m_currentState = std::make_unique<CNoQuarterState>(*this);
	}

	void SetSoldState() override
	{
		m_currentState = std::make_unique<CSoldState>(*this);
	}

	void SetHasQuarterState() override
	{
		m_currentState = std::make_unique<CHasQuarterState>(*this, m_maxQuartersCount);
	}

	void SetMaxQuarterCountState() override
	{
		m_currentState = std::make_unique<CMaxQuarterState>(*this);
	}

	unsigned m_ballsCount = 0;
	unsigned m_quartersCount = 0;
	const unsigned m_maxQuartersCount;
	std::unique_ptr<IState> m_currentState;
};

#endif // LAB08_STATE_CGUMBALLMACHINE_H
