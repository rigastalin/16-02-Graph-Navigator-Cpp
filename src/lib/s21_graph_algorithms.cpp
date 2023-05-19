#include "s21_graph_algorithms.h"

namespace s21 {
    std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph, int start_vertex) {
        std::vector<int> visited;
        s21::stack<int> stack_;
        stack_.push(start_vertex);
        while (!stack_.empty()) {
            int current_vertex = stack_.top();
            stack_.pop();
            if (std::find(visited.begin(), visited.end(), current_vertex) == visited.end()) {
                visited.push_back(current_vertex);

                std::vector<int> neighbors = graph.getNeighbors(current_vertex);

                for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                    int neighbor = *it;
                    if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                        stack_.push(neighbor);
                    }
                }
            }
        }
        return visited;
    }

    std::vector<int> GraphAlgorithms::BreadthFirstSearch(s21::Graph &graph, int start_vertex) {
        std::vector<bool> visited;
        visited.resize(graph.getNumVertices() + 1, false);

        std::vector<int> traversal_order;
        s21::queue<int> queue_;

        queue_.push(start_vertex);
        visited[start_vertex] = true;

        while (!queue_.empty()) {
            int current_vertex = queue_.front();
            queue_.pop();
            traversal_order.push_back(current_vertex);

            for (int adj_vertex : graph.getAdjacent(current_vertex)) {
                if (!visited[adj_vertex]) {
                    queue_.push(adj_vertex);
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


    // ================>  TRAVELING SALES PROBLEM (ANT WAY)  <================
    TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
        int num_vertices = graph.getNumVertices();
        int num_ants = num_vertices;
        std::vector<std::vector<double> > pheromoneMatrix(num_vertices, std::vector<double>(num_vertices, 1.0));

        std::vector<std::vector<int> > antPath(num_ants, std::vector<int>(num_vertices + 1));

        std::vector<int> bestRoute;
        double bestDistance = MAX_D;
        // Цикл по итерациям
        for (int iteration = 0; iteration < NUM_ITERATIONS; ++iteration) {
            // Перемещение муравьев
            AntMovement(graph, pheromoneMatrix, antPath);
            UpdatePheromone(graph, pheromoneMatrix, antPath);
            UpdateBestRoute(graph, antPath, bestRoute, bestDistance);
        }

            TsmResult result;
            result.distance = bestDistance;
            result.vertices = bestRoute;
            return result;
    }

    void GraphAlgorithms::AntMovement(s21::Graph &graph,
                                      const std::vector<std::vector<double>> &pheromoneMatrix,
                                      std::vector<std::vector<int>> &antPath) {
        int num_vertices = graph.getNumVertices();
        int num_ants = num_vertices;

        for (int ant = 0; ant < num_ants; ++ant) {
            // Начальная вершина
            int current_vertex = 0;
            if (ant != 0) {
                current_vertex = ant % num_vertices;
            }
            antPath[ant][0] = current_vertex;

            std::vector<bool> visited(num_vertices, false);
            visited[current_vertex] = true;

            // Посещение остальных вершин
            for (int i = 1; i < num_vertices; ++i) {
                std::vector<int> available_vertices;
                for (int vertex = 0; vertex < num_vertices; ++vertex) {
                    if (!visited[vertex]) {
                        available_vertices.push_back(vertex);
                    }
                }

                std::random_device randomDevice;
                std::mt19937 gen(randomDevice());
                std::shuffle(available_vertices.begin(), available_vertices.end(), gen);

                // Выбор следующей вершины на основе вероятностей
                double sumProbabilities = 0.0;
                std::vector<double> probabilities(available_vertices.size());
                for (size_t j = 0; j < available_vertices.size(); ++j) {
                    double pheromone = pheromoneMatrix[current_vertex][available_vertices[j]];
                    double distance = graph.getDistance(current_vertex, available_vertices[j]);
                    if (distance != 0) {
                        probabilities[j] = std::pow(pheromone, ALPHA) * std::pow(1.0 / distance, BETA);
                    } else {
                        probabilities[j] = MIN_PROBABILITY;
                    }
                    sumProbabilities += probabilities[j];
                }

                for (size_t j = 0; j < available_vertices.size(); ++j) {
                    probabilities[j] /= sumProbabilities;
                }

                // Выбор следующей вершины
                double randomValue = static_cast<double>(rand()) / RAND_MAX;
                double cumulativeProbability = 0.0;
                int next_vertex = -1;
                for (size_t j = 0; j < available_vertices.size(); ++j) {
                    cumulativeProbability += probabilities[j];
                    if (randomValue <= cumulativeProbability) {
                        next_vertex = available_vertices[j];
                        break;
                    }
                }

                // Проверка, что следующая вершина не была посещена ранее
                if (next_vertex == -1) {
                    double max_probability = -1.0;
                    for (size_t j = 0; j < available_vertices.size(); ++j) {
                        if (probabilities[j] > max_probability && available_vertices[j] != current_vertex) {
                            max_probability = probabilities[j];
                            next_vertex = available_vertices[j];
                        }
                    }
                }

                // Обновление текущей вершины
                current_vertex = next_vertex;
                antPath[ant][i] = current_vertex;
                visited[current_vertex] = true;
            }

            antPath[ant][num_vertices] = antPath[ant][0];
        }
    }

    void GraphAlgorithms::UpdatePheromone(s21::Graph &graph, std::vector<std::vector<double>> &pheromoneMatrix,
                                          const std::vector<std::vector<int>> &antPaths) {
        int num_vertices = graph.getNumVertices();
        // Обновление феромона
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = 0; j < num_vertices; ++j) {
                if (i != j) {
                    pheromoneMatrix[i][j] *= EVAPORATION_RATE;
                }
            }
        }

        for (const auto &antPath : antPaths) {
            double totalDistance = CalculateRouteDistance(graph, antPath);

            // Обновление феромона на маршруте текущего муравья
            for (int i = 0; i < num_vertices - 1; ++i) {
                int vertex1 = antPath[i];
                int vertex2 = antPath[i + 1];
                pheromoneMatrix[vertex1][vertex2] += 1.0 / totalDistance;
            }
        }
    }

    double GraphAlgorithms::CalculateRouteDistance(s21::Graph &graph, const std::vector<int> &antPath) {
        double totalDistance = 0.0;
        for (int i = 0; i < antPath.size(); ++i) {
            int vertex1 = antPath[i];
            int vertex2 = antPath[i + 1];
            totalDistance += graph.getDistance(vertex1, vertex2);
        }
        return totalDistance;
    }

    void GraphAlgorithms::UpdateBestRoute(s21::Graph &graph, const std::vector<std::vector<int>> &antPaths,
                                          std::vector<int> &bestRoute, double &bestDistance) {
        for (const auto  &antPath : antPaths) {
            double  totalDistance = CalculateRouteDistance(graph, antPath);
            if (totalDistance < bestDistance) {
                bestDistance = totalDistance;
                bestRoute = antPath;
            }
        }
    }

}  // namespace s21