//
// Created by skidr on 18/05/2020.
//

#include "Menus.h"

void Menus::header(std::string tittle) {
    for (char a : tittle)
        std::cout << "-";
    std::cout << "\n" << tittle << "\n";
    for (char a : tittle)
        std::cout << "-";
    std::cout << "\n";
}

Menus::Menus(Application* application) {
    this->application = application;
}

void Menus::addDriver() {
    header("ADD A NEW DRIVER");
    Driver* driver;
    std::string name;
    int vat;
    std::string email;
    int origin;
    int destiny;
    int car;

    std::string response;
    std::cout << "Name:";
    std::getline(cin, response); name = response;
    std::cout << "VAT Number:";
    std::getline(cin, response); vat = std::stoi(response);
    std::cout << "E-mail address:";
    std::getline(cin, response); email = response;
    std::cout << "Origin Point ID:";
    std::getline(cin, response); origin = std::stoi(response);
    std::cout << "Destiny Point ID:";
    std::getline(cin, response); destiny = std::stoi(response);
    std::cout << "Car ID:";
    std::getline(cin, response); car = std::stoi(response);

    Vehicle* vehicle = application->findVehicle(car);
    if (vehicle == nullptr) {
        vehicle = new Vehicle(5, "undefined", "XX-00-XX", car);
    }

    driver = new Driver(name, vat, email, *vehicle);
    driver->setOrigin(Place(origin));
    driver->setDestiny(Place(destiny));

    if (application->addDriver(driver)) {
        std::cout << "\tSuccessfully Added!\n";
    } else {
        std::cout << "\tCannot add driver!\n";
    }
}

void Menus::addPassenger() {
    header("ADD A NEW PASSENGER");
    Passenger* passenger;
    std::string name;
    int vat;
    std::string email;
    int origin;
    int destiny;

    std::string response;
    std::cout << "Name:";
    std::getline(cin, response); name = response;
    std::cout << "VAT Number:";
    std::getline(cin, response); vat = std::stoi(response);
    std::cout << "E-mail address:";
    std::getline(cin, response); email = response;
    std::cout << "Origin Point ID:";
    std::getline(cin, response); origin = std::stoi(response);
    std::cout << "Destiny Point ID:";
    std::getline(cin, response); destiny = std::stoi(response);

    passenger = new Passenger(name, vat, email);
    passenger->setOrigin(Place(origin));
    passenger->setDestiny(Place(destiny));

    if (application->addPassenger(passenger)) {
        std::cout << "\tSuccessfully Added!\n";
    } else {
        std::cout << "\tCannot add passenger!\n";
    }
}

void Menus::addVehicle() {
    header("ADD A NEW VEHICLE");
    Vehicle* vehicle;
    std::string model;
    int capacity;
    std::string plate;
    int id;

    std::string response;
    std::cout << "Model:";
    std::getline(cin, response); model = response;
    std::cout << "Capacity:";
    std::getline(cin, response); capacity = std::stoi(response);
    std::cout << "Plate:";
    std::getline(cin, response); plate = response;
    std::cout << "ID:";
    std::getline(cin, response); id = std::stoi(response);

    vehicle = new Vehicle(capacity, model, plate, id);

    if (application->addVehicle(vehicle)) {
        std::cout << "\tSuccessfully Added!\n";
    } else {
        std::cout << "\tCannot add passenger!\n";
    }
}

void Menus::exportData() {
    header("EXPORT DATA TO CSV FILES");

    std::string drivers;
    std::string passengers;
    std::string vehicles;

    std::cout << "Path for drivers' file:";
    std::getline(cin, drivers);
    std::cout << "Path for passengers' file:";
    std::getline(cin, passengers);
    std::cout << "Path for vehicles' file:";
    std::getline(cin, vehicles);

    application->exportDrivers(drivers);
    application->exportPassengers(passengers);
    application->exportVehicles(vehicles);

    header("Data exported successfully!");
}
