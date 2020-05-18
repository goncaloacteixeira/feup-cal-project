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

void menus() {
    DataImporter importer(1920, 1080, "Ol");
    DataProcessor processor(importer);

    Application application("res/csvFiles/drivers.csv", "res/csvFiles/passengers.csv", "res/csvFiles/cars.csv", &processor);
    application.init();

    Menus menus(&application);
    menus.startRide();
}

int main() {
    /*********************************************************************************
     *  IMPORTANTE - mudar a working directory do CLion para a raiz do repositório.  *
     *********************************************************************************/

    /* descomentar a linha seguinte para ver o exemplo para um grafo de grelha de 16x16 */

    menus();
}
