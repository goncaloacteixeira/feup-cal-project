#ifndef UNTITLED1_CARRO_H
#define UNTITLED1_CARRO_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Carro {
    int lotacao;
    string modelo;
    string matricula;
public:
    int getLotacao() const;
    string getModelo() const;
    string getMatricula() const;
};
#endif //UNTITLED1_CARRO_H
