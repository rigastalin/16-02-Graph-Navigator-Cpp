#ifndef SRC_LIB_S21_GRAPH_ALGORITHMS_H_
#define SRC_LIB_S21_GRAPH_ALGORITHMS_H_

#pragma once

#include "s21_graph.h"
//#include "../containers/s21_queue.h"
//#include "../containers/s21_stack.h"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

namespace s21 {
    class GraphAlgorithms {
    public:
        GraphAlgorithms()  = default;
        ~GraphAlgorithms()  = default;

        std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
        std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
    };

}  // namespace s21
#endif //  SRC_LIB_S21_GRAPH_ALGORITHMS_H_
