#ifndef COBSERVABLE_H
#define COBSERVABLE_H

#include "IObservable.h"
#include "IObserver.h"
#include <map>

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	static const uint PRIORITY_HIGH   = 400000;
	static const uint PRIORITY_NORMAL = 300000;
	static const uint PRIORITY_LOW    = 200000;

	void RegisterObserver(ObserverType& observer) override
	{
		RegisterObserver(observer, PRIORITY_NORMAL);
	}

	void RegisterObserver(ObserverType& observer, uint priority) override
	{
		m_observers.insert(std::pair(priority, &observer));
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		auto observers = m_observers;
		for (auto& observerData : observers)
		{
			observerData.second->Update(data);
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		std::erase_if(m_observers, [&observer](std::pair<uint, ObserverType*> pair) {
			return pair.second == &observer;
		});
	}

protected:
	// Классы-наследники должны перегрузить данный метод,
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::multimap<uint, ObserverType*, std::greater<uint>> m_observers;
};

#endif // COBSERVABLE_H
