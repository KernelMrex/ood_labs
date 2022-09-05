#include "lib/DecoyDuck.h"
#include "lib/DuckFunctions.h"
#include "lib/MallardDuck.h"
#include "lib/ModelDuck.h"
#include "lib/RedheadDuck.h"
#include "lib/RubberDuck.h"
#include <cstdlib>

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(std::make_unique<FlyWithWings>());
	PlayWithDuck(modelDuck);


	return EXIT_SUCCESS;
}