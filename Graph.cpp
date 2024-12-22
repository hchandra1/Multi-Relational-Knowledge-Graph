// this is my graph.cpp file
#include "Graph.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

// this is my constructor
Graph::Graph()
 {

}

// this is a helpeter function to validate IDs 
bool Graph::isValidId(const std::string &id) const 
{
    for (char c : id) 
    {
        if (!std::isalnum(static_cast<unsigned char>(c)))
         {
            return false;
        }
    }
    return true;
}

// this is my helper function to find node index by ID
int Graph::findNodeIndex(const std::string &id) const
 {
    for (size_t i = 0; i < nodeOrder.size(); ++i) 
    {
        if (nodeOrder[i] == id) 
        {
            return static_cast<int>(i);
        }
    }
    return -1; 
}

// Add or update an entity
std::string Graph::addEntity(const std::string &id, const std::string &name, const std::string &type) 
    {
    if (!isValidId(id)) 
    {
        // return sucness 
        return "success";
    }

    int index = findNodeIndex(id);
    if (index == -1) 
    {
        
        Node newNode(id, name, type);
        nodes.push_back(newNode);
        adjList.emplace_back(); 
        nodeOrder.push_back(id);
    } 
    else
     {
       
        nodes[index].update(name, type);
    }
    return "success"; 
}


std::string Graph::addRelationship(const std::string &source,  const std::string &label,   const std::string &dest, double weight) // my add relationship function
 {
    if (!isValidId(source) || !isValidId(dest)) 
    {
        return "illegal argument"; 
    }

    int srcIndex = findNodeIndex(source);
    int destIndex = findNodeIndex(dest);

    if (srcIndex == -1 || destIndex == -1)
     {
        return "failure"; 
    }

    // the logic here is to check if relationship already exists from source to dest
    bool updated = false;
    for (auto &edge : adjList[srcIndex]) 
    {
        if (edge.destination == dest) 
        {
            edge.label = label;
            edge.weight = weight;
            updated = true;
            break;
        }
    }

    if (!updated) 
    {
        
        adjList[srcIndex].emplace_back(weight, label, dest);
        
        adjList[destIndex].emplace_back(weight, label, source);
    } 
    else 
    {
  
        for (auto &edge : adjList[destIndex]) 
        {

            if (edge.destination == source) 
            {
                edge.label = label;
                edge.weight = weight;
                break;
            }
        }
    }

    return "success";
}

// this fuction is to print all adjacent nodes
std::string Graph::printAdjacent(const std::string &nodeId) const 
{
    if (!isValidId(nodeId)) 
    {
        return "illegal argument"; // this returns the appropitae messfgae acc to if its valid or not and this is the same logic followed for the rest of the funciton 
    }

    int nodeIndex = findNodeIndex(nodeId);
    if (nodeIndex == -1) 
    {
        return "failure"; 
    }

    std::vector<std::string> adjacent;
    for (const auto &edge : adjList[nodeIndex])
    {
        adjacent.push_back(edge.destination);
    }

    // this is to remove duplicates
    std::vector<std::string> uniqueAdjacent;
    for (const auto &dest : adjacent) 
    {
        if (std::find(uniqueAdjacent.begin(), uniqueAdjacent.end(), dest) == uniqueAdjacent.end())
         {
            uniqueAdjacent.push_back(dest);
        }
    }

    // this is to construct the output string
    std::ostringstream oss;
    for (size_t i = 0; i < uniqueAdjacent.size(); ++i)
     {
        oss << uniqueAdjacent[i];
        if (i != uniqueAdjacent.size() - 1) 
        {
            oss << " ";
        }
    }

    return oss.str();
}

// this is to deleteenitity
std::string Graph::deleteEntity(const std::string &nodeId)
 {
    if (!isValidId(nodeId)) 
    {
        return "illegal argument"; 
    }

    int nodeIndex = findNodeIndex(nodeId);
    if (nodeIndex == -1)
     {
        return "failure"; 
    }

    
    nodes.erase(nodes.begin() + nodeIndex);
    adjList.erase(adjList.begin() + nodeIndex);
    nodeOrder.erase(nodeOrder.begin() + nodeIndex);

 
    for (auto &edges : adjList)
     {
        edges.erase(
            std::remove_if(edges.begin(), edges.end(),  [&](const Edge &e) 
                           {
                             return e.destination == nodeId; 
                             }),
            edges.end());
    }

    return "success";
}

// this is my DFS helper Function to find the highest weight path
void Graph::dfs(int current, int end, double currentWeight, double &maxWeight,
               std::vector<std::string> &currentPath,
               std::vector<std::string> &maxPath,
               std::vector<bool> &visited) const 
               
               {
    visited[current] = true;
    currentPath.push_back(nodeOrder[current]);

    if (current == end) 
    {
        if (currentWeight > maxWeight) 
        {
            maxWeight = currentWeight;
            maxPath = currentPath;
        }
    } 
    else
     {
        for (const auto &edge : adjList[current]) 
        {
            int neighbor = findNodeIndex(edge.destination);
            if (neighbor != -1 && !visited[neighbor])
             {
                dfs(neighbor, end, currentWeight + edge.weight, maxWeight,
                    currentPath, maxPath, visited);
            }
        }
    }

    currentPath.pop_back();
    visited[current] = false;
}

