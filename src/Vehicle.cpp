#include "include/Vehicle.h"


int Vehicle::getCapacity() const {
    return capacity;
}

std::string Vehicle::getModel() const {
    return model;
}

std::string Vehicle::getPlate() const {
    return plate;
}

Vehicle::Vehicle(int capacity, const std::string &model, const std::string &plate, int id) : capacity(capacity), model(model),
                                                                                             plate(plate), id(id) {}

int Vehicle::getId() const {
    return id;
}
