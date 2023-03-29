#ifndef LAB08_STATE_CHASQUARTERSTATE_H
#define LAB08_STATE_CHASQUARTERSTATE_H

#include "../IGumballMachine.h"
#include "../IState.h"
#include <iostream>

class CHasQuarterState : public IState
{
public:
	explicit CHasQuarterState(IGumballMachine& gumballMachine)
		: m_gumballMachine(gumballMachine)
	{
	}

	void InsertQuarter() override
	{
		std::cout << "You can't insert another quarter\n";
	}

	void EjectQuarter() override
	{
		std::cout << "Quarter returned\n";
		m_gumballMachine.SetNoQuarterState();
	}

	void TurnCrank() override
	{
		std::cout << "You turned...\n";
		m_gumballMachine.SetSoldState();
	}

	void Dispense() override
	{
		std::cout << "No gumball dispensed\n";
	}

	[[nodiscard]]
	std::string ToString() const override
	{
		return "waiting for turn of crank";
	}

private:
	IGumballMachine& m_gumballMachine;
};

#endif // LAB08_STATE_CHASQUARTERSTATE_H
