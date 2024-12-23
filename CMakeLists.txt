cmake_minimum_required(VERSION 3.29)
project(tp1_kirill)

set(CMAKE_CXX_STANDARD 20)

add_executable(tp1_kirill main.cpp
        Car.cpp
        Car.h
        Keeper.cpp
        Keeper.h
        Bus.cpp
        Bus.h
        Motorcycle.cpp
        Motorcycle.h
        Base.h
)
