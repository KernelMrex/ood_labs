cmake_minimum_required(VERSION 3.23)
project(lab02_weather_station)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab02_weather_station_example

        example/WeatherStation/main.cpp example/WeatherStation/WeatherData.h example/WeatherStation/Observer.h)