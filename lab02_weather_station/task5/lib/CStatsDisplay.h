#ifndef CSTATSDISPLAY_H
#define CSTATSDISPLAY_H

#include "IObserver.h"
#include "Measurement.h"
#include "SWeatherInfo.h"
#include <functional>
#include <utility>

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;


class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(
		PrintMeasurementFn<double> temperatureMeasurementFn,
		PrintMeasurementFn<double> humidityMeasurementFn,
		PrintMeasurementFn<double> pressureMeasurementFn,
		PrintMeasurementFn<double> windDirectionMeasurementFn)
		: m_temperatureMeasurementFn(std::move(temperatureMeasurementFn))
		, m_humidityMeasurementFn(std::move(humidityMeasurementFn))
		, m_pressureMeasurementFn(std::move(pressureMeasurementFn))
		, m_windDirectionMeasurementFn(std::move(windDirectionMeasurementFn))
	{
	}

private:
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "--- BEGIN: Stats display ---" << std::endl;
		m_temperatureMeasurementFn(data.temperature);
		std::cout << "----------------" << std::endl;
		m_humidityMeasurementFn(data.humidity);
		std::cout << "----------------" << std::endl;
		m_pressureMeasurementFn(data.pressure);
		std::cout << "----------------" << std::endl;
		m_windDirectionMeasurementFn(data.windDirection);
		std::cout << "---  END: Stats display  ---" << std::endl;
	}

	PrintMeasurementFn<double> m_temperatureMeasurementFn;
	PrintMeasurementFn<double> m_humidityMeasurementFn;
	PrintMeasurementFn<double> m_pressureMeasurementFn;
	PrintMeasurementFn<double> m_windDirectionMeasurementFn;
};

#endif // CSTATSDISPLAY_H
