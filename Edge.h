#ifndef EDGE_H //this is my edge.h file 
#define EDGE_H

#include <string>

class Edge 
{
public:
    double weight;
    std::string label;
    std::string destination;
    Edge(double edgeWeight, const std::string &edgeLabel, const std::string &destId);
};

#endif 
