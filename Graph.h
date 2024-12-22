// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include "illegal_exception.h" 
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

class Graph {
private:
    std::vector<Node> nodes; // this the list of nodes
    std::vector<std::vector<Edge>> adjList; 
    std::vector<std::string> nodeOrder; 
    bool isValidId(const std::string &id) const;
    int findNodeIndex(const std::string &id) const; // this is my helper function

    // dfs helper function
    void dfs(int current, int end, double currentWeight, double &maxWeight,
             std::vector<std::string> &currentPath,
             std::vector<std::string> &maxPath,
             std::vector<bool> &visited) const;

public:
    Graph();

    std::string addEntity(const std::string &id, const std::string &name, const std::string &type);
    std::string addRelationship(const std::string &source, const std::string &label, const std::string &dest, double weight);
    std::string printAdjacent(const std::string &nodeId) const;
    std::string deleteEntity(const std::string &nodeId);
    std::string path(const std::string &start, const std::string &end) const;
    std::string highestWeightPath() const;
    std::string findAll(const std::string &fieldType, const std::string &fieldValue) const;

    std::string loadFromFile(const std::string &filename, const std::string &type);
};

#endif 