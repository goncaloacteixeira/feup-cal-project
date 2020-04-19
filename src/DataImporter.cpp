//
// Created by skidr on 19/04/2020.
//

#include <VertexInfo.h>
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

    for (int i = 1; i < stoi(edges[0]) ; ++i) {
        char unused;
        int x, y;
        istringstream ss(edges[i]);
        ss >> unused;
        ss >> x;
        ss >> unused;
        ss >> y;
        ss >> unused;

        graph.addEdge(VertexInfo(x), VertexInfo(y), 0); /* the weight needs to be calculated for each type of road */
    }


}

void DataImporter::parseNodes() {
    vector<string> nodes;
    ifstream nodesFile(this->nodesFilename);

    string line;
    while (getline(nodesFile, line)) {
        nodes.emplace_back(line);
    }


    for (int i = 1; i < stoi(nodes[0]); i++) {
        int id;
        double x;
        double y;
        char unused;
        istringstream ss(nodes[i]);
        ss >> unused;
        ss >> id;
        ss >> unused;
        ss >> x;
        ss >> unused;
        ss >> y;

        graph.addVertex(VertexInfo(id, x, y));
    }
}

Graph<VertexInfo> *DataImporter::createGraph() {
    this->parseNodes();
    this->parseEdges();

    return &this->graph;
}
