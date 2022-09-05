#ifndef MINUETDANCESTRATEGY_H
#define MINUETDANCESTRATEGY_H

#include "IDanceStrategy.h"
#include <iostream>

class MinuetDanceStrategy : public IDanceStrategy
{
	void Dance() override
	{
		std::cout << "I'm dancing minuet" << std::endl;
	}
};

#endif
