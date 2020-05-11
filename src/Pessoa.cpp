#include "include/Pessoa.h"


Pessoa::Pessoa(const std::string &nome, unsigned int nif, const std::string &email) : nome(nome), nif(nif),
                                                                                      email(email) {}

Place Pessoa::getOrigem() const {
    return origem;
}

Place Pessoa::getDestino() const {
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

std::vector<Place *> Pessoa::getDestinosFrequentes() const {
    return destinosFrequentes;
}


Condutor::Condutor(const std::string &nome, unsigned int nif, const std::string &email, Carro carro) : Pessoa(nome, nif, email), carro(carro) {
}

Passageiro::Passageiro(const std::string &nome, unsigned int nif, const std::string &email) : Pessoa(nome, nif, email) {

}
