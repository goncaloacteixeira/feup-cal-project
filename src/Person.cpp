#include "include/Person.h"


Person::Person(const std::string &name, unsigned int vat, const std::string &email) : name(name), vat(vat),
                                                                                      email(email) {}

Place Person::getOrigin() const {
    return origin;
}

Place Person::getDestiny() const {
    return destiny;
}

std::string Person::getName() const {
    return name;
}

unsigned int Person::getVAT() const {
    return vat;
}

std::string Person::getEmail() const {
    return email;
}

std::vector<Place *> Person::getFrequentDestinies() const {
    return frequentDestinies;
}

void Person::setOrigin(const Place &origin) {
    Person::origin = origin;
}

void Person::setDestiny(const Place &destiny) {
    Person::destiny = destiny;
}


Driver::Driver(const std::string &name, unsigned int vat, const std::string &email, Vehicle vehicle) : Person(name, vat, email), vehicle(vehicle) {
}

Vehicle Driver::getVehicle() const {
    return vehicle;
}

Passenger::Passenger(const std::string &name, unsigned int vat, const std::string &email) : Person(name, vat, email) {

}
