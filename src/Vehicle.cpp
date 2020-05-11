#include "include/Vehicle.h"


int Vehicle::getLotacao() const {
    return lotacao;
}

std::string Vehicle::getModelo() const {
    return modelo;
}

std::string Vehicle::getMatricula() const {
    return matricula;
}

Vehicle::Vehicle(int lotacao, const std::string &modelo, const std::string &matricula) : lotacao(lotacao), modelo(modelo),
                                                                                         matricula(matricula) {}
