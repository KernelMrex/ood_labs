#include "../../../../src/app/gum_ball_machine_with_state/CGumballMachine.h"
#include <gtest/gtest.h>

constexpr std::string_view SOLD_OUT = "sold out";
constexpr std::string_view WAITING_FOR_QUARTER = "waiting for quarter";
constexpr std::string_view WAITING_FOR_TURN = "waiting for turn of crank";

std::string GetGumballMachineStateDescription(unsigned ballsAmount, unsigned quartersAmount, unsigned maxQuartersAmount, const std::string& state)
{
	auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: %1% gumball%2%
Quarters buffer: %3% out of %4%
Machine is %5%
)");
	auto formatted = fmt
		% ballsAmount % (ballsAmount != 1 ? "s" : "")
		% quartersAmount % maxQuartersAmount
		% state;

	return formatted.str();
}

TEST(GumballMachineTest, EmptyGumballMachine)
{
	CGumballMachine machine(0, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));
}

TEST(GumballMachineTest, WithOneGumball)
{
	CGumballMachine machine(1, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(1, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(0, 0, 5, std::string(SOLD_OUT)));
}

TEST(GumballMachineTest, WithMultipleGumballs)
{
	CGumballMachine machine(4, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, 0, 5, std::string(WAITING_FOR_QUARTER)));
}

TEST(GumballMachineTest, EjectingMultipleQuarters)
{
	CGumballMachine machine(4, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 2, 5, std::string(WAITING_FOR_TURN)));

	machine.EjectQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));
}

TEST(GumballMachineTest, MultipleEjectingGumballsOnOneQuarter)
{
	CGumballMachine machine(4, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, 0, 5, std::string(WAITING_FOR_QUARTER)));
}

TEST(GumballMachineTest, MultipleEjectingGumballsOnMultipleQuarters)
{
	CGumballMachine machine(4, 5);
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.InsertQuarter();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(4, 2, 5, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(3, 1, 5, std::string(WAITING_FOR_TURN)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(2, 0, 5, std::string(WAITING_FOR_QUARTER)));

	machine.TurnCrank();
	ASSERT_EQ(machine.ToString(), GetGumballMachineStateDescription(2, 0, 5, std::string(WAITING_FOR_QUARTER)));
}