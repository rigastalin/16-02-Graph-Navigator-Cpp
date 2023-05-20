#include "interface/interface.h"
#include "lib/s21_graph.h"
#include "lib/s21_graph_algorithms.h"

int main() {
  Interface interface;
//  interface.Intro();
  interface.Menu();

    s21::Graph graph;
    graph.loadGraphFromFile("/opt/goinfre/cflossie/A2_SimpleNavigator_v1.0-0/src/dataset/graph1.txt");
    s21::GraphAlgorithms graphAlgorithms;

//    int startVertex = 0;
//    std::vector<int> dfsResult = graphAlgorithms.DepthFirstSearch(graph, startVertex);
//    std::cout << "\nDepth-First Search: \n";
//    for (auto vertex : dfsResult) {
//        std::cout << vertex << " ";
//    }
//    std::cout << std::endl;

//    std::vector<int> bfsResult = graphAlgorithms.BreadthFirstSearch(graph, startVertex);
//    std::cout << "\nBreadth-First Search: \n";
//    for (auto vertext : bfsResult) {
//        std::cout << vertext << " ";
//    }
//    std::cout << std::endl;

//    std::cout << std::endl;
//    int gspbvres = graphAlgorithms.GetShortestPathBetweenVertices(graph, 2, 3);
//    std::cout << gspbvres << std::endl;

//    auto res = graphAlgorithms.GetShortestPathsBetweenAllVertices(graph);
//    std::cout << "Shortest paths between all vertices:" << std::endl;
//    for (int i = 0; i < graph.getNumVertices(); i++) {
//        for (int j = 0; j < graph.getNumVertices(); j++) {
//            std::cout << res[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

//    RIGHT SOLUTION
//    sequence of traversing vertices: 1-8-5-4-10-6-3-7-2-11-9-1
//                                     0-7-4-3-9-5-2-6-1-10-8-0
//    route length: 253


//    s21::TsmResult result;
//    result = graphAlgorithms.SolveTravelingSalesmanProblem(graph);
//
//    std::cout << "Vertices: ";
//    for (int vertex : result.vertices) {
//        std::cout << vertex << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "Distance: " << result.distance << std::endl;

    return 0;
}