#ifndef SRC_LIB_S21_GRAPH_ALGORITHMS_H_
#define SRC_LIB_S21_GRAPH_ALGORITHMS_H_

#pragma once

#include "s21_graph.h"
#include "../containers/s21_queue.h"
#include "../containers/s21_stack.h"
#include <vector>

namespace s21 {
    class GraphAlgorithmss {
    public:
        static std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex;
        static std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);

    };

}  // namespace s21
#endif //  SRC_LIB_S21_GRAPH_ALGORITHMS_H_
