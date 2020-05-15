//
// Created by skidr on 06/05/2020.
//

#include "DataImporter.h"
#include "math.h"

std::string toLower(std::string string) {
    std::string result = "";
    for (char a : string)
        result += std::tolower(a);
    return result;
}

std::string DataImporter::build_path(std::string city, data_t data) {
    switch (data) {
        case NODES: return "res/PortugalMaps/" + city + "/nodes_x_y_" + toLower(city) + ".txt";
        case EDGES: return "res/PortugalMaps/" + city + "/edges_" + toLower(city) + ".txt";
        default: return "";
    }
}

DataImporter::DataImporter(const std::string &nodesFilename, const std::string &edgesFilename) : nodesFilename(nodesFilename),
                                                                                       edgesFilename(edgesFilename) {
    graphViewer = new GraphViewer(750, 750, false);
    real_maps = false;
    this->height = 750;
    this->width = 750;

    minX = std::numeric_limits<double>::max();
    minY = std::numeric_limits<double>::max();
    maxX = std::numeric_limits<double>::min();
    maxY = std::numeric_limits<double>::min();
}

DataImporter::DataImporter(int width, int height, std::string city) {
    this->height = height;
    this->width = width;
    real_maps = true;

    this->nodesFilename = build_path(city, NODES);
    this->edgesFilename = build_path(city, EDGES);

    minX = std::numeric_limits<double>::max();
    minY = std::numeric_limits<double>::max();
    maxX = std::numeric_limits<double>::min();
    maxY = std::numeric_limits<double>::min();

    graphViewer = new GraphViewer(width, height, false);
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

        if (real_maps) {
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }
        this->graph.addVertex(Place(id, "null", x, y));
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

        if (real_maps) {
            graph.addBidirectionalEdge(id1, id2, 1); /* the weight needs to be calculated for each type of road */
        }
        else
            graph.addBidirectionalEdge(Place(id1), Place(id2), 1); /* the weight needs to be calculated for each type of road */
    }
}

Graph *DataImporter::getGraph() {
    return &this->graph;
}

void DataImporter::viewGraph() {
    graphViewer->createWindow(this->width, this->height);
    graphViewer->defineVertexColor("black");
    graphViewer->defineEdgeColor("black");
    graphViewer->defineEdgeCurved(false);

    int edgeID = 0;
    for (auto vertex : this->graph.getVertexSet()) {
        if (real_maps) {
            double yPercent = 1.0 - ((vertex->getInfo().getY() - minY)/(maxY - minY) * 0.9 + 0.05);
            double xPercent = (vertex->getInfo().getX() - minX)/(maxX - minX)*0.9 + 0.05;
            graphViewer->addNode(vertex->getInfo().getId(), (int) (xPercent * width), (int) (yPercent * height));
        }
        else {
            graphViewer->addNode(vertex->getInfo().getId(), vertex->getInfo().getX(), vertex->getInfo().getY());
        }
        graphViewer->setVertexLabel(vertex->getInfo().getId(), std::to_string(vertex->getInfo().getId()));
        graphViewer->rearrange();
    }
    for (auto vertex : this->graph.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            graphViewer->addEdge(edgeID++, vertex->getInfo().getId(), edge.getDest()->getInfo().getId(), EdgeType::DIRECTED);
            // graphViewer->setEdgeLabel(edgeID-1, to_string(edge.getWeight()));
        }
        graphViewer->rearrange();
    }

    graphViewer->rearrange();
    graphViewer->setBackground("background.jpg");
}

void DataImporter::wait() {
    std::cout << "Press any key to continue ...";
    getchar();
}

GraphViewer *DataImporter::getGraphViewer() const {
    return graphViewer;
}

void DataImporter::parseData() {
    this->graph = Graph();
    this->parseNodes();
    this->parseEdges();
}
