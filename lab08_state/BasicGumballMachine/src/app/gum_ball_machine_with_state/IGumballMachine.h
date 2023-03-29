#ifndef LAB08_STATE_IGUMBALLMACHINE_H
#define LAB08_STATE_IGUMBALLMACHINE_H

class IGumballMachine
{
public:
	virtual void ReleaseBall() = 0;

	[[nodiscard]]
	virtual unsigned GetBallCount() const = 0;

	virtual void SetSoldOutState() = 0;

	virtual void SetNoQuarterState() = 0;

	virtual void SetSoldState() = 0;

	virtual void SetHasQuarterState() = 0;

	virtual ~IGumballMachine() = default;
};

#endif // LAB08_STATE_IGUMBALLMACHINE_H
