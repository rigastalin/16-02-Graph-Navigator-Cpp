//#include "interface/interface.h"
#include "lib/s21_graph.h"

int main() {
//  Interface interface;
//  interface.Intro();
//  interface.Menu();
    s21::Graph graph;
    graph.loadGraphFromFile("/opt/goinfre/cflossie/A2_SimpleNavigator_v1.0-0/src/dataset/graph1.txt");
    graph.printGraph();

    graph.exportGraphToDot("dataset/graph.dot");
    return 0;
}