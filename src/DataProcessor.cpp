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
            std::cout << "Processing paths from " << source << " with Bellman Ford's Algorithm\n";
            this->dataImporter.getGraph()->bellmanFordShortestPath(Local(source));
            break;
        case dijkstra:
            std::cout << "Processing paths from " << source << " with Dijkstra's Algorithm\n";
            this->dataImporter.getGraph()->dijkstraShortestPath(Local(source));
            break;
    }
}

void DataProcessor::buildPath(int source, int destiny) {
    tmpPath = this->dataImporter.getGraph()->getPath(Local(source), Local(destiny));
    this->tmpEdges.clear();

    Vertex<Local> *vertex = nullptr;

    for (const auto& v : tmpPath) {
        if (v.getId() != destiny && v.getId() != source)
            this->dataImporter.getGraphViewer()->setVertexColor(v.getId(), "yellow");

        if (vertex == nullptr)
            vertex = this->dataImporter.getGraph()->findVertex(v);
        else {
            tmpEdges.push_back(edgeID);
            this->dataImporter.getGraphViewer()->addEdge(edgeID, vertex->getInfo().getId(), v.getId(), EdgeType::DIRECTED);
            this->dataImporter.getGraphViewer()->setEdgeColor(edgeID, "orange");
            this->dataImporter.getGraphViewer()->setEdgeThickness(edgeID++, 4);
            vertex = this->dataImporter.getGraph()->findVertex(v);
        }
    }
    this->dataImporter.getGraphViewer()->rearrange();
    std::cout << "Cost: " << this->pathCost() << std::endl;
}

void DataProcessor::cleanup() {
    for (auto v : tmpPath)
        this->dataImporter.getGraphViewer()->clearVertexColor(v.getId());
    for (int i = 0; i < tmpEdges.size(); i++)
        this->dataImporter.getGraphViewer()->removeEdge(tmpEdges[i]);
    this->dataImporter.getGraphViewer()->rearrange();
}

int DataProcessor::pathCost() {
    int result = 0;
    for (int i = 0; i < this->tmpPath.size() - 1; i++) {
        Vertex<Local>* v1 = this->dataImporter.getGraph()->findVertex(tmpPath[i]);
        Vertex<Local>* v2 = this->dataImporter.getGraph()->findVertex(tmpPath[i + 1]);
        for (auto w : v1->getAdj())
            if (w.getDest() == v2)
                result += w.getWeight();
    }
    return result;
}

void DataProcessor::markPoint(int id, point_t point) {
    switch (point) {
        case START:
            this->dataImporter.getGraphViewer()->setVertexColor(id, "green");
            break;
        case END:
            this->dataImporter.getGraphViewer()->setVertexColor(id, "red");
            break;
        case STOP:
            this->dataImporter.getGraphViewer()->setVertexColor(id, "blue");
            break;
    }
    this->dataImporter.getGraphViewer()->rearrange();
}

void DataProcessor::wait() {
    std::cout << "Press any key to continue ...";
    getchar();
}




