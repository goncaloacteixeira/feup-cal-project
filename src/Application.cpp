//
// Created by skidr on 12/05/2020.
//

#include "Application.h"

Application::Application(const string &driversFile, const string &passengersFile, const string &vehiclesFile,
                         DataProcessor* processor) {
    this->driversFile = driversFile;
    this->passengersFile = passengersFile;
    this->vehiclesFile = vehiclesFile;
    this->processor = processor;
}

void Application::parseData() {
    this->parseVehicles();
    this->parseDrivers();
    this->parsePassengers();
}

void Application::initGraph() {
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

void Application::startRun(int driverVAT, algorithm_t algorithm) {
    auto driver = findDriver(driverVAT);
    if (driver == nullptr)
        return;

    std::cout << "Starting run for " << driver->getName() << " as driver\n";

    std::vector<int> points = { driver->getOrigin().getId() };

    std::srand(time(nullptr));
    for (int i = 0; i < driver->getVehicle().getCapacity() - 1; i++) {
       int j = std::rand() % this->passengers.size();   // os passageiros são escolhidos aleatoriamente

       std::cout << "Selecting " << this->passengers[j]->getName() << " as passenger\n";

       points.emplace_back(this->passengers[j]->getOrigin().getId());
       points.emplace_back(this->passengers[j]->getDestiny().getId());
    }

    points.emplace_back(driver->getDestiny().getId());

    this->processor->completePath(points, algorithm);
    this->processor->wait();

    // TODO - implementar um sistema que tenha em conta as horas de saída dos passageiros.
}

void Application::startRun(int driverVAT, std::vector<int> *passengersVAT, algorithm_t algorithm) {
    auto driver = findDriver(driverVAT);
    if (driver == nullptr)
        return;

    std::cout << "Starting run for " << driver->getName() << " as driver\n";

    std::vector<int> points = { driver->getOrigin().getId() };

    for (int passVAT : *passengersVAT) {
        auto passenger = this->findPassenger(passVAT);
        if (passenger == nullptr)
            continue;

        std::cout << "Selecting " << passenger->getName() << " as passenger\n";

        points.emplace_back(passenger->getOrigin().getId());
        points.emplace_back(passenger->getDestiny().getId());
    }

    points.emplace_back(driver->getDestiny().getId());

    if (algorithm != floydwarshall)
        this->processor->completePath(points, algorithm);
    else
        this->processor->completePath(points);
    this->processor->wait();
}


void Application::cleanup() {
    this->processor->cleanup();
}

bool Application::addPassenger(Passenger *passenger) {
    if (this->findPassenger(passenger->getVAT()) != nullptr)
        return false;
    this->passengers.push_back(passenger);
    return true;
}

bool Application::addDriver(Driver *driver) {
    if (this->findDriver(driver->getVAT()) != nullptr)
        return false;
    this->drivers.push_back(driver);
    return true;
}

bool Application::addVehicle(Vehicle *vehicle) {
    if (this->findVehicle(vehicle->getId()) != nullptr)
        return false;
    this->vehicles.push_back(vehicle);
    return true;
}

void Application::exportPassengers(std::string filename) {
    std::fstream fs(filename, std::fstream::out | std::fstream::trunc);
    if (fs.is_open()) {
        fs << "name,vat,email,source,destination" << std::endl;
        for (auto passenger : this->passengers) {
            fs << passenger->getName() << ",";
            fs << passenger->getVAT() << ",";
            fs << passenger->getEmail() << ",";
            fs << passenger->getOrigin().getId() << ",";
            fs << passenger->getDestiny().getId() << "\n";
        }
        fs.close();
    }
}

void Application::exportDrivers(std::string filename) {
    std::fstream fs(filename, std::fstream::out | std::fstream::trunc);
    if (fs.is_open()) {
        fs << "name,vat,email,source,destination,car" << std::endl;
        for (auto driver : this->drivers) {
            fs << driver->getName() << ",";
            fs << driver->getVAT() << ",";
            fs << driver->getEmail() << ",";
            fs << driver->getOrigin().getId() << ",";
            fs << driver->getDestiny().getId() << ",";
            fs << driver->getVehicle().getId() << "\n";
        }
        fs.close();
    }
}

void Application::exportVehicles(std::string filename) {
    std::fstream fs(filename, std::fstream::out | std::fstream::trunc);
    if (fs.is_open()) {
        fs << "capacity,model,registration,id" << std::endl;
        for (auto vehicle : this->vehicles) {
            fs << vehicle->getCapacity() << ",";
            fs << vehicle->getModel() << ",";
            fs << vehicle->getPlate() << ",";
            fs << vehicle->getId() << "\n";
        }
        fs.close();
    }
}
