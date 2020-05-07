//
// Created by skidr on 06/05/2020.
//

#include "Local.h"


const std::string &Local::getNome() const {
    return nome;
}

void Local::setNome(const std::string &nome) {
    Local::nome = nome;
}

Local::Local() {
    this->nome = "undefined";
    this->x = 0;
    this->y = 0;
    this->id = -1;
}

Local::Local(int id, const std::string &nome, double x, double y) : id(id), nome(nome), x(x), y(y) {

}

int Local::getId() const {
    return id;
}

double Local::getX() const {
    return x;
}

double Local::getY() const {
    return y;
}

bool Local::operator==(const Local &rhs) const {
    return id == rhs.id;
}

bool Local::operator!=(const Local &rhs) const {
    return !(rhs == *this);
}

Local::Local(int id) : Local() {
    this->id = id;
}
