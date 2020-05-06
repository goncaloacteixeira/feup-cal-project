#include "include/Pessoa.h"


Pessoa::Pessoa(const std::string &nome, unsigned int nif, const std::string &email) : nome(nome), nif(nif),
                                                                                      email(email) {}

Local Pessoa::getOrigem() const {
    return origem;
}

Local Pessoa::getDestino() const {
    return destino;
}

std::string Pessoa::getNome() const {
    return nome;
}

unsigned int Pessoa::getNif() const {
    return nif;
}

std::string Pessoa::getEmail() const {
    return email;
}

std::vector<Local *> Pessoa::getDestinosFrequentes() const {
    return destinosFrequentes;
}


Condutor::Condutor(const std::string &nome, unsigned int nif, const std::string &email, Carro carro) : Pessoa(nome, nif, email) {
    this->carro = carro;
}

Passageiro::Passageiro(const std::string &nome, unsigned int nif, const std::string &email) : Pessoa(nome, nif, email) {

}
