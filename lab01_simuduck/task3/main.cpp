#include "lib/Dance.h"
#include "lib/DuckContext.h"
#include "lib/Fly.h"
#include "lib/Quack.h"
#include <cstdlib>
#include <iostream>

void PlayWithDuck(const DuckContext& duckCtx)
{
	duckCtx.PerformQuack();
	duckCtx.PerformFly();
	duckCtx.PerformDanceStrategy();
	std::cout << std::endl;
}

int main()
{
	DuckContext mallardDuck(FlyWithWings, Quack, Waltz);
	PlayWithDuck(mallardDuck);

	DuckContext redheadDuck(FlyWithWings, Quack, Minuet);
	PlayWithDuck(redheadDuck);

	DuckContext rubberDuck(FlyWithWings, Squeak, CantDance);
	PlayWithDuck(rubberDuck);

	DuckContext decoyDuck(FlyNoWay, Mute, CantDance);
	PlayWithDuck(decoyDuck);

	DuckContext modelDuck(FlyNoWay, Quack, CantDance);
	PlayWithDuck(decoyDuck);

	return EXIT_SUCCESS;
}