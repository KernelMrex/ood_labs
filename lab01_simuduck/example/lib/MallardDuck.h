#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"
#include "FlyWithWings.h"
#include "QuackBehavior.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

#endif