// this is my path functiobn
std::string Graph::path(const std::string &start, const std::string &end) const
 {
    if (!isValidId(start) || !isValidId(end)) 
    {
        return "illegal argument";
    }

    int startIndex = findNodeIndex(start);
    int endIndex = findNodeIndex(end);

    if (startIndex == -1 || endIndex == -1) 
    {
        return "failure"; 
    }

    
    double maxWeight = 0.0; // wieghts are non negative
    std::vector<std::string> maxPath;
    std::vector<std::string> currentPath;
    std::vector<bool> visited(nodes.size(), false);

    
    dfs(startIndex, endIndex, 0.0, maxWeight, currentPath, maxPath, visited);

    if (maxPath.empty()) {
        return "failure"; // no path found
    }

    //this is to construct the output string
    std::ostringstream oss;
    for (size_t i = 0; i < maxPath.size(); ++i)
     {
        oss << maxPath[i];
        if (i != maxPath.size() - 1)
         {
            oss << " ";
        }
    }
    oss << " " << maxWeight;

    return oss.str();
}

// this is my highestweightpath function
std::string Graph::highestWeightPath() const
 {
    if (nodes.empty() || adjList.empty()) 
    {
        return "failure"; 
    }

    double maxWeight = 0.0; 
    std::string startNode, endNode;

    // this is to go over unique pairs of distinct node 
    for (size_t i = 0; i < nodeOrder.size(); ++i) 
    {
        for (size_t j = i + 1; j < nodeOrder.size(); ++j) 
        {
            std::string pathResult = path(nodeOrder[i], nodeOrder[j]);
            if (pathResult != "failure") 
            {
                // to exract weight and path nodes
                std::istringstream iss(pathResult);
                std::string token;
                std::vector<std::string> tokens;
                while (iss >> token) 
                {
                    tokens.push_back(token);
                }
                if (tokens.size() < 2) continue; // invalid 
                double weight = std::stod(tokens.back());

                std::string pathStart = tokens[0];
                std::string pathEnd = tokens[tokens.size() - 2];

                // reorder node pair based on upper to lower lexicographical order 
                std::string orderedStart, orderedEnd;
                if (pathStart > pathEnd)
                 { 
                    orderedStart = pathStart;
                    orderedEnd = pathEnd;
                }
                else 
                {
                    orderedStart = pathEnd;
                    orderedEnd = pathStart;
                }

                // updates if a higher weight is found
                if (weight > maxWeight) 
                {
                    maxWeight = weight;
                    startNode = orderedStart;
                    endNode = orderedEnd;
                }
            }
        }
    }

    if (maxWeight == 0.0 && startNode.empty() && endNode.empty())
     {
        return "failure"; // invalid paths only
    }

    // to construct the output string same logic as otherwise
    std::ostringstream oss;
    oss << startNode << " " << endNode << " " << maxWeight;
    return oss.str();
}

// this is my findall function 
std::string Graph::findAll(const std::string &fieldType,
                           const std::string &fieldValue) const 
                           {
    std::vector<std::string> results;

    for (const auto &id : nodeOrder)
     {
        int index = findNodeIndex(id);
        if (index == -1) continue;
        const Node &node = nodes[index];
        if ((fieldType == "name" && node.name == fieldValue) ||
            (fieldType == "type" && node.type == fieldValue))
             {
            results.push_back(id);
        }
    }

    if (results.empty()) 
    {
        return "failure"; // no mathcing node found
    }

    // this is to construct output string
    std::ostringstream oss;
    for (size_t i = 0; i < results.size(); ++i) {
        oss << results[i];
        if (i != results.size() - 1) {
            oss << " ";
        }
    }

    return oss.str();
}

// thi sis my load function
std::string Graph::loadFromFile(const std::string &filename,
                                const std::string &type) 
                                {
    std::ifstream file(filename.c_str());
    if (!file) 
    {
        return "failure"; 
    }

    std::string line;
    if (type == "entities")
     {
        while (std::getline(file, line)) 
        {
            if (line.empty())
                continue;
            std::istringstream iss(line);
            std::string id, name, nodeType;
            iss >> id >> name >> nodeType;
            if (iss.fail())
                continue;
            std::string result = addEntity(id, name, nodeType);
            
        }
    }
    else if (type == "relationships") 
    {
        while (std::getline(file, line)) 
        {
            if (line.empty())
                continue;
            std::istringstream iss(line);
            std::string source, label, dest;
            double weight;
            iss >> source >> label >> dest >> weight;
            if (iss.fail())
                continue;
            std::string result = addRelationship(source, label, dest, weight);
            
        }
    }
    else {
        file.close();
        return "failure";
    }

    file.close();
    return "success";
} 
