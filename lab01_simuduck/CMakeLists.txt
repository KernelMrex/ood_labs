cmake_minimum_required(VERSION 3.23)
project(lab01_simuduck)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab01_simuduck_example
        example/lib/IFlyBehavior.h
        example/lib/FlyWithWings.h
        example/lib/FlyNoWay.h
        example/lib/IQuakBehavior.h
        example/lib/QuackBehavior.h
        example/lib/SqueakBehavior.h
        example/lib/MuteQuackBehavior.h
        example/lib/Duck.h
        example/lib/MallardDuck.h
        example/lib/RedheadDuck.h
        example/lib/DecoyDuck.h
        example/lib/RubberDuck.h
        example/lib/ModelDuck.h
        example/lib/DuckFunctions.h
        example/main.cpp
)

add_executable(
        lab01_simuduck_task1
        task1/lib/Fly/IFlyBehavior.h
        task1/lib/Fly/FlyWithWings.h
        task1/lib/Fly/FlyNoWay.h
        task1/lib/Quack/IQuakBehavior.h
        task1/lib/Quack/QuackBehavior.h
        task1/lib/Quack/SqueakBehavior.h
        task1/lib/Quack/MuteQuackBehavior.h
        task1/lib/Duck/Duck.h
        task1/lib/Duck/MallardDuck.h
        task1/lib/Duck/RedheadDuck.h
        task1/lib/Duck/DecoyDuck.h
        task1/lib/Duck/RubberDuck.h
        task1/lib/Duck/ModelDuck.h
        task1/lib/DuckFunctions.h
        task1/main.cpp
        task1/lib/Dance/IDanceStrategy.h
        task1/lib/Dance/WaltzDanceStrategy.h
        task1/lib/Dance/MinuetDanceStrategy.h
        task1/lib/Dance/CantDanceStrategy.h
)
