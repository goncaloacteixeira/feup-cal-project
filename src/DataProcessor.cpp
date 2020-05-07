//
// Created by skidr on 07/05/2020.
//

#include "DataProcessor.h"


DataProcessor::DataProcessor(const DataImporter &dataImporter) : dataImporter(dataImporter) {

}

int DataProcessor::edgeID = 1000000;

void DataProcessor::computePaths(int source, algorithm_t algorithm) {
    switch (algorithm) {
        case bellmanford:
            this->dataImporter.getGraph()->bellmanFordShortestPath(Local(source));
            break;
        case dijkstra:
            this->dataImporter.getGraph()->dijkstraShortestPath(Local(source));
            break;
    }
}

void DataProcessor::buildPath(int source, int destiny) {
    auto path = this->dataImporter.getGraph()->getPath(Local(source), Local(destiny));
    Vertex<Local> *vertex = nullptr;

    std::vector<int> edgeIDs;

    for (const auto& v : path) {
        if (v.getId() == source)
            this->dataImporter.getGraphViewer()->setVertexColor(v.getId(), "green");
        else if (v.getId() == destiny)
            this->dataImporter.getGraphViewer()->setVertexColor(v.getId(), "red");
        else
            this->dataImporter.getGraphViewer()->setVertexColor(v.getId(), "yellow");

        if (vertex == nullptr)
            vertex = this->dataImporter.getGraph()->findVertex(v);
        else {
            edgeIDs.push_back(edgeID);
            this->dataImporter.getGraphViewer()->addEdge(edgeID, vertex->getInfo().getId(), v.getId(), EdgeType::DIRECTED);
            this->dataImporter.getGraphViewer()->setEdgeColor(edgeID++, "orange");
            vertex = this->dataImporter.getGraph()->findVertex(v);
        }
    }

    this->dataImporter.getGraphViewer()->rearrange();

    std::cout << "Press any key to continue ...";
    getchar();

    /* cleanup */
    for (auto v : path)
        this->dataImporter.getGraphViewer()->clearVertexColor(v.getId());
    for (int i = 0; i < edgeIDs.size(); i++)
        this->dataImporter.getGraphViewer()->removeEdge(edgeIDs[i]);
}

