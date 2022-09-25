#ifndef CDISPLAY_H
#define CDISPLAY_H

#include "IObserver.h"
#include "SWeatherInfo.h"
#include <iostream>
#include <map>

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		auto measurementIt = m_measurements.find(data.sourceId);
		if (measurementIt == m_measurements.end())
		{
			measurementIt = m_measurements.insert(std::pair(data.sourceId, data)).first;
		}
		measurementIt->second = data;

		for (auto& measurementPair : m_measurements)
		{
			PrintMeasurementsForWeatherInfo(measurementPair.second);
		}

		std::cout << "----------------" << std::endl;
	}

	void static PrintMeasurementsForWeatherInfo(SWeatherInfo const& data)
	{
		std::cout << "From: " << data.sourceId << std::endl;
		PrintMeasurement("Temp", data.temperature);
		PrintMeasurement("Hum", data.humidity);
		PrintMeasurement("Pressure", data.pressure);
	}

	void static PrintMeasurement(const std::string& label, double value)
	{
		std::cout << "Current " << label << " " << value << std::endl;
	}

	std::map<std::string, SWeatherInfo> m_measurements{};
};


#endif // CDISPLAY_H
