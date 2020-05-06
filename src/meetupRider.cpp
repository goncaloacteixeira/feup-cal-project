//
// Created by skidr on 06/05/2020.
//

#include <iostream>

#include "GraphViewer/connection.h"
#include "GraphViewer/edgetype.h"
#include "GraphViewer/graphviewer.h"


int main() {
    GraphViewer* gv = new GraphViewer(600, 600, true);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    gv->addNode(0);
    gv->addNode(1);
    gv->rearrange();    // set changes to graphviewer

    gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED); // for undirected edges
    gv->addEdge(1, 0, 1, EdgeType::DIRECTED);   // for directed edges
    gv->rearrange();

    gv->removeNode(0);
    gv->rearrange();

    gv->addNode(2);
    gv->addEdge(2, 1, 2, EdgeType::UNDIRECTED);
    gv->rearrange();

    gv->setVertexLabel(2, "This is node 2");
    gv->setEdgeLabel(2, "This an labeled edge");
    gv->rearrange();

    gv->setVertexColor(2, "green");
    gv->setEdgeColor(2, "yellow");
    gv->rearrange();

    gv->setBackground("background.jpg");
    gv->rearrange();

    getchar();
}

