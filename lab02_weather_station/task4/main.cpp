#include "lib/CDisplay.h"
#include "lib/CStatsDisplay.h"
#include "lib/CWeatherData.h"

int main()
{
	CWeatherData wdOut("out");
	CWeatherData wdIn("in");

	CDisplay display;

	wdOut.RegisterObserver(display);
	wdIn.RegisterObserver(display);

	wdOut.SetMeasurements(3, 0.7, 759);
	wdIn.SetMeasurements(4, 0.8, 761);

	return EXIT_SUCCESS;
}