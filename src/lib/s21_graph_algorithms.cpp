#include "s21_graph_algorithms.h"

namespace s21 {
    std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
        std::vector<int> visited;
        s21::stack<int> stack_;
        stack_.push(start_vertex);
        while (!stack_.empty()) {
            int vertex = stack_.top();
            stack_.pop();
            if (std::find(visited.begin(), visited.end(), vertex) == visited.end()) {
                visited.push_back(vertex);
                for (auto neighbor : graph.getNeighbors(vertex)) {
                    stack_.push(neighbor);
                }
            }
        }
        return visited;
    }

    std::vector<int> GraphAlgorithms::BreadthFirstSearch(s21::Graph &graph, int start_vertex) {
        std::vector<bool> visited;
        visited.resize(graph.getNumVertices() + 1, false);

        std::vector<int> traversal_order;
        s21::queue<int> queue;
//        std::queue<int> queue;

        queue.push(start_vertex);
        visited[start_vertex] = true;

        while (!queue.empty()) {
            int current_vertex = queue.front();
            queue.pop();
            traversal_order.push_back(current_vertex);

            for (int adj_vertex : graph.getAdjacent(current_vertex)) {
                if (!visited[adj_vertex]) {
                    queue.push(adj_vertex);
                    visited[adj_vertex] = true;
                }
            }
        }
        return traversal_order;
    }

    int GraphAlgorithms::GetShortestPathBetweenVertices(s21::Graph &graph, int vertex1, int vertex2) {
        int num_vertices = graph.getNumVertices();
        std::vector<int> distance(num_vertices, MAX);
        std::vector<int> parent(num_vertices, NO_PARENT);

        distance[vertex1] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > priorityQueue;
        priorityQueue.push(std::make_pair(distance[vertex1], vertex1));

        while (!priorityQueue.empty()) {
            int current_vertex = priorityQueue.top().second;
            int current_distance = priorityQueue.top().first;
            priorityQueue.pop();

            if (current_distance > distance[current_vertex]) {
                continue;
            }

            for (int adj_vertex: graph.getAdjacent(current_vertex)) {
                int edge_weight = graph[current_vertex][adj_vertex];
                int new_distance = distance[current_vertex] + edge_weight;

                if (new_distance < distance[adj_vertex]) {
                    distance[adj_vertex] = new_distance;
                    parent[adj_vertex] = current_vertex;
                    priorityQueue.push(std::make_pair(distance[adj_vertex], adj_vertex));
                }
            }
        }
        std::vector<int> path;
        int cur_vertex = vertex2;
        while (cur_vertex != NO_PARENT) {
            path.push_back(cur_vertex);
            cur_vertex = parent[cur_vertex];
        }
        std::reverse(path.begin(), path.end());

        std::cout << "SHORTEST PATH FROM " << vertex1 << " TO " << vertex2 << ": ";
        for (int vertex : path) {
            std::cout << vertex << " ";
        }

        return distance[vertex2];
    }


    std::vector<std::vector<int> > GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
        int num_verticies = graph.getNumVertices();
        std::vector<std::vector<int> > distance(num_verticies, std::vector<int> (num_verticies, MAX));

        for (int i = 0; i < num_verticies; i++) {
            for (int j = 0; j < num_verticies; j++) {
                if (graph[i][j]) {
                    distance[i][j] = graph[i][j];
                }
            }
        }

        for (int k = 0; k < num_verticies; k++) {
            for (int i = 0; i < num_verticies; i++) {
                for (int j = 0; j < num_verticies; j++) {
                    if (distance[i][k] != MAX && distance[k][j] != MAX && distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[j][k];
                    }
                }
            }
        }

        return distance;
    }

    std::vector<std::vector<int> > GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {
        int num_vertices = graph.getNumVertices();
        std::vector<std::vector<int> > mst(num_vertices, std::vector<int>(num_vertices, 0));
        std::vector<bool> visited(num_vertices, false);
        std::vector<int> weights(num_vertices, MAX);

        int start_index = 0;
        weights[start_index] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int,int> > > priorityQueue;
        priorityQueue.push(std::make_pair(0, start_index));

        while (!priorityQueue.empty()) {
            int current_index = priorityQueue.top().second;
            priorityQueue.pop();

            visited[current_index] = true;

            for (int neighbor_vertex = 0; neighbor_vertex < num_vertices; ++neighbor_vertex) {
                int weight = graph[current_index][neighbor_vertex];

                if (!visited[neighbor_vertex] && weight < weights[neighbor_vertex]) {
                    weights[neighbor_vertex] = weight;
                    priorityQueue.push(std::make_pair(weight, neighbor_vertex));
                }
            }
        }

        for (int vertex = 0; vertex < num_vertices; ++vertex) {
            if (vertex == start_index) {
                continue;
            }

            int parent_vertex = vertex;
            int weight = weights[vertex];

            mst[parent_vertex][vertex] = weight;
            mst[vertex][parent_vertex] = weight;
        }

        return mst;
    }

}  // namespace s21