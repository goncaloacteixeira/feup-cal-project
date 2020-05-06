//
// Created by skidr on 06/05/2020.
//

#include "Local.h"

Local::Local(const std::string &nome) : nome(nome) {

}

const std::string &Local::getNome() const {
    return nome;
}

void Local::setNome(const std::string &nome) {
    Local::nome = nome;
}

Local::Local() {
    this->nome = "undefined";
}
