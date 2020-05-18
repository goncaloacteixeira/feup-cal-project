cmake_minimum_required(VERSION 3.16)
project(meetup-rider)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/include)
include_directories(src/lib)
include_directories(res)

# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
link_libraries(ws2_32 wsock32)

add_executable(meetup-rider src/meetupRider.cpp
        src/Vehicle.cpp src/include/Vehicle.h
        src/Person.cpp src/include/Person.h
        src/Place.cpp src/include/Place.h
        src/lib/GraphViewer/connection.cpp src/lib/GraphViewer/graphviewer.cpp
        src/DataImporter.cpp src/include/DataImporter.h
        src/DataProcessor.cpp src/include/DataProcessor.h src/lib/CSVReader/CSVReader.cpp src/lib/CSVReader/CSVReader.h src/Application.cpp src/include/Application.h src/Graph.cpp src/include/Ride.h src/Ride.cpp src/Menus.cpp src/include/Menus.h)