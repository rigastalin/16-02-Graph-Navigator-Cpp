#ifndef SRC_LIB_S21_GRAPH_H_
#define SRC_LIB_S21_GRAPH_H_

#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace s21 {
    class Graph {
    public:
        Graph() = default;
        ~Graph() = default;
        explicit Graph(const std::vector<std::vector<int> >& matrix);

        void loadGraphFromFile(std::string filename);
        void exportGraphToDot(std::string filename) const;

        std::vector<int> getNeighbors(int vertex) const;
        int getNumVertices() const;

        void printGraph() const;

        std::vector<int>  getAdjacent(int current_index);

    private:
        std::vector<std::vector<int> > m_matrix;
        int m_dimension;
    };

}  // namespace s21
#endif  // SRC_LIB_S21_GRAPH_H_
