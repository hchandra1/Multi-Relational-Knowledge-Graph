#include "Node.h" //this is my node.h file 

Node::Node() : id(""), name(""), type("")
 {

}

Node::Node(const std::string &nodeId, const std::string &nodeName, const std::string &nodeType)
    : id(nodeId), name(nodeName), type(nodeType) 
    {

    }

void Node::update(const std::string &newName, const std::string &newType) 
{
    name = newName;
    type = newType;
}
