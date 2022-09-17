cmake_minimum_required(VERSION 3.23)
project(lab02_weather_station)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lab02_weather_station_example
        example/WeatherStation/main.cpp
        example/WeatherStation/WeatherData.h
        example/WeatherStation/Observer.h
)

add_executable(
        lab02_weather_station_task1
        task1/main.cpp
        task1/lib/CStatsDisplay.h
        task1/lib/Measurement.h
        task1/lib/CDisplay.h
        task1/lib/SWeatherInfo.h
        task1/lib/IObservable.h
        task1/lib/IObserver.h
        task1/lib/CObservable.h
)

add_executable(
        lab02_weather_station_task2
        task2/main.cpp
        task2/lib/CStatsDisplay.h
        task2/lib/Measurement.h
        task2/lib/CDisplay.h
        task2/lib/SWeatherInfo.h
        task2/lib/IObservable.h
        task2/lib/IObserver.h
        task2/lib/CObservable.h
)