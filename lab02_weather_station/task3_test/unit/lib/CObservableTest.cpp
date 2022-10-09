#define CATCH_CONFIG_MAIN
#include "../../../../catch.hpp"
#include "../../../task3/lib/CObservable.h"

TEST_CASE("CObservable unit tests", "[c_observable]")
{
	SECTION("Self remove from observers works fine")
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

	SECTION("Prioritizing queue works fine")
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
			CMockObserver(
				uint* mustBeCalledNumber,
				uint calledNumber)
				: m_mustBeCalledNumber(mustBeCalledNumber)
				, m_calledNumber(calledNumber)
			{
			}

			void Update(SMockUpdateData const& data) final
			{
				++(*m_mustBeCalledNumber);
				REQUIRE(*m_mustBeCalledNumber == m_calledNumber);
			}

		private:
			uint* m_mustBeCalledNumber;
			uint m_calledNumber;
		};


		WHEN("No priority defined")
		{
			uint mutableCounter = 0;
			CMockObservable observable;
			CMockObserver mockObserver1(&mutableCounter, 1);
			CMockObserver mockObserver2(&mutableCounter, 2);
			CMockObserver mockObserver3(&mutableCounter, 3);
			CMockObserver mockObserver4(&mutableCounter, 4);

			observable.RegisterObserver(mockObserver1);
			observable.RegisterObserver(mockObserver2);
			observable.RegisterObserver(mockObserver3);
			observable.RegisterObserver(mockObserver4);

			observable.NotifyObservers();
		}

		WHEN("Priority are higher and lower")
		{
			uint mutableCounter = 0;
			CMockObservable observable;
			CMockObserver mockObserver1(&mutableCounter, 2);
			CMockObserver mockObserver2(&mutableCounter, 1);
			CMockObserver mockObserver3(&mutableCounter, 4);
			CMockObserver mockObserver4(&mutableCounter, 3);

			observable.RegisterObserver(mockObserver1);
			observable.RegisterObserver(mockObserver2, CMockObservable::PRIORITY_HIGH);
			observable.RegisterObserver(mockObserver3, CMockObservable::PRIORITY_LOW);
			observable.RegisterObserver(mockObserver4, CMockObservable::PRIORITY_NORMAL);

			observable.NotifyObservers();
		}
	}
}