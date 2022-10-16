#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;

template <typename T>
PrintMeasurementFn<T> GetMeasurementPrintFn(const std::string& label, std::function<std::string(T val)> calcAccValueFn)
{
	T minValue = std::numeric_limits<T>::infinity();
	T maxValue = -std::numeric_limits<T>::infinity();

	return [label, calcAccValueFn, minValue, maxValue](T newValue) mutable {
		minValue = std::min<T>(newValue, minValue);
		maxValue = std::max<T>(newValue, maxValue);

		std::cout << "Max " << label << " " << std::fixed << std::setprecision(4) << maxValue << std::endl;
		std::cout << "Min " << label << " " << std::fixed << std::setprecision(4) << minValue << std::endl;
		std::cout << "Average " << label << " " << calcAccValueFn(newValue) << std::endl;
	};
}

template <typename T>
std::function<std::string(T)> GetDefaultMeasurementAccCalcFn()
{
	double accValue = 0;
	int counter = 0;

	return [accValue, counter](T val) mutable -> std::string {
		std::stringstream ss;

		counter++;
		accValue += val;

		ss << std::setprecision(4) << (accValue / counter);
		return ss.str();
	};
}

#endif // MEASUREMENT_H
