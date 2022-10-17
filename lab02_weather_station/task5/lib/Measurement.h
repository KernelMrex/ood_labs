#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>

template <typename T>
using PrintMeasurementFn = std::function<void(T newValue)>;

template <typename T>
PrintMeasurementFn<T> GetMeasurementPrintFnHOC(
	const std::string& label,
	const std::vector<std::function<std::string(const std::string&, T)>>& valProcFns)
{
	return [label, valProcFns](T newValue) mutable {
		for (const auto& valProcFn : valProcFns)
		{
			std::cout << valProcFn(label, newValue);
		}
	};
}

template <typename T>
std::function<std::string(const std::string& label, T)> GetMinMeasurementPrintFn()
{
	T minValue = std::numeric_limits<T>::infinity();

	return [minValue](const std::string& label, T val) mutable -> std::string {
		std::stringstream ss;

		minValue = std::min<T>(val, minValue);

		ss << "Min " << label << ": " << std::setprecision(4) << minValue << std::endl;
		return ss.str();
	};
}

template <typename T>
std::function<std::string(const std::string& label, T)> GetMaxMeasurementPrintFn()
{
	T maxValue = -std::numeric_limits<T>::infinity();

	return [maxValue](const std::string& label, T val) mutable -> std::string {
		std::stringstream ss;

		maxValue = std::max<T>(val, maxValue);

		ss << "Max " << label << ": " << std::setprecision(4) << maxValue << std::endl;
		return ss.str();
	};
}

template <typename T>
std::function<std::string(const std::string& label, T)> GetAvgMeasurementPrintFn()
{
	double accValue = 0;
	int counter = 0;

	return [accValue, counter](const std::string& label, T val) mutable -> std::string {
		std::stringstream ss;

		counter++;
		accValue += val;

		ss << "Average " << label << ": " << std::setprecision(4) << (accValue / counter) << std::endl;
		return ss.str();
	};
}

template <typename T>
std::function<std::string(const std::string& label, T)> GetAvgCircleMeasurementAccCalcFn()
{
	double accValue = 0;
	int counter = 0;

	return [accValue, counter](const std::string& label, T val) mutable -> std::string {
		std::stringstream ss;

		counter++;
		accValue += val;

		// TODO: переработать суммирование векторов
		ss << "Average " << label << ": " << std::setprecision(4) << std::fmod(accValue / counter, 180) << std::endl;
		return ss.str();
	};
}

#endif // MEASUREMENT_H
