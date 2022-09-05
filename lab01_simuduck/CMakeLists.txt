cmake_minimum_required(VERSION 3.23)
project(lab01_simuduck)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab01_simuduck_task1
        .example/lib/IFlyBehavior.h .example/lib/FlyWithWings.h .example/lib/FlyNoWay.h .example/lib/IQuakBehavior.h .example/lib/QuackBehavior.h .example/lib/SqueakBehavior.h .example/lib/MuteQuackBehavior.h .example/lib/Duck.h .example/lib/MallardDuck.h .example/lib/RedheadDuck.h .example/lib/DecoyDuck.h .example/lib/RubberDuck.h .example/lib/ModelDuck.h .example/lib/DuckFunctions.h .example/main.cpp)
