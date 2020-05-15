//
// Created by skidr on 07/05/2020.
//

#ifndef MEEPlaceUP_RIDER_GRAPH_H
#define MEEPlaceUP_RIDER_GRAPH_H

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include "MutablePriorityQueue.h"
#include <iostream>
#include "Place.h"

using namespace std;

 class Edge;
 class Graph;
 class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/


class Vertex {
    Place info;                // contents
    vector<Edge> adj;  // outgoing edges
    bool visited;          // auxiliary field
    double dist = 0;
    Vertex *path = nullptr;
    int queueIndex = 0; 		// required by MutablePriorityQueue
    void addEdge(Vertex *dest, double w);
public:
    Vertex(Place in);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    Place getInfo() const;

    const vector<Edge> &getAdj() const;

    double getDist() const;
    Vertex *getPath() const;
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};

/********************** Edge  ****************************/
class Edge {
    Vertex *orig; 	// Fp07
    Vertex * dest;      // destination vertex
    double weight;         // edge weight

    bool selected; // Fp07

public:
    Edge(Vertex *o, Vertex *d, double w);
    Vertex *getDest() const;
    friend class Graph;
    friend class Vertex;

    // Fp07
    double getWeight() const;
};

/*************************** Graph  **************************/
class Graph {
    vector<Vertex *> vertexSet;    // vertex set

    // Fp05
    Vertex * initSingleSource(const Place &orig);
    bool relax(Vertex *v, Vertex *w, double weight);
    double ** W = nullptr;   // dist
    int **P = nullptr;   // path
public:
    Vertex *findVertex(const Place &in) const;
    bool addVertex(const Place &in);
    bool addEdge(const Place &sourc, const Place &dest, double w);
    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;

    // Fp05 - single source
    void dijkstraShortestPath(const Place &s);
    void unweightedShortestPath(const Place &s);
    void bellmanFordShortestPath(const Place &s);
    vector<Place> getPath(const Place &origin, const Place &dest) const;

    // Fp05 - all pairs
    void floydWarshallShortestPath();
    vector<Place> getfloydWarshallPath(const Place &origin, const Place &dest) const;
    double** getDistanceMatrix();
    int findVertexIdx(const Place &in) const;
    ~Graph();

    // Fp07 - minimum spanning tree
    bool addBidirectionalEdge(const Place &sourc, const Place &dest, double w);
    vector<Vertex*> calculatePrim();
    vector<Vertex*> calculateKruskal();
};



#endif //MEEPlaceUP_RIDER_GRAPH_H
