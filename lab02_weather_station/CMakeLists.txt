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
        task1/WeatherData.h
        task1/Observer.h
        task1/lib/CStatsDisplay.h
        task1/lib/Measurement.h)