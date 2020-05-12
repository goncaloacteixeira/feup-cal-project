//
// Created by skidr on 12/05/2020.
//

#ifndef MEETUP_RIDER_APPLICATION_H
#define MEETUP_RIDER_APPLICATION_H

#include <random>
#include <time.h>
#include "DataProcessor.h"
#include "Person.h"
#include "Vehicle.h"
#include "Place.h"
#include "CSVReader/CSVReader.h"

class Application {
    std::string driversFile;
    std::string passengersFile;
    std::string vehiclesFile;

    std::vector<Driver*> drivers;
    std::vector<Passenger*> passengers;
    std::vector<Vehicle*> vehicles;
    DataProcessor *processor;

    void parseDrivers();
    void parsePassengers();
    void parseVehicles();

    Driver* findDriver(int vat);
    Passenger* findPassenger(int vat);
    Vehicle* findVehicle(int id);
public:
    Application(const string &driversFile, const string &passengersFile, const string &vehiclesFile,
                const string &nodesFile, const string &edgesFile);

    void initGraph();


    void startRun(int driverVAT);

    void cleanup();
};


#endif //MEETUP_RIDER_APPLICATION_H
