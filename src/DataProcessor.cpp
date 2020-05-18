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
            this->dataImporter.getGraph()->bellmanFordShortestPath(Place(source));
            break;
        case dijkstra:
            std::cout << "Processing paths from " << source << " with Dijkstra's Algorithm\n";
            this->dataImporter.getGraph()->dijkstraShortestPath(Place(source));
            break;
        case floydwarshall:
            std::cout << "Processing all pairs of paths with Floyd Warshall's Algorithm\n";
            this->dataImporter.getGraph()->floydWarshallShortestPath();
            break;
    }
}

double DataProcessor::updateTmpPath(int source, int destination, algorithm_t algorithm) {
    tmpPath = (algorithm != floydwarshall) ? this->dataImporter.getGraph()->getPath(Place(source), Place(destination)) :
              this->dataImporter.getGraph()->getfloydWarshallPath(Place(source), Place(destination));

    return this->pathCost();
}

void DataProcessor::buildPath(int source, int destination) {
    Vertex *vertex = nullptr;

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
    for (auto v : this->getDataImporter().getGraph()->getVertexSet())
        this->dataImporter.getGraphViewer()->clearVertexColor(v->getInfo().getId());
    for (int i = 0; i < tmpEdges.size(); i++)
        this->dataImporter.getGraphViewer()->removeEdge(tmpEdges[i]);
    this->dataImporter.getGraphViewer()->rearrange();

    this->tmpEdges.clear();
}

