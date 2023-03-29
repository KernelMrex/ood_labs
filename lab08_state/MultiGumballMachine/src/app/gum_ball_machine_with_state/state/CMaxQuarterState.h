#ifndef LAB08_STATE_CMAXQUARTERSTATE_H
#define LAB08_STATE_CMAXQUARTERSTATE_H

#include "../IState.h"

class CMaxQuarterState : public IState
{
public:
	explicit CMaxQuarterState(IGumballMachine& gumballMachine)
		: m_gumballMachine(gumballMachine)
	{
	}

	void InsertQuarter() override
	{
		std::cout << "Could not insert any more coins!" << std::endl;
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
		std::cout << "No gumball dispensed" << std::endl;
	}

	[[nodiscard]]
	std::string ToString() const override
	{
		return "quarters buffer is full";
	}

private:
	IGumballMachine& m_gumballMachine;
};

#endif // LAB08_STATE_CMAXQUARTERSTATE_H
