#ifndef UNTITLED1_CARRO_H
#define UNTITLED1_CARRO_H

#include <string>

/**
 * @file Vehicle.h
 * @brief Classe Vehicle
 */


/**
 * @brief Classe Vehicle
 */
class Vehicle {
    int lotacao;                //!< lotação do vehicle
    std::string modelo;         //!< modelo do vehicle
    std::string matricula;      //!< matricula do vehicle
public:
    /**
     * @brief Construtor da classe Vehicle
     * @param lotacao lotação do vehicle
     * @param modelo modelo do vehicle
     * @param matricula matricula do vehicle
     */
    Vehicle(int lotacao, const std::string &modelo, const std::string &matricula);

    /**
     * @brief Método GET para lotação
     * @return lotação do vehicle
     */
    int getLotacao() const;

    /**
     * @brief Método GET para modelo
     * @return modelo do vehicle
     */
    std::string getModelo() const;

    /**
     * @brief Método GET para matrícula
     * @return matricula do vehicle
     */
    std::string getMatricula() const;
};
#endif //UNTITLED1_CARRO_H
