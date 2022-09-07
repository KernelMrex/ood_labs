#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	FlyWithWings()
		: m_flyTimes(0)
	{
	}

	void Fly() override
	{
		std::cout << "I'm flying with wings!! Times: " << ++m_flyTimes << std::endl;
	}

private:
	unsigned int m_flyTimes;
};

#endif
