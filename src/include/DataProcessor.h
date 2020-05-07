//
// Created by skidr on 07/05/2020.
//

#ifndef MEETUP_RIDER_DATAPROCESSOR_H
#define MEETUP_RIDER_DATAPROCESSOR_H

#include "Graph.h"
#include "DataImporter.h"

class DataProcessor {
    Graph<Local>* graph;

public:
    DataProcessor(Graph<Local> *graph);
    void buildPath(int id1, int id2);
    void showPath();
};


#endif //MEETUP_RIDER_DATAPROCESSOR_H
