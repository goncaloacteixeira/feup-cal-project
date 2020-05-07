//
// Created by skidr on 06/05/2020.
//

#include "DataImporter.h"

DataImporter::DataImporter(const std::string &nodesFilename, const std::string &edgesFilename) : nodesFilename(nodesFilename),
                                                                                       edgesFilename(edgesFilename) {
    graph = Graph<Local>();

    graphViewer = new GraphViewer(750, 750, false);
    
}

void DataImporter::parseNodes() {
    std::vector<std::string> nodes;
    std::ifstream nodesFile(this->nodesFilename);

    std::string line;
    while (getline(nodesFile, line)) {
        nodes.emplace_back(line);
    }


    for (int i = 1; i <= stoi(nodes[0]); i++) {
        int id;
        double x;
        double y;
        char unused;
        std::istringstream ss(nodes[i]);
        ss >> unused;
        ss >> id;
        ss >> unused;
        ss >> x;
        ss >> unused;
        ss >> y;

        this->graph.addVertex(Local(id, "null", x, y));
    }
}

void DataImporter::parseEdges() {
    vector<string> edges;
    ifstream edgesFile(this->edgesFilename);

    string line;
    while (getline(edgesFile, line)) {
        edges.emplace_back(line);
    }

    for (int i = 1; i <= stoi(edges[0]) ; ++i) {
        char unused;
        int id1, id2;
        istringstream ss(edges[i]);
        ss >> unused;
        ss >> id1;
        ss >> unused;
        ss >> id2;
        ss >> unused;

        graph.addBidirectionalEdge(Local(id1), Local(id2), 0); /* the weight needs to be calculated for each type of road */
    }
}

void DataImporter::viewGraph() {
    // TODO - Create a new thread for graph visualization
}

Graph<Local> *DataImporter::getGraph() {
    return &this->graph;
}

void DataImporter::_viewGraph() {
    this->parseNodes();
    this->parseEdges();

    graphViewer->createWindow(750, 750);
    graphViewer->defineVertexColor("blue");
    graphViewer->defineEdgeColor("black");

    int edgeID = 0;
    for (auto vertex : this->graph.getVertexSet()) {
        graphViewer->addNode(vertex->getInfo().getId(), vertex->getInfo().getX(), vertex->getInfo().getY());
        graphViewer->setVertexLabel(vertex->getInfo().getId(), std::to_string(vertex->getInfo().getId()));
        for (auto edge : vertex->getAdj())
            graphViewer->addEdge(edgeID++, vertex->getInfo().getId(), edge.getDest()->getInfo().getId(), EdgeType::UNDIRECTED);

    }

    graphViewer->setBackground("background.jpg");
    graphViewer->defineEdgeCurved(false);
    graphViewer->rearrange();

    std::cout << "Press any key to continue ...";
    getchar();
}
