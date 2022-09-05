#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "../Fly/FlyNoWay.h"
#include "../Quack/SqueakBehavior.h"
#include "Duck.h"
#include <iostream>

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(
			std::make_unique<FlyNoWay>(),
			std::make_unique<SqueakBehavior>(),
			std::make_unique<CantDanceStrategy>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm rubber duck" << std::endl;
	}
};

#endif
