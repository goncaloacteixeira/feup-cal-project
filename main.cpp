#include <iostream>

#include "DataImporter.h"

string pt_maps(string s) {
    return "res/PortugalMaps/" + s;
}

int main() {
    auto dt = new DataImporter(pt_maps("Porto/edges_porto.txt"), pt_maps("Porto/nodes_x_y_porto.txt"));
    dt->parseEdges();

    return 0;
}
