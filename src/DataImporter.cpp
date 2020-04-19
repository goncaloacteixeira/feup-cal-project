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

    vector<Edge<int>> vector;

    for (int i = 1; i < stoi(edges[0]) ; ++i) {
        char unused;
        int x, y;
        istringstream ss(edges[i]);
        ss >> unused;
        ss >> x;
        ss >> unused;
        ss >> y;
        ss >> unused;

        // TODO - Adicionar Edges aos Vertex
    }

    printf("Hello");
}
