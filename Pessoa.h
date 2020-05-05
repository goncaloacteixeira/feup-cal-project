#ifndef UNTITLED1_PESSOA_H
#define UNTITLED1_PESSOA_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Carro.h"
#include "Local.h"

using namespace std;

class Pessoa {
    Local origem;
    Local destino;
    string nome;
    unsigned int nif;
    string email;
    vector<Local *> destinosFrequentes;
public:
    Local getOrigem() const;
    Local getDestino() const;
    string getNome() const;
    unsigned int getNif() const;
    string getEmail() const;
    vector<Local *> getDestinosFrequentes() const;
};

class Condutor : public Pessoa {
    Carro carro;
public:
    Carro getCarro() const;
};

class Passageiro : public Pessoa {
public:

};


#endif //UNTITLED1_PESSOA_H
