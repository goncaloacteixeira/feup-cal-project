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
    floydwarshall,
} algorithm_t;

typedef enum {
    START,
    END,
    STOP,
} point_t;

class DataProcessor {
    DataImporter dataImporter;
    static int edgeID;
    std::vector<int> tmpEdges;
    std::vector<Local> tmpPath;

public:
    DataProcessor(const DataImporter &dataImporter);

    void buildPath(int source, int destiny, algorithm_t algorithm);
    void markPoint(int id, point_t point);
    void computePaths(int source, algorithm_t algorithm);
    std::vector<int> findPath(std::vector<int> points, algorithm_t algorithm);

    int pathCost();
    void cleanup();

    void wait();
};


#endif //MEETUP_RIDER_DATAPROCESSOR_H
