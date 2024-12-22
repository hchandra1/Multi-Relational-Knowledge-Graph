#ifndef NODE_H //this is my node.h file 
#define NODE_H

#include <string>

class Node {
public:
    std::string id;
    std::string name;
    std::string type;

    Node();
    Node(const std::string &nodeId, const std::string &nodeName, const std::string &nodeType);
    void update(const std::string &newName, const std::string &newType);
};

#endif 