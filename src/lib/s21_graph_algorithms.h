#ifndef SRC_LIB_S21_GRAPH_ALGORITHMS_H_
#define SRC_LIB_S21_GRAPH_ALGORITHMS_H_

#pragma once

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <random>
#include <vector>

#include "../containers/s21_queue.cpp"
#include "../containers/s21_stack.cpp"
#include "s21_graph.h"

namespace s21 {
const int MAX = std::numeric_limits<int>::max();
const double MAX_D = std::numeric_limits<double>::max();
const int NO_PARENT = -1;
const double ALPHA = 1.0;
const double BETA = 0.5;
const double EVAPORATION_RATE = 0.5;
const int NUM_ITERATIONS = 1000;
const double MIN_PROBABILITY = 1e-9;
const int NUM_ANTS = 111;
const int DEFAULT = -1;

struct TsmResult {
  std::vector<int> vertices;
  double distance;
};

class GraphAlgorithms {
 public:
  GraphAlgorithms(){};
  ~GraphAlgorithms(){};

  std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
  int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(
      Graph &graph);
  std::vector<std::vector<int>> GetLeastSpanningTree(Graph &graph);
  TsmResult SolveTravelingSalesmanProblem(Graph &graph);

 private:
  void AntMovement(Graph &graph,
                   const std::vector<std::vector<double>> &pheromoneMatrix,
                   std::vector<std::vector<int>> &antPath);
  void UpdatePheromone(Graph &graph,
                       std::vector<std::vector<double>> &pheromoneMatrix,
                       const std::vector<std::vector<int>> &antPaths);
  double CalculateRouteDistance(Graph &graph, const std::vector<int> &antPath);
  void UpdateBestRoute(Graph &graph,
                       const std::vector<std::vector<int>> &antPaths,
                       std::vector<int> &bestRoute, double &bestDistance);
};

}  // namespace s21
#endif  //  SRC_LIB_S21_GRAPH_ALGORITHMS_H_
