#define CATCH_CONFIG_MAIN

#include <utility>

#include "../../../../catch.hpp"
#include "../../../task4/lib/CObservable.h"

TEST_CASE("CObservable unit tests", "[c_observable]")
{
	SECTION("Observer can determine from which observable data received")
	{
		struct SMockUpdateData
		{
			explicit SMockUpdateData(std::string sourceId)
				: sourceId(std::move(sourceId))
			{
			}
			std::string sourceId;
		};

		class CMockObservable : public CObservable<SMockUpdateData>
		{
		public:
			explicit CMockObservable(std::string observableId)
				: CObservable<SMockUpdateData>(std::move(observableId))
			{
			}

			[[nodiscard]] SMockUpdateData GetChangedData() const final
			{
				SMockUpdateData data(GetObservableId());
				return data;
			}
		};

		class CMockObserver : public IObserver<SMockUpdateData>
		{
		public:
			explicit CMockObserver(std::vector<std::string>& updateSourcesGot)
				: m_updateSourcesGot(updateSourcesGot)
			{
			}

			void Update(SMockUpdateData const& data) final
			{
				m_updateSourcesGot.emplace_back(data.sourceId);
			}

		private:
			std::vector<std::string>& m_updateSourcesGot;
		};

		CMockObservable observable1("observable1");
		CMockObservable observable2("observable2");

		std::vector<std::string> updateSourcesGot;

		CMockObserver observer(updateSourcesGot);

		observable1.RegisterObserver(observer);
		observable2.RegisterObserver(observer);

		observable1.NotifyObservers();
		observable2.NotifyObservers();

		REQUIRE(updateSourcesGot == std::vector<std::string>{"observable1", "observable2"});
	}
}