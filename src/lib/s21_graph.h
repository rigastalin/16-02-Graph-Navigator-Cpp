#ifndef SRC_LIB_H_
#define SRC_LIB_H_

#include <string>

class Graph {
 public:
    Graph();
    ~Graph();

    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
};

#endif  // SRC_LIB_H_
