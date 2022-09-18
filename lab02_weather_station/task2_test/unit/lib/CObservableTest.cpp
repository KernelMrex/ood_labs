#define CATCH_CONFIG_MAIN
#include "../../../task2/lib/CObservable.h"
#include "../catch.hpp"

TEST_CASE("Self remove from observers works fine", "[c_observable]")
{
	struct SMockUpdateData
	{
	};

	class MockObservable : public CObservable<SMockUpdateData>
	{
	public:
		[[nodiscard]] SMockUpdateData GetChangedData() const final
		{
			SMockUpdateData data;
			return data;
		}
	};

	class MockObserver : public IObserver<SMockUpdateData>
	{
	public:
		explicit MockObserver(
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
	MockObservable observable;
	MockObserver mockObserver1(observable, &mutableCounter);
	MockObserver mockObserver2(observable, &mutableCounter);
	MockObserver mockObserver3(observable, &mutableCounter);
	MockObserver mockObserver4(observable, &mutableCounter);

	observable.RegisterObserver(mockObserver1);
	observable.RegisterObserver(mockObserver2);
	observable.RegisterObserver(mockObserver3);
	observable.RegisterObserver(mockObserver4);

	observable.NotifyObservers();

	REQUIRE(mutableCounter == 4);
}