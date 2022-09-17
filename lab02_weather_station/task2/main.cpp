#include "lib/CDisplay.h"
#include "lib/CStatsDisplay.h"
#include "lib/Measurement.h"

int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display);

	CStatsDisplay statsDisplay(
		GetMeasurementPrintFn<double>("Temperature"),
		GetMeasurementPrintFn<double>("Humidity"),
		GetMeasurementPrintFn<double>("Pressure"));
	wd.RegisterObserver(statsDisplay);

	wd.SetMeasurements(3, 0.7, 760);
	std::cout << std::endl
			  << " === Measurements Updated === " << std::endl
			  << std::endl;

	wd.SetMeasurements(4, 0.8, 761);
	std::cout << std::endl
			  << " === Measurements Updated === " << std::endl
			  << std::endl;

	wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761);
	std::cout << std::endl
			  << " === Measurements Updated === " << std::endl
			  << std::endl;

	wd.SetMeasurements(-10, 0.8, 761);
	std::cout << std::endl
			  << " === Measurements Updated === " << std::endl
			  << std::endl;

	return 0;
}