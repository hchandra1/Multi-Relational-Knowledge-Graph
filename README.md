# 🔗 Multi-Relational Knowledge Graph

This project implements a multi-relational, weighted, undirected graph in C++. It models complex relationships between entities, providing a way to analyze and query connections between nodes through paths and relationship weights.

## 🚀 Project Overview
Inspired by knowledge graphs used in search engines and AI systems, this project allows the creation and management of multi-relational graphs. Nodes represent entities (like people or documents), and edges represent weighted relationships between them. The project supports efficient graph operations such as pathfinding, adjacency queries, and graph traversal.

This project is designed to:
- Build and manage entity-based graphs.
- Store relationships with customizable weights and labels.
- Perform highest-weight pathfinding between nodes.
- Query entities and connections dynamically.

## 🎯 Key Features
- **Entity Management:** Add, delete, and update entities and relationships.  
- **Pathfinding:** Compute the highest-weight path between nodes using DFS (Depth-First Search).  
- **Adjacency Queries:** Retrieve all entities connected to a given node.  
- **Dynamic Graph Structure:** Handle nodes, edges, and relationships with efficient memory management.  
- **CLI-Based Commands:** Interact with the graph through simple text commands.  

## 🛠️ Technologies Used
- **Language:** C++  
- **Data Structures:** Graph (Adjacency List), DFS for pathfinding  
- **Platform:** Cross-platform (Windows/Linux/MacOS)  

---

## 📂 Project Structure
```
Knowledge-Graph/
│
├── src/
│   ├── Graph.cpp       # Core graph logic (pathfinding, entity management)
│   ├── Graph.h         # Graph class definition
│   ├── Node.cpp        # Node class implementation
│   ├── Node.h          # Node header (entity definition)
│   ├── Edge.cpp        # Edge class implementation
│   ├── Edge.h          # Edge header (relationship logic)
│   ├── main.cpp        # CLI interface to interact with the graph
│   ├── illegal_exception.h  # Custom exception for invalid arguments
│
├── data/
│   └── test_entities.txt # Custom test case for entities and relationships
│
├── Makefile               # Compilation instructions
│
└── README.md              # This file
```

---

## ⚙️ How It Works
1. **Graph Initialization:**  
   The graph starts empty, and entities and relationships can be added dynamically.  

2. **Add Entities and Relationships:**  
   Define entities (nodes) and their relationships (edges) with weights and labels.  
   ```
   ENTITY A Alice Researcher
   RELATIONSHIP A colleague B 3.5
   ```

3. **Query Relationships:**  
   Retrieve adjacent nodes, find paths, and compute the highest-weight path between entities.  
   ```
   PRINT A
   PATH A B
   HIGHEST
   ```

---

## 🚦 Running the Project
### 1. Clone and Navigate:
```bash
git clone <repo-link>
cd Knowledge-Graph
```

### 2. Compile the Project:
```bash
make
```

### 3. Run the Program:
```bash
./a.out
```

### 4. Example Commands:
```bash
LOAD data/test_entities.txt entities
ENTITY B Bob Engineer
RELATIONSHIP A mentor B 5.0
PRINT B
PATH A B
HIGHEST
EXIT
```

---

## 📜 Commands
| Command       | Description                                                    |
|---------------|----------------------------------------------------------------|
| **LOAD**      | Load entity/relationship data from a file.                     |
| **ENTITY**    | Add or update an entity with ID, name, and type.               |
| **RELATIONSHIP** | Add/update relationships between two entities with weights. |
| **PRINT**     | Print all adjacent entities of a node.                         |
| **DELETE**    | Remove an entity and all its connections.                      |
| **PATH**      | Find the highest-weight path between two entities.             |
| **HIGHEST**   | Compute the highest-weight path in the entire graph.           |
| **FINDALL**   | Query entities by name or type.                                |
| **EXIT**      | Exit the program.                                              |

---

## 🧪 Example Data (`test_entities.txt`)
```text
A Alice Researcher
B Bob Engineer
C Carol Designer
D Dan Manager
E Eve Analyst
RELATIONSHIP A mentor B 5.0
RELATIONSHIP B colleague C 3.0
RELATIONSHIP C reports_to D 4.0
RELATIONSHIP D works_with E 2.0
```

---

## 🎨 Why I Built This
I wanted to explore graph theory in C++ by building a flexible, multi-relational graph system. This project deepened my understanding of adjacency lists, DFS algorithms, and real-world applications of graph traversal.

---

## 🚧 Future Improvements
- **Shortest Path (Dijkstra):** Add shortest-path algorithms to complement highest-weight paths.  
- **Entity Visualization:** Build a simple visualization tool for the graph.  
- **Graph Export:** Enable exporting graph structures to visualize using external tools.  

---

## 📝 License
This project is open-source and available under the MIT License.
