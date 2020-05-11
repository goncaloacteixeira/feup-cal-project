#ifndef UNTITLED1_PESSOA_H
#define UNTITLED1_PESSOA_H

#include <string>
#include <vector>
#include "Carro.h"
#include "Place.h"

/**
 * @brief Super Classe Pessoa
 */
class Pessoa {
    Place origem;       //!< Place de origem da Pessoa
    Place destino;      //!< Place de destino da Pessoa
    std::string nome;   //!< name da Pessoa
    unsigned int nif;   //!< NIF da Pessoa
    std::string email;  //!< email da Pessoa
    std::vector<Place *> destinosFrequentes;    //!< Locais mais frequentes como destino
public:
    /**
     * @brief Construtor de Pessoa
     * @param nome name da Pessoa
     * @param nif NIF da Pessoa
     * @param email email da Pessoa
     */
    Pessoa(const std::string &nome, unsigned int nif, const std::string &email);

    /**
     * @brief Método GET de origem
     * @return Place de origem da Pessoa
     */
    Place getOrigem() const;

    /**
     * @brief Método GET de destino
     * @return Place de destino da Pessoa
     */
    Place getDestino() const;

    /**
     * @brief Método GET de name
     * @return name da Pessoa
     */
    std::string getNome() const;

    /**
     * @brief Método GET de NIF
     * @return NIF da Pessoa
     */
    unsigned int getNif() const;

    /**
     * @brief Método GET de email
     * @return email da Pessoa
     */
    std::string getEmail() const;

    /**
     * @brief Método GET de destinos frequentes
     * @return vetor com os destinos frequentes da Pessoa
     */
    std::vector<Place *> getDestinosFrequentes() const;
};

/**
 * @brief Classe derivada Condutor
 */
class Condutor : public Pessoa {
    // todo - adicionar um vetor de viagens já feitas
    Carro carro;    //!< Carro do condutor
public:
    /**
     * @brief Construtor de Condutor
     * @param nome name do Condutor
     * @param nif NIF do Condutor
     * @param email email do Condutor
     * @param carro carro do Condutor
     */
    Condutor(const std::string &nome, unsigned int nif, const std::string &email, Carro carro);

    /**
     * @brief Método GET do carro
     * @return carro do Condutor
     */
    Carro getCarro() const;
};

/**
 * @brief Classe derivada Passageiro
 */
class Passageiro : public Pessoa {
    // todo - adicionar um vetor de viagens já feitas
public:
    /**
     * @brief Construtor de Passageiro
     * @param nome name do Passageiro
     * @param nif NIF do Passageiro
     * @param email email do Passageiro
     */
    Passageiro(const std::string &nome, unsigned int nif, const std::string &email);
};


#endif //UNTITLED1_PESSOA_H
