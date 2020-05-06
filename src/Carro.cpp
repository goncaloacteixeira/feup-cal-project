#include "include/Carro.h"


int Carro::getLotacao() const {
    return lotacao;
}

std::string Carro::getModelo() const {
    return modelo;
}

std::string Carro::getMatricula() const {
    return matricula;
}

Carro::Carro(int lotacao, const std::string &modelo, const std::string &matricula) : lotacao(lotacao), modelo(modelo),
                                                                                     matricula(matricula) {}
