#ifndef LAB08_STATE_CHASQUARTERSTATE_H
#define LAB08_STATE_CHASQUARTERSTATE_H

#include "../IGumballMachine.h"
#include "../IState.h"
#include <iostream>

class CHasQuarterState : public IState
{
public:
	CHasQuarterState(IGumballMachine& gumballMachine, unsigned maxQuartersCount)
		: m_gumballMachine(gumballMachine)
		, m_maxQuartersCount(maxQuartersCount)
	{
	}

	void InsertQuarter() override
	{
		m_gumballMachine.AddQuarter();

		if (m_gumballMachine.GetQuartersCount() == m_maxQuartersCount)
		{
			m_gumballMachine.SetMaxQuarterCountState();
		}

		std::cout << "Quarter inserted" << std::endl;
	}

	void EjectQuarter() override
	{
		auto quartersAmount = m_gumballMachine.GetQuartersCount();
		m_gumballMachine.ReleaseQuarters(quartersAmount);
		m_gumballMachine.SetNoQuarterState();
		std::cout << quartersAmount << " quarter(s) ejected" << std::endl;
	}

	void TurnCrank() override
	{
		std::cout << "You turned..." << std::endl;
		m_gumballMachine.ReleaseQuarters(1);
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
	const unsigned m_maxQuartersCount;
};

#endif // LAB08_STATE_CHASQUARTERSTATE_H
