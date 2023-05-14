//#include "interface/interface.h"
#include "lib/s21_graph.h"

int main() {
//  Interface interface;
//  interface.Intro();
//  interface.Menu();
    s21::Graph graph;
    graph.loadGraphFromFile("dataset/graph1.txt");
    graph.printGraph();
//    graph.exportGraphToDot("graph.dot");
    return 0;
}