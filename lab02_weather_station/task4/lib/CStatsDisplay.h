#ifndef CSTATSDISPLAY_H
#define CSTATSDISPLAY_H

#include "IObserver.h"
#include "Measurement.h"
#include "SWeatherInfo.h"
#include <functional>
#include <utility>

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	struct SWeatherStatsDisplayData
	{
		PrintMeasurementFn<double> temperatureMeasurementFn;
		PrintMeasurementFn<double> humidityMeasurementFn;
		PrintMeasurementFn<double> pressureMeasurementFn;
	};

	void Update(SWeatherInfo const& data) override
	{
		auto measurementIt = m_measurements.find(data.sourceId);
		if (measurementIt == m_measurements.end())
		{
			SWeatherStatsDisplayData displayCallbackCollection{
				GetMeasurementPrintFn<double>("Temperature"),
				GetMeasurementPrintFn<double>("Humidity"),
				GetMeasurementPrintFn<double>("Pressure"),
			};

			auto p = std::pair(data.sourceId, displayCallbackCollection);
			measurementIt = m_measurements.insert(p).first;
		}

		std::cout << "--- BEGIN: Stats display ---" << std::endl;

		std::cout << "From " << data.sourceId << std::endl;
		measurementIt->second.temperatureMeasurementFn(data.temperature);
		measurementIt->second.humidityMeasurementFn(data.humidity);
		measurementIt->second.pressureMeasurementFn(data.pressure);

		std::cout << "---  END: Stats display  ---" << std::endl;
	}

	std::map<std::string, SWeatherStatsDisplayData> m_measurements;
};

#endif // CSTATSDISPLAY_H
