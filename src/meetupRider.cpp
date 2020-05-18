//
// Created by skidr on 06/05/2020.
//

#include "Application.h"

void app() {
    DataImporter importer(1920, 1080, "Ol");
    DataProcessor processor(importer);

    Application application("res/csvFiles/drivers.csv", "res/csvFiles/passengers.csv", "res/csvFiles/cars.csv", &processor);
    application.init();
    application.startRun(112211221, dijkstra);
}

int main() {
    /*********************************************************************************
     *  IMPORTANTE - mudar a working directory do CLion para a raiz do repositório.  *
     *********************************************************************************/

    /* descomentar a linha seguinte para ver o exemplo para um grafo de grelha de 16x16 */

    app();
}
