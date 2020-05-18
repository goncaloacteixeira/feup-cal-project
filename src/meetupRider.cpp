//
// Created by skidr on 06/05/2020.
//

#include "Menus.h"

void app() {
    DataImporter importer(1920, 1080, "Ol");
    DataProcessor processor(importer);

    Application application("res/csvFiles/drivers.csv", "res/csvFiles/passengers.csv", "res/csvFiles/cars.csv", &processor);
    application.init();

    std::vector<int> passengers = {
            456789876,
            234234768,
            234098755,
    };

    application.startRun(112211221, &passengers, dijkstra);
}

int main() {
    /*********************************************************************************
     *  IMPORTANTE - mudar a working directory do CLion para a raiz do repositório.  *
     *********************************************************************************/

    DataImporter importer(1920, 1080, "Ol");
    DataProcessor processor(importer);

    Application application("res/csvFiles/drivers.csv", "res/csvFiles/passengers.csv", "res/csvFiles/cars.csv", &processor);
    application.init();

    Menus menus(&application);

    int option;

    do {
        option = menus.mainMenu();
        switch (option) {
            case 1:
                menus.addDriver();
                break;
            case 2:
                menus.addPassenger();
                break;
            case 3:
                menus.addVehicle();
            case 4:
                menus.startRide();
                break;
            case 0:
                menus.exitMenu();
                break;
            default:
                break;
        }
    } while (option != 0);
}
