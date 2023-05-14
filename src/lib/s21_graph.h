#ifndef SRC_LIB_H_
#define SRC_LIB_H_

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
        explicit Graph(const std::vector<std::vector<int> >& matrix);

        void loadGraphFromFile(std::string filename);
        void exportGraphToDot(std::string filename) const;

        void printGraph() const;

    private:
        std::vector<std::vector<int> > m_matrix;
        int m_dimension;
    };

}  // namespace s21
#endif  // SRC_LIB_H_
