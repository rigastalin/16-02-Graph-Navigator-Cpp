#include "interface/interface.h"
#include "lib/s21_graph.h"
#include "lib/s21_graph_algorithms.h"

int main() {
//  Interface interface;
//  interface.Intro();
//  interface.Menu();

    s21::Graph graph;
    graph.loadGraphFromFile("/opt/goinfre/cflossie/A2_SimpleNavigator_v1.0-0/src/dataset/graph1.txt");
    s21::GraphAlgorithms graphAlgorithms;

    int startVertex = 0;
    std::vector<int> dfsResult = graphAlgorithms.DepthFirstSearch(graph, startVertex);
    std::cout << "\nDepth-First Search: \n";
    for (auto vertex : dfsResult) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

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
    return 0;
}