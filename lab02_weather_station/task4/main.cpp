#include "lib/CDisplay.h"
#include "lib/CStatsDisplay.h"
#include "lib/CWeatherData.h"

int main()
{
	CWeatherData wdOut("out");
	CWeatherData wdIn("in");

	CDisplay display;
	CStatsDisplay statsDisplay;

	wdOut.RegisterObserver(display);
	wdOut.RegisterObserver(statsDisplay);
	wdIn.RegisterObserver(display);
	wdIn.RegisterObserver(statsDisplay);

	wdOut.SetMeasurements(3, 0.7, 759);
	wdIn.SetMeasurements(4, 0.8, 761);
	wdIn.SetMeasurements(2, 0.2, 701);

	return EXIT_SUCCESS;
}