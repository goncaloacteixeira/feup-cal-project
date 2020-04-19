//
// Created by skidr on 19/04/2020.
//

#ifndef FEUP_CAL_PROJECT_DATAIMPORTER_H
#define FEUP_CAL_PROJECT_DATAIMPORTER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "VertexInfo.h"
#include "Graph.h"

using namespace std;

class DataImporter {
    string nodesFilename;
    string edgesFilename;

    Graph<VertexInfo> graph;

    void parseEdges();
    void parseNodes();

public:
    DataImporter(const string &nodesFilename, const string &edgesFilename);

    Graph<VertexInfo>* createGraph();

};


#endif //FEUP_CAL_PROJECT_DATAIMPORTER_H
