#ifndef CSTATSDISPLAY_H
#define CSTATSDISPLAY_H

#include "../WeatherData.h"
#include <functional>
#include <utility>

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay(
		PrintMeasurementFn<double> temperatureMeasurementFn,
		PrintMeasurementFn<double> humidityMeasurementFn,
		PrintMeasurementFn<double> pressureMeasurementFn
	)
		: m_temperatureMeasurementFn(std::move(temperatureMeasurementFn))
		, m_humidityMeasurementFn(std::move(humidityMeasurementFn))
		, m_pressureMeasurementFn(std::move(pressureMeasurementFn))
	{
	}

private:
	void Update(SWeatherInfo const& data) override
	{
		m_temperatureMeasurementFn(data.temperature);
		m_humidityMeasurementFn(data.humidity);
		m_pressureMeasurementFn(data.pressure);
	}

	PrintMeasurementFn<double> m_temperatureMeasurementFn;
	PrintMeasurementFn<double> m_humidityMeasurementFn;
	PrintMeasurementFn<double> m_pressureMeasurementFn;
};

#endif // CSTATSDISPLAY_H
