cmake_minimum_required(VERSION 3.16)
project(meetup-rider)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(meetup-rider meetupRider.cpp
        Carro.cpp include/Carro.h
        Pessoa.cpp include/Pessoa.h Local.cpp include/Local.h)