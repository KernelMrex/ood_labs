cmake_minimum_required(VERSION 3.23)
project(lab01_simuduck)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab01_simuduck_example
        example/lib/Duck/Fly/IFlyBehavior.h
        example/lib/Duck/Fly/FlyWithWings.h
        example/lib/Duck/Fly/FlyNoWay.h
        example/lib/Duck/Quack/IQuakBehavior.h
        example/lib/Duck/Quack/QuackBehavior.h
        example/lib/Duck/Quack/SqueakBehavior.h
        example/lib/Duck/Quack/MuteQuackBehavior.h
        example/lib/Duck/Duck.h
        example/lib/Duck/MallardDuck.h
        example/lib/Duck/RedheadDuck.h
        example/lib/Duck/DecoyDuck.h
        example/lib/Duck/RubberDuck.h
        example/lib/Duck/ModelDuck.h
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
