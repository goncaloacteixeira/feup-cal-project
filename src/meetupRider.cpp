//
// Created by skidr on 06/05/2020.
//

#include <iostream>

#include "DataProcessor.h"

void graphViz4() {
    DataImporter dataImporter("res/GridGraphs/4x4/nodes.txt", "res/GridGraphs/4x4/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();
}

void graphViz8() {
    DataImporter dataImporter("res/GridGraphs/8x8/nodes.txt", "res/GridGraphs/8x8/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();

    DataProcessor dataProcessor(dataImporter);
    dataProcessor.computePaths(0, dijkstra);
    dataProcessor.buildPath(0, 49);
    dataProcessor.computePaths(0, bellmanford);
    dataProcessor.buildPath(0, 49);

    dataImporter.getGraphViewer()->closeWindow();
}

void graphViz16() {
    DataImporter dataImporter("res/GridGraphs/16x16/nodes.txt", "res/GridGraphs/16x16/edges.txt");
    dataImporter.parseData();
    dataImporter.viewGraph();
}


int main() {
    // graphViz4();
    graphViz8();
    // graphViz16();
}

