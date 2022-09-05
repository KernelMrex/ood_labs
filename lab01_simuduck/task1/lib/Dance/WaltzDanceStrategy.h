#ifndef WALTZDANCESTRATEGY_H
#define WALTZDANCESTRATEGY_H

#include "IDanceStrategy.h"
#include <iostream>

class WaltzDanceStrategy : public IDanceStrategy
{
	void Dance() override
	{
		std::cout << "I'm dancing waltz!" << std::endl;
	}
};

#endif
