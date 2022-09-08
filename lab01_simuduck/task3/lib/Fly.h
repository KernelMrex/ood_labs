#ifndef FLY_H
#define FLY_H

#include <iostream>

using FlyStrategy = std::function<void()>;

void FlyNoWay()
{
}

FlyStrategy GetFlyWithWingsFn()
{
	uint timesFlew = 0;
	return [&timesFlew]() -> void {
		std::cout << "I'm flying with wings!! Times: " << timesFlew++ << std::endl;
	};
}

#endif
