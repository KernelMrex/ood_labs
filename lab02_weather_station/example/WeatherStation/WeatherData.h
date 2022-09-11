#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		if (m_minTemperature > data.temperature)
		{
			m_minTemperature = data.temperature;
		}
		if (m_maxTemperature < data.temperature)
		{
			m_maxTemperature = data.temperature;
		}
		m_accTemperature += data.temperature;
		++m_countAcc;

		std::cout << "Max Temp " << m_maxTemperature << std::endl;
		std::cout << "Min Temp " << m_minTemperature << std::endl;
		std::cout << "Average Temp " << (m_accTemperature / m_countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}

	double m_minTemperature = std::numeric_limits<double>::infinity();
	double m_maxTemperature = -std::numeric_limits<double>::infinity();
	double m_accTemperature = 0;
	unsigned m_countAcc = 0;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
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
	SWeatherInfo GetChangedData() const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}

private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};

#endif // WEATHERDATA_H
