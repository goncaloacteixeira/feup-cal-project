#include <iostream>

#include "DataImporter.h"

string pt_maps(string s) {
    return "res/PortugalMaps/" + s;
}

int main() {
    auto dt = new DataImporter(pt_maps("Porto/nodes_x_y_porto.txt"), pt_maps("Porto/edges_porto.txt"));

    auto graph = dt->createGraph();
    printf("%d\n", graph->getVertexSet()[1]->getInfo().getId());

    return 0;
}
