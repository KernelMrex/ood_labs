#ifndef CANTDANCESTRATEGY_H
#define CANTDANCESTRATEGY_H

#include "IDanceStrategy.h"
#include <iostream>

class CantDanceStrategy : public IDanceStrategy
{
	void Dance() override
	{
		std::cout << "I can't dance!" << std::endl;
	}
};

#endif
