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
        case floydwarshall:
            std::cout << "Processing all pairs of paths with Floyd Warshall's Algorithm\n";
            this->dataImporter.getGraph()->floydWarshallShortestPath();
            break;
    }
}

void DataProcessor::buildPath(int source, int destination, algorithm_t algorithm) {
    // needs to compute path first !
    tmpPath = (algorithm != floydwarshall) ? this->dataImporter.getGraph()->getPath(Local(source), Local(destination)) :
            this->dataImporter.getGraph()->getfloydWarshallPath(Local(source), Local(destination));

    this->tmpEdges.clear();

    Vertex<Local> *vertex = nullptr;

    for (const auto& v : tmpPath) {
        if (v.getId() != destination && v.getId() != source)
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
    std::cout << "Cost from " << source << " to " << destination << ": " << this->pathCost() << std::endl;
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

std::vector<int> DataProcessor::completePath(std::vector<int> points) {
    std::cout << "Building path from A to B passing in C with Floyd Warshall's algorithm\n";

    int index = 0;
    int current_index = 0;
    int edges_worked = 0;
    std::vector<int> worked;
    worked.push_back(index);

    std::vector<int> path;
    path.push_back(points[0]);

    this->dataImporter.getGraph()->floydWarshallShortestPath();
    auto weightMatrix = this->dataImporter.getGraph()->getDistanceMatrix();

    while (edges_worked < points.size() - 2) {
        double current_cost = INT16_MAX;
        for (int i = 1; i < points.size() - 1; i++) {
            if (i != index && std::find(worked.begin(), worked.end(), i) == worked.end()) {
                if (current_cost > weightMatrix[this->dataImporter.getGraph()->findVertexIdx(Local(points[index]))][this->dataImporter.getGraph()->findVertexIdx(Local(points[i]))]) {
                    current_index = i;
                    current_cost = weightMatrix[this->dataImporter.getGraph()->findVertexIdx(Local(points[index]))][this->dataImporter.getGraph()->findVertexIdx(Local(points[i]))];
                }
            }
        }
        buildPath(points[index], points[current_index], floydwarshall);
        index = current_index;
        path.push_back(points[index]);
        worked.push_back(index);
        edges_worked++;
    }

    buildPath(points[index], points[points.size() - 1], floydwarshall);
    path.push_back(points[points.size() - 1]);

    this->markPoint(points[0], START);
    for (int i = 1; i < points.size() -1 ; i++)
        this->markPoint(points[i], STOP);
    this->markPoint(points[points.size() - 1], END);


    std::cout << "The path is: ";
    for (int i = 0; i < path.size() - 1; i++)
        std::cout << std::to_string(path[i]) << " -> ";
    std::cout << std::to_string(path[path.size() - 1]) << std::endl;

    return path;
}

std::vector<int> DataProcessor::fastestPath(std::vector<int> points, algorithm_t algorithm) {
    this->computePaths(points[0], algorithm);
    this->buildPath(points[0], points[points.size() - 1], algorithm);

    std::vector<int> path;
    path.push_back(points[0]);

    for (int i = 1; i < points.size() - 1; i++) {
        if (std::find(this->tmpPath.begin(), this->tmpPath.end(), points[i]) != this->tmpPath.end()) {
            this->markPoint(points[i], STOP);
            path.push_back(points[i]);
        }
    }
    path.push_back(points[points.size() - 1]);
    markPoint(points[0], START);
    markPoint(points[points.size() - 1], END);
    return path;
}




