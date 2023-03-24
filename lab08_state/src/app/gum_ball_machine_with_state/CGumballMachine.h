#ifndef LAB08_STATE_CGUMBALLMACHINE_H
#define LAB08_STATE_CGUMBALLMACHINE_H

#include "IGumballMachine.h"
#include "IState.h"
#include "state/CHasQuarterState.h"
#include "state/CNoQuarterState.h"
#include "state/CSoldOutState.h"
#include "state/CSoldState.h"
#include <boost/format.hpp>
#include <iostream>
#include <memory>

class CGumballMachine : public IGumballMachine
{
public:
	explicit CGumballMachine(unsigned numBalls)
		: m_count(numBalls)
	{

		if (m_count > 0)
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
Machine is %3%
)");
		return (fmt % m_count % (m_count != 1 ? "s" : "") % m_currentState->ToString()).str();
	}

private:
	[[nodiscard]]
	unsigned GetBallCount() const override
	{
		return m_count;
	}

	void ReleaseBall() override
	{
		if (m_count != 0)
		{
			std::cout << "A gumball comes rolling out the slot...\n";
			--m_count;
		}
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
		m_currentState = std::make_unique<CHasQuarterState>(*this);
	}

private:
	unsigned m_count = 0;
	std::unique_ptr<IState> m_currentState;
};

#endif // LAB08_STATE_CGUMBALLMACHINE_H
