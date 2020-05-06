//
// Created by skidr on 06/05/2020.
//

#include <iostream>

#include "GraphViewer/graphviewer.h"
#include "DataImporter.h"

void graphViz4() {
    DataImporter dataImporter("res/GridGraphs/4x4/nodes.txt", "res/GridGraphs/4x4/edges.txt");
    dataImporter.viewGraph();
}

void graphViz8() {
    DataImporter dataImporter("res/GridGraphs/8x8/nodes.txt", "res/GridGraphs/8x8/edges.txt");
    dataImporter.viewGraph();
}

void graphViz16() {
    DataImporter dataImporter("res/GridGraphs/16x16/nodes.txt", "res/GridGraphs/16x16/edges.txt");
    dataImporter.viewGraph();
}


int main() {
    graphViz4();
    graphViz8();
    graphViz16();
}

