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
        task2/lib/CWeatherData.h
)


add_executable(
        lab02_weather_station_task2_test
        ../catch.hpp
        task2/lib/IObservable.h
        task2/lib/IObserver.h
        task2/lib/CObservable.h
        task2_test/unit/lib/CObservableTest.cpp
)

add_executable(
        lab02_weather_station_task3
        task3/main.cpp
        task3/lib/CStatsDisplay.h
        task3/lib/Measurement.h
        task3/lib/CDisplay.h
        task3/lib/SWeatherInfo.h
        task3/lib/IObservable.h
        task3/lib/IObserver.h
        task3/lib/CObservable.h
        task3/lib/CWeatherData.h
)

add_executable(
        lab02_weather_station_task3_test
        ../catch.hpp
        task3/lib/IObservable.h
        task3/lib/IObserver.h
        task3/lib/CObservable.h
        task3_test/unit/lib/CObservableTest.cpp
)

add_executable(
        lab02_weather_station_task4
        task4/main.cpp
        task4/lib/CStatsDisplay.h
        task4/lib/Measurement.h
        task4/lib/CDisplay.h
        task4/lib/SWeatherInfo.h
        task4/lib/IObservable.h
        task4/lib/IObserver.h
        task4/lib/CObservable.h
        task4/lib/CWeatherData.h
)

add_executable(
        lab02_weather_station_task4_test
        ../catch.hpp
        task4/lib/Measurement.h
        task4/lib/SWeatherInfo.h
        task4/lib/IObservable.h
        task4/lib/IObserver.h
        task4/lib/CObservable.h
        task4_test/unit/lib/CObservableTest.cpp
)

add_executable(
        lab02_weather_station_task5
        task5/main.cpp
        task5/lib/CStatsDisplay.h
        task5/lib/Measurement.h
        task5/lib/CDisplay.h
        task5/lib/SWeatherInfo.h
        task5/lib/IObservable.h
        task5/lib/IObserver.h
        task5/lib/CObservable.h
        task5/lib/CWeatherData.h
)