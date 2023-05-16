#ifndef SRC_LIB_S21_GRAPH_ALGORITHMS_H_
#define SRC_LIB_S21_GRAPH_ALGORITHMS_H_

#pragma once

#include "s21_graph.h"
#include "../containers/s21_queue.cpp"
#include "../containers/s21_stack.cpp"

#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

const int MAX = std::numeric_limits<int>::max();
const int NO_PARENT = -1;

namespace s21 {
    class GraphAlgorithms {
    public:
        GraphAlgorithms()  = default;
        ~GraphAlgorithms()  = default;

        std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
        std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);

        int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
        std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(Graph &graph);

    };

}  // namespace s21
#endif //  SRC_LIB_S21_GRAPH_ALGORITHMS_H_
