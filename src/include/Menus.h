//
// Created by skidr on 18/05/2020.
//

#ifndef MEETUP_RIDER_MENUS_H
#define MEETUP_RIDER_MENUS_H

#include "Application.h"
#include "VariadicTable/VariadicTable.h"

class Menus {
    static void header(std::string tittle);
    static void option(int number, std::string option);
    Application* application;

    std::vector<int> selectPassengers(int capacity);

    void viewDrivers();
    void viewPassengers();
public:
    Menus(Application* application);

    int mainMenu();

    void addDriver();
    void addPassenger();
    void addVehicle();

    void startRide();

    void exitMenu();
    void exportData();

};


#endif //MEETUP_RIDER_MENUS_H
