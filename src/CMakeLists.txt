cmake_minimum_required(VERSION 3.16)
project(meetup-rider)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(lib)

# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
link_libraries(ws2_32 wsock32)

add_executable(meetup-rider meetupRider.cpp
        Carro.cpp include/Carro.h
        Pessoa.cpp include/Pessoa.h Local.cpp include/Local.h)