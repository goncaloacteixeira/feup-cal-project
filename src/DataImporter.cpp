//
// Created by skidr on 19/04/2020.
//

#include "DataImporter.h"

DataImporter::DataImporter(const string &nodesFilename, const string &edgesFilename) : nodesFilename(nodesFilename),
                                                                                       edgesFilename(edgesFilename) {}

void DataImporter::parseEdges() {
    vector<string> edges;
    ifstream edgesFile(this->edgesFilename);

    string line;
    while (getline(edgesFile, line)) {
        edges.emplace_back(line);
    }

    printf("Hello");
}
