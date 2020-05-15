//
// Created by skidr on 06/05/2020.
//

#include "Application.h"

// deprecated
void graphViz4() {
    DataImporter dataImporter("res/GridGraphs/4x4/nodes.txt", "res/GridGraphs/4x4/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();

    DataProcessor dataProcessor(dataImporter);
    dataProcessor.computePaths(0, dijkstra);
    dataProcessor.buildPath(0, 12);
    dataProcessor.cleanup();
    dataProcessor.computePaths(0, bellmanford);
    dataProcessor.buildPath(0, 12);
    dataProcessor.cleanup();

    dataImporter.getGraphViewer()->closeWindow();
}

// deprecated
void graphViz8() {
    DataImporter dataImporter("res/GridGraphs/8x8/nodes.txt", "res/GridGraphs/8x8/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();

    DataProcessor dataProcessor(dataImporter);
    dataProcessor.computePaths(0, dijkstra);
    dataProcessor.buildPath(0, 49);
    dataProcessor.cleanup();
    dataProcessor.computePaths(0, bellmanford);
    dataProcessor.buildPath(0, 49);
    dataProcessor.cleanup();

    dataImporter.getGraphViewer()->closeWindow();
}

/* deprecated */
void graphViz16() {
    DataImporter dataImporter("res/GridGraphs/16x16/nodes.txt", "res/GridGraphs/16x16/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();
    dataImporter.wait();

    DataProcessor dataProcessor(dataImporter);
    auto path = dataProcessor.completePath(std::vector<int>{0, 160, 10, 108, 225, 164, 182, 284});
    dataProcessor.wait();

    dataImporter.getGraphViewer()->closeWindow();
}

void app() {
    Application application("res/csvFiles/drivers.csv", "res/csvFiles/passengers.csv", "res/csvFiles/cars.csv",
                            "res/GridGraphs/16x16/nodes.txt", "res/GridGraphs/16x16/edges.txt");

    application.parseData();

    application.initGraph();
    /* selecting driver with vat 112211221 and random passengers for his vehicle */
    application.startRun(112211221, dijkstra);
    application.cleanup();

    /* selecting driver with vat 112211221 and specific passengers */
    std::vector<int> passengers = {
            345676554,
            234234768,
            234587657,
    };
    application.startRun(112211221, &passengers, bellmanford);
    application.cleanup();
}

int main() {
    /*********************************************************************************
     *  IMPORTANTE - mudar a working directory do CLion para a raiz do repositório.  *
     *********************************************************************************/

    /* descomentar a linha seguinte para ver o exemplo para um grafo de grelha de 16x16 */

    app();
}
