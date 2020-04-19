cmake_minimum_required(VERSION 3.16)
project(feup_cal_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)

add_executable(feup_cal_project main.cpp include/Graph.h include/MutablePriorityQueue.h src/DataImporter.cpp include/DataImporter.h src/VertexInfo.cpp include/VertexInfo.h)