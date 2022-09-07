#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "../Dance/MinuetDanceStrategy.h"
#include "../Fly/FlyWithWings.h"
#include "../Quack/QuackBehavior.h"
#include "Duck.h"

#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(
			std::make_unique<FlyWithWings>(),
			std::make_unique<QuackBehavior>(),
			std::make_unique<MinuetDanceStrategy>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

#endif
