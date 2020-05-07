//
// Created by skidr on 06/05/2020.
//

#ifndef MEETUP_RIDER_DATAIMPORTER_H
#define MEETUP_RIDER_DATAIMPORTER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Local.h"
#include "GraphViewer/graphviewer.h"

class DataImporter {
    std::string nodesFilename;
    std::string edgesFilename;

    std::vector<Local*> locais;

    void parseEdges();
    void parseNodes();

public:
    DataImporter(const std::string &nodesFilename, const std::string &edgesFilename);

    void viewGraph();
};


#endif //MEETUP_RIDER_DATAIMPORTER_H
