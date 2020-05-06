#ifndef UNTITLED1_CARRO_H
#define UNTITLED1_CARRO_H

#include <string>

/**
 * @file Carro.h
 * @brief Classe Carro
 */


/**
 * @brief Classe Carro
 */
class Carro {
    int lotacao;                //!< lotação do carro
    std::string modelo;         //!< modelo do carro
    std::string matricula;      //!< matricula do carro
public:
    /**
     * @brief Construtor da classe Carro
     * @param lotacao lotação do carro
     * @param modelo modelo do carro
     * @param matricula matricula do carro
     */
    Carro(int lotacao, const std::string &modelo, const std::string &matricula);

    /**
     * @brief Método GET para lotação
     * @return lotação do carro
     */
    int getLotacao() const;

    /**
     * @brief Método GET para modelo
     * @return modelo do carro
     */
    std::string getModelo() const;

    /**
     * @brief Método GET para matrícula
     * @return matricula do carro
     */
    std::string getMatricula() const;
};
#endif //UNTITLED1_CARRO_H
