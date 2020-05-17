//
// Created by skidr on 06/05/2020.
//

#include "Application.h"

void app() {
    DataImporter importer(1920, 1080, "California");
    importer.parseData();
    importer.viewGraph();
    importer.wait();

    DataProcessor processor(importer);
    /*processor.completePath(std::vector<int> {
        264, 154, 1241, 5402,
    }, dijkstra);*/

    Person person("teste",1,"email");
    std::vector<Ride> rides = {Ride(154, 1241,&person)};
    processor.completePath(264,5402,&rides,dijkstra);
    processor.wait();
}

int main() {
    /*********************************************************************************
     *  IMPORTANTE - mudar a working directory do CLion para a raiz do repositório.  *
     *********************************************************************************/

    /* descomentar a linha seguinte para ver o exemplo para um grafo de grelha de 16x16 */

    app();
}
