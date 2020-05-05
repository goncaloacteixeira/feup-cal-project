#include "Pessoa.h"

Pessoa::Pessoa(Local origem, Local destino, string nome, unsigned int nif, string email, vector<Local *> destinosFrequentes);

Local Pessoa::getOrigem() const { return origem;}
Local Pessoa::getDestino() const { return destino;}
string Pessoa::getNome() const { return nome;}
unsigned int Pessoa::getNif() const {return nif;}
string Pessoa::getEmail() const {return email;}
vector<Local *> Pessoa::getDestinosFrequentes() const {return destinosFrequentes;}


