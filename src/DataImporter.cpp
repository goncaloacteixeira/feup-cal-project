//
// Created by skidr on 06/05/2020.
//

#include "DataImporter.h"

DataImporter::DataImporter(const std::string &nodesFilename, const std::string &edgesFilename) : nodesFilename(nodesFilename),
                                                                                       edgesFilename(edgesFilename) { }

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

        this->locais.emplace_back(new Local(id, "null", x, y));
    }
}

void DataImporter::viewGraph() {
    this->parseNodes();

    GraphViewer* gv = new GraphViewer(750, 750, false);
    gv->createWindow(750, 750);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for (auto local : this->locais) {
        gv->addNode(local->getId(), local->getX(), local->getY());
    }

    gv->setBackground("background.jpg");
    gv->rearrange();

    std::cout << "Press any key to close this window ...";
    getchar();
    gv->closeWindow();
}
