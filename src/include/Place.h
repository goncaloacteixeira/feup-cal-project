//
// Created by skidr on 06/05/2020.
//

#ifndef MEETUP_RIDER_PLACE_H
#define MEETUP_RIDER_PLACE_H

#include <string>

/**
 * @brief Place Class
 * Stores Place's information
 */
class Place {
    int id;             //!< Place ID
    std::string name;   //!< Place name
    double x;           //!< Place's X position
    double y;           //!< Place's Y position
public:
    /**
     * @brief Default Place constructor
     */
    Place();

    /**
     * @brief Place constructor with ID
     * @param id Place ID
     */
    Place(int id);

    /**
     * @brief Place complete constructor
     * @param id    Place ID
     * @param name  Place Name
     * @param x     Place's X position
     * @param y     Place's Y position
     */
    Place(int id, const std::string &name, double x, double y);

    /**
     * @brief GET method for name
     * @return local's name
     */
    const std::string &getName() const;

    /**
     * @brief SET method for name
     * @param nome new local's name
     */
    void setName(const std::string &nome);

    /**
     * @brief GET method for ID
     * @return local's ID
     */
    int getId() const;

    /**
     * @brief GET method for X
     * @return local's X position
     */
    double getX() const;

    /**
     * @brief GET method for Y
     * @return local's Y position
     */
    double getY() const;

    /**
     * @brief Operator overload
     * @return true if the IDs are equal
     */
    bool operator==(const Place &rhs) const;

    bool operator!=(const Place &rhs) const;
};


#endif //MEETUP_RIDER_PLACE_H
