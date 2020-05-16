//
// Created by skidr on 07/05/2020.
//

#ifndef MEETUP_RIDER_DATAPROCESSOR_H
#define MEETUP_RIDER_DATAPROCESSOR_H

#include "Graph.h"
#include "DataImporter.h"

#define PLUS_INF std::numeric_limits<double>::max()
#define MINUS_INF std::numeric_limits<double>::min()

/**
 * @file DataProcessor.h
 */

/**
 * @enum algorithm_t
 * @brief Enum data type for algorithms used on the project
 */
typedef enum {
    bellmanford,    //!< Bellman Ford's algorithm
    dijkstra,       //!< Dijkstra's algorithm
    floydwarshall,  //!< Floyd Warshall's algorithm
} algorithm_t;

/**
 * @enum point_t
 * @brief Enum data type for our points
 *
 * This is useful to mark the nodes in our graphViewer as starting points,
 * stopping points and end points.
 */
typedef enum {
    START,  //!< Point where the ride starts
    END,    //!< Point where the ride ends
    STOP,   //!< Stopping point on the ride
} point_t;

/**
 * @brief DataProcessor Class
 *
 * This class processes the data imported by DataImporter. In order properly use this class
 * we need to call DataImporter::viewGraph() so it can assemble the graph on the GraphViewer class.
 */
class DataProcessor {
    DataImporter dataImporter;      //!< DataImporter instance
    static int edgeID;              //!< static value for edgeID - starts at 1000000 so we never have conflicts with edges ID
    std::vector<int> tmpEdges;      //!< Temporary field for edges marked on the GUI framework
    std::vector<Place> tmpPath;     //!< Temporary filed for path created by a builder function
public:
    /**
     * @brief DataProcessor Constructor
     * @param dataImporter an object of DataImporter filled with data and a graph
     */
    DataProcessor(const DataImporter &dataImporter);

    /**
     * @brief Build shortest path on the framework
     * @param source        Starting Node's ID
     * @param destination   Ending Node's ID
     * @param algorithm     Algorithm to be used to build shortest path from source to destination
     */
    void buildPath(int source, int destination);

    /**
     * @brief Function to mark a point on the framework
     * @param id    Node's ID to be marked
     * @param point Type of point to be marked
     *
     * This function marks the points on the GUI Framework.
     * Red - END
     * Blue - STOP
     * Green - START
     */
    void markPoint(int id, point_t point);

    /**
     * @brief Function to compute paths from source
     * @param source        Starting Node's ID
     * @param algorithm     Algorithm to be used
     * This function is useful to compute the distance to all points from source. But it can also compute the
     * Floyd Warshall's algorithm.
     *
     * This function should be called before DataProcessor::buildPath().
     */
    void computePaths(int source, algorithm_t algorithm);

    /**
     * @brief useful function to check how to make calls
     * @param source        source
     * @param destination   destination
     * @param algorithm     algorithm to be used
     */
    void pathAtoB(int source, int destination, algorithm_t algorithm);

    /**
     * @brief Function to update tmpPath vector
     * @param source
     * @param destination
     * @param algorithm
     * @return path cost
     */
    int updateTmpPath(int source, int destination, algorithm_t algorithm);

    /**
     * @brief Method to assemble the best path from A to B, passing on a set of points
     * @param points Vector containing all the points. { START, STOP, STOP, [...], END }
     * @return returns a vector with the path ordered
     *
     * This method does not require calling DataProcessor::computePaths() before.
     */
    std::vector<int> completePath(std::vector<int> points);

    /**
     * @brief Method to assemble the best path from A to B, passing on a set of points
     * @param points Vector containing all the points. { START, STOP, STOP, [...], END }
     * @param algorithm Algorithm to be used
     * @return returns a vector with the path ordered
     *
     * This method does not require calling DataProcessor::computePaths() before.
     */
    std::vector<int> completePath(std::vector<int> points, algorithm_t algorithm);

    /**
     * @brief Method to assemble the best path from A to B, marking all stopping points on the way
     * @param points        Vector containing all the points. { START, STOP, STOP, [...], END }
     * @param algorithm     algorithm to be used
     * @return              vector with te path ordered
     *
     * This function calculates the best path from A to B, and if it happens to pass on a mentioned point,
     * it marks that point as a STOP point. This is usefull if we want to go from A to B ASAP but we dont mind
     * stopping alongside the ride.
     */
    std::vector<int> fastestPath(std::vector<int> points, algorithm_t algorithm);

    /**
     * @brief Calculcates the cost of the path, if a path on tmpPath field.
     * @return cost of the path
     */
    double pathCost();

    /**
     * @brief Cleans the framework
     *
     * This method cleans the path on the framework. It uses the tmpEdges and tmpPath to clear the path
     * assembled on the display. This is very useful when we want to draw many different paths on the GUI
     */
    void cleanup();

    /**
     * @brief Waiting input method
     *
     * This method waits for the user to press any key. Useful if we want to see the data
     * assembled this far as the GraphViewer may not wait for other changes.
     */
    void wait();

    DataImporter &getDataImporter();
};


#endif //MEETUP_RIDER_DATAPROCESSOR_H
