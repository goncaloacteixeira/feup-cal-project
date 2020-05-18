//
// Created by skidr on 18/05/2020.
//

#ifndef MEETUP_RIDER_MENUS_H
#define MEETUP_RIDER_MENUS_H

#include "Application.h"

class Menus {
    static void header(std::string tittle);
    Application* application;
public:
    Menus(Application* application);

    void addDriver();
    void addPassenger();
    void addVehicle();


    void exportData();

};


#endif //MEETUP_RIDER_MENUS_H
