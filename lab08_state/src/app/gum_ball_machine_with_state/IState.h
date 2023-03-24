#ifndef LAB08_STATE_ISTATE_H
#define LAB08_STATE_ISTATE_H

#include <string>

class IState
{
public:
	virtual void InsertQuarter() = 0;

	virtual void EjectQuarter() = 0;

	virtual void TurnCrank() = 0;

	virtual void Dispense() = 0;

	[[nodiscard]]
	virtual std::string ToString() const = 0;

	virtual ~IState() = default;
};

#endif // LAB08_STATE_ISTATE_H
