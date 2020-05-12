#ifndef UNTITLED1_PESSOA_H
#define UNTITLED1_PESSOA_H

#include <string>
#include <vector>
#include "Vehicle.h"
#include "Place.h"

/**
 * @brief Super Class Person
 */
class Person {
    Place origin;       //!< Person's origin place
    Place destiny;      //!< Person's destiny place
    std::string name;   //!< Person's name
    unsigned int vat;   //!< Person's VAT number
    std::string email;  //!< Person's e-mail address
    std::vector<Place *> frequentDestinies;    //!< Most frequent destinies
public:
    /**
     * @brief Person's Constructor
     * @param name Person's name
     * @param vat Person's VAT number
     * @param email Person's e-mail address
     */
    Person(const std::string &name, unsigned int vat, const std::string &email);

    /**
     * @brief GET Method for origin
     * @return Person's origin place
     */
    Place getOrigin() const;

    /**
     * @brief GET Method for destiny
     * @return Person's destiny place
     */
    Place getDestiny() const;

    /**
     * @brief GET Method for name
     * @return Person's name
     */
    std::string getName() const;

    /**
     * @brief GET Method for VAT number
     * @return Person's VAT number
     */
    unsigned int getVAT() const;

    /**
     * @brief GET Method for e-mail
     * @return Person's e-mail address
     */
    std::string getEmail() const;

    /**
     * @brief GET Method for frequent destinies
     * @return vector with most frequent destinies
     */
    std::vector<Place *> getFrequentDestinies() const;

    void setOrigin(const Place &origin);

    void setDestiny(const Place &destiny);
};

/**
 * @brief SubClass Driver
 */
class Driver : public Person {
    // todo - adicionar um vetor de viagens já feitas
    Vehicle vehicle;    //!< Driver's Vehicle
public:
    /**
     * @brief Driver's Constructor
     * @param name Driver's name
     * @param vat Drivers's VAT number
     * @param email Driver's e-mail address
     * @param vehicle Driver's Vehicle
     */
    Driver(const std::string &name, unsigned int vat, const std::string &email, Vehicle vehicle);

    /**
     * @brief GET Method for Vehicle
     * @return Driver's Vehicle
     */
    Vehicle getVehicle() const;
};

/**
 * @brief SubClass Passenger
 */
class Passenger : public Person {
    // todo - adicionar um vetor de viagens já feitas
public:
    /**
     * @brief Passenger's Constructor
     * @param name Passenger's Name
     * @param vat Passenger's VAT Name
     * @param email Passenger's e-mail address
     */
    Passenger(const std::string &name, unsigned int vat, const std::string &email);
};


#endif //UNTITLED1_PESSOA_H
