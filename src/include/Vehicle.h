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
    int capacity;                //!< lotação do vehicle
    std::string model;         //!< modelo do vehicle
    std::string plate;      //!< matricula do vehicle
    int id;
public:
    /**
     * @brief Construtor da classe Vehicle
     * @param capacity lotação do vehicle
     * @param model model do vehicle
     * @param plate plate do vehicle
     */
    Vehicle(int capacity, const std::string &model, const std::string &plate, int id);

    /**
     * @brief Método GET para lotação
     * @return lotação do vehicle
     */
    int getCapacity() const;

    /**
     * @brief Método GET para modelo
     * @return modelo do vehicle
     */
    std::string getModel() const;

    /**
     * @brief Método GET para matrícula
     * @return matricula do vehicle
     */
    std::string getPlate() const;

    int getId() const;
};
#endif //UNTITLED1_CARRO_H
