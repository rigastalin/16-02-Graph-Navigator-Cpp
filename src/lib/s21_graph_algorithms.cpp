#include "s21_graph_algorithms.h"

namespace s21 {
    std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
        std::vector<int> visited;
        std::stack<int> stack_;
//        stack<int> stack_;
        stack_.push(start_vertex);
        while (!stack_.empty()) {
            int vertex = stack_.top();
            stack_.pop();
            if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
                visited.push_back(vertex);
                for (auto neighbor: graph.getNeighbors(vertex)) {
                    stack_.push(neighbor);
                }
            }
        }
        return visited;
    }

    std::vector<int> GraphAlgorithms::BreadthFirstSearch(s21::Graph &graph, int start_vertex) {
        std::vector<int> visited;
        visited.resize(graph.getNumVertices() + 1, false);

        std::queue<int> queue;
        queue.push(start_vertex);
        visited[start_vertex] = true;

        while (!queue.empty()) {
            int current_vertex = queue.front();
            queue.pop();
            visited.push_back(current_vertex);

            for (int i = 0; i < graph.getNumVertices(); ++i) {
                if (graph[current_vertex][i] && !visited[i]) {
                    queue.push(i);
                    visited[i] = true;
                }
            }
        }
        return visited;
    }

}  // namespace s21