#include "../../../../src/app/gum_ball_machine_with_state/CGumballMachine.h"
#include <gtest/gtest.h>

constexpr std::string_view SOLD_OUT = "sold out";
constexpr std::string_view WAITING_FOR_QUARTER = "waiting for quarter";
constexpr std::string_view WAITING_FOR_TURN = "waiting for turn of crank";

std::string GetGumballMachineStateDescription(unsigned amount, const std::string& state)
{
	auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: %1% gumball%2%
Machine is %3%
)");
	return (fmt % amount % (amount != 1 ? "s" : "") % state).str();
}

TEST(GumballMachineTest, EmptyGumballMachine)
{
	CGumballMachine machine(0);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));
}

TEST(GumballMachineTest, WithOneGumball)
{
	CGumballMachine machine(1);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, std::string(WAITING_FOR_TURN)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, std::string(SOLD_OUT)));
}

TEST(GumballMachineTest, WithMultipleGumballs)
{
	CGumballMachine machine(4);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, std::string(WAITING_FOR_TURN)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, std::string(WAITING_FOR_QUARTER)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, std::string(WAITING_FOR_QUARTER)));
}