#ifndef DUCKFUNCTIONS_H
#define DUCKFUNCTIONS_H

#include "Duck.h"

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	std::cout << std::endl;
}

#endif // DUCKFUNCTIONS_H
