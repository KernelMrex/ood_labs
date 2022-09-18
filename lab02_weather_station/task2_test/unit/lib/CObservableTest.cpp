#define CATCH_CONFIG_MAIN
#include "../../../task2/lib/CObservable.h"
#include "../catch.hpp"

TEST_CASE("Self remove from observers works fine", "[c_observable]")
{
	struct SMockUpdateData
	{
	};

	class CMockObservable : public CObservable<SMockUpdateData>
	{
	public:
		SMockUpdateData GetChangedData() const final
		{
			SMockUpdateData data;
			return data;
		}
	};

	class CMockObserver : public IObserver<SMockUpdateData>
	{
	public:
		explicit CMockObserver(
			CObservable<SMockUpdateData>& currentObservable,
			int* executedTimes)
			: m_currentObservable(currentObservable)
			, m_executedTimes(executedTimes)
		{
		}

		void Update(SMockUpdateData const& data) final
		{
			m_currentObservable.RemoveObserver(*this);
			*m_executedTimes = (*m_executedTimes) + 1;
		}

	private:
		CObservable<SMockUpdateData>& m_currentObservable;
		int* m_executedTimes;
	};

	int mutableCounter = 0;
	CMockObservable observable;
	CMockObserver mockObserver1(observable, &mutableCounter);
	CMockObserver mockObserver2(observable, &mutableCounter);
	CMockObserver mockObserver3(observable, &mutableCounter);
	CMockObserver mockObserver4(observable, &mutableCounter);

	observable.RegisterObserver(mockObserver1);
	observable.RegisterObserver(mockObserver2);
	observable.RegisterObserver(mockObserver3);
	observable.RegisterObserver(mockObserver4);

	observable.NotifyObservers();

	REQUIRE(mutableCounter == 4);
}