double DataProcessor::pathCost() {
    double result = 0;
    for (int i = 0; i < this->tmpPath.size() - 1; i++) {
        Vertex* v1 = this->dataImporter.getGraph()->findVertex(tmpPath[i]);
        Vertex* v2 = this->dataImporter.getGraph()->findVertex(tmpPath[i + 1]);
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


std::vector<int> DataProcessor::sortPoints(int start, int finish, std::vector<Ride> *rides, algorithm_t algorithm){
    std::vector<int> sortedPoints;

    sortedPoints.push_back(start);
    int last_stop = start;
    int next_stop, edges_worked = 0;

    int next_stop_id;

    while(edges_worked < 2*rides->size()) {
        float current_cost = PLUS_INF;
        this->computePaths(last_stop, algorithm);
        for (int i = 0; i < rides->size(); ++i) {
            if (!rides->at(i).hasStarted()) {
                int cost = this->updateTmpPath(last_stop, rides->at(i).getOrigin(), algorithm);
                if (cost < current_cost) {
                    current_cost = cost;
                    next_stop = rides->at(i).getOrigin();
                    next_stop_id = i;
                }
            } else if (rides->at(i).hasStarted() && !rides->at(i).hasFinished()) {
                int cost = this->updateTmpPath(last_stop, rides->at(i).getDestiny(), algorithm);
                if (cost  < current_cost) {
                    current_cost = cost;
                    next_stop = rides->at(i).getDestiny();
                    next_stop_id = i;
                }
            } else {
                continue;
            }
        }
        sortedPoints.push_back(next_stop);
        last_stop = next_stop;
        if(!rides->at(next_stop_id).hasStarted()){
            rides->at(next_stop_id).startRide();
        }else{
            rides->at(next_stop_id).finishRide();
        }
        edges_worked++;
    }

    sortedPoints.push_back(finish);
    return sortedPoints;
}

void DataProcessor::paintPath(std::vector<int> sortedPoints, algorithm_t algorithm){


    this->markPoint(sortedPoints[0], START);
    this->computePaths(sortedPoints[0], algorithm);
    updateTmpPath(sortedPoints[0], sortedPoints[0+1], algorithm);
    buildPath(sortedPoints[0], sortedPoints[0+1]);

    for(int i = 1; i < sortedPoints.size()-1; ++i){
        this->markPoint(sortedPoints[i], STOP);
        this->computePaths(sortedPoints[i], algorithm);
        updateTmpPath(sortedPoints[i], sortedPoints[i+1], algorithm);
        buildPath(sortedPoints[i], sortedPoints[i+1]);
    }
    this->markPoint(sortedPoints[sortedPoints.size() - 1], END);
}

void DataProcessor::printPath(std::vector<int> sortedPoints){
    std::cout << "The path is: ";
    for (int i = 0; i < sortedPoints.size() - 1; i++)
        std::cout << std::to_string(sortedPoints[i]) << " -> ";
    std::cout << std::to_string(sortedPoints[sortedPoints.size() - 1]) << std::endl;
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
        double current_cost = PLUS_INF;
        for (int i = 1; i < points.size() - 1; i++) {
            if (i != index && std::find(worked.begin(), worked.end(), i) == worked.end()) {
                if (current_cost > weightMatrix[this->dataImporter.getGraph()->findVertexIdx(Place(points[index]))][this->dataImporter.getGraph()->findVertexIdx(Place(points[i]))]) {
                    current_index = i;
                    current_cost = weightMatrix[this->dataImporter.getGraph()->findVertexIdx(Place(points[index]))][this->dataImporter.getGraph()->findVertexIdx(Place(points[i]))];
                }
            }
        }
        updateTmpPath(points[index], points[current_index], floydwarshall);
        buildPath(points[index], points[current_index]);
        index = current_index;
        path.push_back(points[index]);
        worked.push_back(index);
        edges_worked++;
    }

    updateTmpPath(points[index], points[points.size() - 1], floydwarshall);
    buildPath(points[index], points[points.size() - 1]);
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

std::vector<int> DataProcessor::completePath(std::vector<int> points, algorithm_t algorithm) {
    int index = 0;
    int current_index = 0;
    int edges_worked = 0;
    std::vector<int> worked;
    worked.push_back(index);

    std::vector<int> path;
    path.push_back(points[0]);

    while (edges_worked < points.size() - 2) {
        this->computePaths(points[index], algorithm);
        double current_cost = PLUS_INF;
        for (int i = 1; i < points.size() - 1; i++) {
            if (i != index && std::find(worked.begin(), worked.end(), i) == worked.end()) {
                int cost = this->updateTmpPath(points[index], points[i], algorithm);
                if (current_cost > cost) {
                    current_index = i;
                    current_cost = cost;
                }
            }
        }
        updateTmpPath(points[index], points[current_index], algorithm);
        buildPath(points[index], points[current_index]);
        index = current_index;
        path.push_back(points[index]);
        worked.push_back(index);
        edges_worked++;
    }
    this->computePaths(points[index], algorithm);
    updateTmpPath(points[index], points[points.size() - 1], algorithm);
    buildPath(points[index], points[points.size() - 1]);
    path.push_back(points[points.size() - 1]);

    this->markPoint(points[0], START);
    for (int i = 1; i < points.size() -1 ; i++)
        this->markPoint(points[i], STOP);
    this->markPoint(points[points.size() - 1], END);


    printPath(path);
    /*std::cout << "The path is: ";
    for (int i = 0; i < path.size() - 1; i++)
        std::cout << std::to_string(path[i]) << " -> ";
    std::cout << std::to_string(path[path.size() - 1]) << std::endl;*/

    return path;
}

std::vector<int> DataProcessor::completePath(int start, int finish, std::vector<Ride> *rides, algorithm_t algorithm){
    std::vector<int> sortedPoints= sortPoints(start, finish, rides, algorithm);
    paintPath(sortedPoints, algorithm);
    printPath(sortedPoints);

    return sortedPoints;

}

std::vector<int> DataProcessor::fastestPath(std::vector<int> points, algorithm_t algorithm) {
    this->computePaths(points[0], algorithm);
    this->updateTmpPath(points[0], points[points.size() - 1], algorithm);
    this->buildPath(points[0], points[points.size() - 1]);

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

DataImporter &DataProcessor::getDataImporter() {
    return dataImporter;
}

void DataProcessor::pathAtoB(int source, int destination, algorithm_t algorithm) {
    this->computePaths(source, algorithm);
    this->updateTmpPath(source, destination, algorithm);
    this->buildPath(source, destination);
}




