#include "lib/Dance.h"
#include "lib/Display.h"
#include "lib/DuckContext.h"
#include "lib/Fly.h"
#include "lib/Quack.h"
#include <cstdlib>
#include <iostream>

void DrawDuck(const DuckContext& duck)
{
	duck.PerformDisplay();
}

void PlayWithDuck(const DuckContext& duckCtx)
{
	DrawDuck(duckCtx);
	duckCtx.PerformQuack();
	duckCtx.PerformFly();
	duckCtx.PerformFly();
	duckCtx.PerformDanceStrategy();
	std::cout << std::endl;
}

int main()
{
	DuckContext mallardDuck(MallardDuckDisplay, GetFlyWithWingsFn(), Quack, Waltz);
	PlayWithDuck(mallardDuck);

	DuckContext redheadDuck(RedheadDuckDisplay, GetFlyWithWingsFn(), Quack, Minuet);
	PlayWithDuck(redheadDuck);

	DuckContext rubberDuck(RubberDuckDisplay, GetFlyWithWingsFn(), Squeak, CantDance);
	PlayWithDuck(rubberDuck);

	DuckContext decoyDuck(DecoyDuckDisplay, FlyNoWay, Mute, CantDance);
	PlayWithDuck(decoyDuck);

	DuckContext modelDuck(ModelDuckDisplay, FlyNoWay, Quack, CantDance);
	PlayWithDuck(decoyDuck);

	return EXIT_SUCCESS;
}