//
// Created by skidr on 06/05/2020.
//

#ifndef MEETUP_RIDER_DATAIMPORTER_H
#define MEETUP_RIDER_DATAIMPORTER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Place.h"
#include "GraphViewer/graphviewer.h"
#include "Graph.h"

/**
 * @brief Class DataImporter
 * This Class is responsible for importing the data from files into data structures.
 * It also assembles the graph on the GUI framework. (this is required if we are to process graph data)
 */
class DataImporter {
    std::string nodesFilename;  //!< Nodes file name
    std::string edgesFilename;  //!< Edges file name
    Graph<Place> graph;         //!< Graph Data Structure
    GraphViewer* graphViewer;   //!< GraphViewer GUI Framework

    /**
     * @brief Private Method to parse Edge Data
     * This method parses edge data into graph data structure
     */
    void parseEdges();
    /**
     * @brief Private Method to parse Node Data
     * This method parses node data into graph data structure
     */
    void parseNodes();
public:
    /**
     * @brief DataImporter Constructor
     * @param nodesFilename Nodes file name
     * @param edgesFilename Edges file name
     *
     * This constructor creates a GraphViewer instance
     */
    DataImporter(const std::string &nodesFilename, const std::string &edgesFilename);

    /**
     * @brief GET Method for graph data structure
     * @return Pointer to the graph
     */
    Graph<Place>* getGraph();

    /**
     * @brief Method to parse file's data
     * This method creates a graph data structure and
     * calls DataImporter::parseEdges() and DataImporter::parseNodes()
     */
    void parseData();

    /**
     * @brief Method to assemble the graph
     * This method is required. It assembles the graph info into the GraphViewer
     */
    void viewGraph();

    /**
     * @brief Waiting input method
     * This method waits for the user to press any key. Useful if we want to see the data
     * assembled this far as the GraphViewer may not wait for other changes.
     */
    void wait();

    /**
     * @brief GET Method for GraphViewer
     * @return pointer to graphViewer instance
     */
    GraphViewer *getGraphViewer() const;
};


#endif //MEETUP_RIDER_DATAIMPORTER_H
