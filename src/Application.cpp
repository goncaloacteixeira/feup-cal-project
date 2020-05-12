//
// Created by skidr on 12/05/2020.
//

#include "Application.h"

Application::Application(const string &driversFile, const string &passengersFile, const string &vehiclesFile,
                         const string &nodesFile, const string &edgesFile) {
    this->driversFile = driversFile;
    this->passengersFile = passengersFile;
    this->vehiclesFile = vehiclesFile;
    this->processor = new DataProcessor(DataImporter(nodesFile, edgesFile));
}

void Application::initGraph() {
    this->parseVehicles();
    this->parseDrivers();
    this->parsePassengers();

    this->processor->getDataImporter().parseData();
    this->processor->getDataImporter().viewGraph();
    this->processor->getDataImporter().wait();
}

Driver *Application::findDriver(int vat) {
    for (auto driver : this->drivers) {
        if (driver->getVAT() == vat)
            return driver;
    }
    return nullptr;
}

Passenger *Application::findPassenger(int vat) {
    for (auto passenger : this->passengers) {
        if (passenger->getVAT() == vat)
            return passenger;
    }
    return nullptr;
}

Vehicle *Application::findVehicle(int id) {
    for (auto vehicle : this->vehicles) {
        if (vehicle->getId() == id)
            return vehicle;
    }
    return nullptr;
}

void Application::parseVehicles() {
    CSVReader reader(this->vehiclesFile, ",");
    auto data = reader.getData();

    for (auto line : data) {
        int capacity = std::stoi(line[0]);
        std::string model = line[1];
        std::string plate = line[2];
        int id = std::stoi(line[3]);

        this->vehicles.emplace_back(new Vehicle(capacity, model, plate, id));
    }
}

void Application::parseDrivers() {
    CSVReader reader(this->driversFile, ",");
    auto data = reader.getData();

    for (auto line : data) {
        std::string name = line[0];
        int vat = std::stoi(line[1]);
        std::string email = line[2];
        int source = std::stoi(line[3]);
        int destination = std::stoi(line[4]);
        int car = std::stoi(line[5]);

        auto vehicle = this->findVehicle(car);
        auto driver = new Driver(name, vat, email, *vehicle);
        driver->setDestiny(Place(destination));
        driver->setOrigin(Place(source));

        this->drivers.emplace_back(driver);
    }
}

void Application::parsePassengers() {
    CSVReader reader(this->passengersFile, ",");
    auto data = reader.getData();

    for (auto line : data) {
        std::string name = line[0];
        int vat = std::stoi(line[1]);
        std::string email = line[2];
        int source = std::stoi(line[3]);
        int destination = std::stoi(line[4]);

        auto passenger = new Passenger(name, vat, email);
        passenger->setDestiny(Place(destination));
        passenger->setOrigin(Place(source));

        this->passengers.emplace_back(passenger);
    }
}

