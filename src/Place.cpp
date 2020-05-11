//
// Created by skidr on 06/05/2020.
//

#include "Place.h"


const std::string &Place::getName() const {
    return name;
}

void Place::setName(const std::string &nome) {
    Place::name = nome;
}

Place::Place() {
    this->name = "undefined";
    this->x = 0;
    this->y = 0;
    this->id = -1;
}

Place::Place(int id, const std::string &name, double x, double y) : id(id), name(name), x(x), y(y) {

}

int Place::getId() const {
    return id;
}

double Place::getX() const {
    return x;
}

double Place::getY() const {
    return y;
}

bool Place::operator==(const Place &rhs) const {
    return id == rhs.id;
}

bool Place::operator!=(const Place &rhs) const {
    return !(rhs == *this);
}

Place::Place(int id) : Place() {
    this->id = id;
}
