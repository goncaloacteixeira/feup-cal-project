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

/**
 * @brief Class Application
 *
 * This is the main class to our project
 */
class Application {
    std::string driversFile;    //!< drivers filename
    std::string passengersFile; //!< passengers filename
    std::string vehiclesFile;   //!< vehicles filename

    std::vector<Driver*> drivers;           //!< drivers vector
    std::vector<Passenger*> passengers;     //!< passengers vector
    std::vector<Vehicle*> vehicles;         //!< vehicles vector
    DataProcessor *processor;               //!< pointer to data processor

    void parseDrivers();        //!< private method to parse drivers data from file
    void parsePassengers();     //!< private method to parse passengers data from file
    void parseVehicles();       //!< private method to parse vehicles data from file

    Driver* findDriver(int vat);        //!< private method to find a driver
    Passenger* findPassenger(int vat);  //!< private method to find a passenger
    Vehicle* findVehicle(int id);       //!< private method to find a vehicle
public:
    /**
     * @brief Application constructor
     * @param driversFile       drivers filename
     * @param passengersFile    passengers filename
     * @param vehiclesFile      vehicles filename
     * @param nodesFile         nodes filename
     * @param edgesFile         edges filename
     */
    Application(const string &driversFile, const string &passengersFile, const string &vehiclesFile,
                const string &nodesFile, const string &edgesFile);

    /**
     * @brief Parses data (call all parsing data methods)
     */
    void parseData();

    /**
     * @brief Initializing graphs and visualization
     *
     * This is needed to process further data
     */
    void initGraph();

    /**
     * @brief Ride starter for a driver VAT - driverVAT (1)
     * @param driverVAT driver's VAT number
     *
     * This method builds a path from driver's origin to their destination,
     * selecting random passengers to fill their vehicle.
     */
    void startRun(int driverVAT);

    /**
     * @brief Ride starter for a driver VAT - driverVAT (2)
     * @param driverVAT         driver's VAT number
     * @param passengersVAT     vector with passengers' VAT number
     *
     * This method builds a path from driver's origin to their destination,
     * selecting all passengers passed on second argument.
     */
    void startRun(int driverVAT, std::vector<int>* passengersVAT);

    /**
     * @brief Cleanup assembled path
     */
    void cleanup();

    /**
     * @brief Export passengers data to CSV file
     * @param filename passengers desired path
     */
    void exportPassengers(std::string filename);

    /**
     * @brief Export drivers data to CSV file
     * @param filename drivers desired path
     */
    void exportDrivers(std::string filename);

    /**
     * @brief Export vehicles data to CSV file
     * @param filename vehicles desired path
     */
    void exportVehicles(std::string filename);

    /**
     * @brief Add a passenger to vector
     * @param passenger passenger to be added
     * @return true - if successfully added
     */
    bool addPassenger(Passenger* passenger);

    /**
     * @brief Add a driver to vector
     * @param driver driver to be added
     * @return true - if successfully added
     */
    bool addDriver(Driver* driver);

    /**
     * @brief Add a vehicle to vector
     * @param vehicle vehicle to be added
     * @return true - if successfully added
     */
    bool addVehicle(Vehicle* vehicle);
};


#endif //MEETUP_RIDER_APPLICATION_H
