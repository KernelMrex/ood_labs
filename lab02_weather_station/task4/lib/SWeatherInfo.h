#ifndef SWEATHERINFO_H
#define SWEATHERINFO_H

#include <string>

struct SWeatherInfo
{
	std::string sourceId;
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

#endif // SWEATHERINFO_H
