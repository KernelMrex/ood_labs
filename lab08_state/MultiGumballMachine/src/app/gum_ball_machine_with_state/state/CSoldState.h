#ifndef LAB08_STATE_CSOLDSTATE_H
#define LAB08_STATE_CSOLDSTATE_H

#include "../IGumballMachine.h"
#include "../IState.h"
#include <iostream>

class CSoldState : public IState
{
public:
	explicit CSoldState(IGumballMachine& gumballMachine)
		: m_gumballMachine(gumballMachine)
	{
	}

	void InsertQuarter() override
	{
		std::cout << "Please wait, we're already giving you a gumball\n";
	}

	void EjectQuarter() override
	{
		std::cout << "Sorry you already turned the crank\n";
	}

	void TurnCrank() override
	{
		std::cout << "Turning twice doesn't get you another gumball\n";
	}

	void Dispense() override
	{
		m_gumballMachine.ReleaseBall();
		if (m_gumballMachine.GetBallCount() == 0)
		{
			std::cout << "Oops, out of gumballs\n";
			m_gumballMachine.SetSoldOutState();
			return;
		}

		if (m_gumballMachine.GetQuartersCount() > 0)
		{
			m_gumballMachine.SetHasQuarterState();
			return;
		}

		m_gumballMachine.SetNoQuarterState();
	}

	[[nodiscard]]
	std::string ToString() const override
	{
		return "delivering a gumball";
	}

private:
	IGumballMachine& m_gumballMachine;
};

#endif // LAB08_STATE_CSOLDSTATE_H
