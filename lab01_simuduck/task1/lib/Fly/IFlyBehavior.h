#ifndef IFLYBEHAVIOR_H
#define IFLYBEHAVIOR_H

struct IFlyBehavior
{
	virtual ~IFlyBehavior(){};
	virtual void Fly() = 0;
};

#endif
