#ifndef CWEATHERDATA_H
#define CWEATHERDATA_H

#include "CObservable.h"
#include "SWeatherInfo.h"

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	explicit CWeatherData(std::string id)
		: CObservable(std::move(id))
	{
	}

	// Температура в градусах Цельсия
	double GetTemperature() const
	{
		return m_temperature;
	}

	// Относительная влажность (0...100)
	double GetHumidity() const
	{
		return m_humidity;
	}

	// Атмосферное давление (в мм.рт.ст)
	double GetPressure() const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}

protected:
	[[nodiscard]] SWeatherInfo GetChangedData() const override
	{
		SWeatherInfo info{
			GetObservableId(),
			GetTemperature(),
			GetHumidity(),
			GetPressure()
		};
		return info;
	}

private:
	std::string m_weatherDataId;
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};

#endif // CWEATHERDATA_H
