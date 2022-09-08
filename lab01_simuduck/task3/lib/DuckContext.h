#ifndef FLYBEHAVIORCONTEXT_H
#define FLYBEHAVIORCONTEXT_H

#include <functional>
#include <utility>

using FlyStrategy = std::function<void()>;
using QuackStrategy = std::function<void()>;
using DanceStrategy = std::function<void()>;

class DuckContext
{
public:
	DuckContext(
		FlyStrategy flyStrategy,
		QuackStrategy quackStrategy,
		DanceStrategy danceStrategy)
		: m_flyStrategy(std::move(flyStrategy))
		, m_quackStrategy(std::move(quackStrategy))
		, m_danceStrategy(std::move(danceStrategy))
	{
	}

	void PerformFly() const
	{
		m_flyStrategy();
	}

	void PerformQuack() const
	{
		m_quackStrategy();
	}

	void PerformDanceStrategy() const
	{
		m_danceStrategy();
	}

private:
	FlyStrategy m_flyStrategy;
	QuackStrategy m_quackStrategy;
	DanceStrategy m_danceStrategy;
};

#endif
