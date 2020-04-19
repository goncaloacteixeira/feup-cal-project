//
// Created by skidr on 19/04/2020.
//

#ifndef FEUP_CAL_PROJECT_DATAIMPORTER_H
#define FEUP_CAL_PROJECT_DATAIMPORTER_H

#include <string>
#include <vector>
#include <fstream>
#include "Graph.h"

using namespace std;

class DataImporter {
    string nodesFilename;
    string edgesFilename;
    vector<Vertex<int>> nodes;
    vector<Edge<int>> edges;

public:
    DataImporter(const string &nodesFilename, const string &edgesFilename);

    void parseEdges();

};


#endif //FEUP_CAL_PROJECT_DATAIMPORTER_H
