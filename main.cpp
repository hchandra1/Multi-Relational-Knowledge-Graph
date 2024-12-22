// main.cpp
#include "Graph.h"
#include "illegal_exception.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    Graph graph;
    std::string command;
    while (std::cin >> command) 
    { //all commands acc to the document specification
        try {
            if (command == "LOAD")
             {
                std::string filename, type;
                std::cin >> filename >> type;
                std::cout << graph.loadFromFile(filename, type) << std::endl;
            }
            else if (command == "ENTITY")
             {
                std::string id, name, type;
                std::cin >> id >> name >> type;
                std::cout << graph.addEntity(id, name, type) << std::endl;
            }
            else if (command == "RELATIONSHIP")
             {
                std::string source, label, dest;
                double weight;
                std::cin >> source >> label >> dest >> weight;
                std::cout << graph.addRelationship(source, label, dest, weight) << std::endl;
            }
            else if (command == "PRINT")
             {
                std::string id;
                std::cin >> id;
                std::cout << graph.printAdjacent(id) << std::endl;
            }
            else if (command == "DELETE")
             {
                std::string id;
                std::cin >> id;
                std::cout << graph.deleteEntity(id) << std::endl;
            }
            else if (command == "PATH") 
            {
                std::string start, end;
                std::cin >> start >> end;
                std::cout << graph.path(start, end) << std::endl;
            }
            else if (command == "HIGHEST") 
            {
                std::cout << graph.highestWeightPath() << std::endl;
            }
            else if (command == "FINDALL") 
            {
                std::string fieldType, fieldValue;
                std::cin >> fieldType >> fieldValue;
                std::cout << graph.findAll(fieldType, fieldValue) << std::endl;
            }
            else if (command == "EXIT")
             {
                break;
            }
            
        }
        catch (illegal_exception &e)
         {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
