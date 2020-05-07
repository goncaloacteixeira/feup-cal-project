//
// Created by skidr on 07/05/2020.
//

#ifndef MEETUP_RIDER_DATAPROCESSOR_H
#define MEETUP_RIDER_DATAPROCESSOR_H

#include "Graph.h"
#include "DataImporter.h"

typedef enum {
    bellmanford,
    dijkstra,
} algorithm_t;

class DataProcessor {
    DataImporter dataImporter;
    static int edgeID;
public:
    DataProcessor(const DataImporter &dataImporter);

    void computePaths(int source, algorithm_t algorithm);
    void buildPath(int source, int destiny);
};


#endif //MEETUP_RIDER_DATAPROCESSOR_H
