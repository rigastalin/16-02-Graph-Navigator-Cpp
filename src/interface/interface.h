#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include "../lib/s21_graph.h"
#include "../lib/s21_graph_algorithms.h"

class Interface {
 public:
  Interface();
  ~Interface();

  int Intro();
  int ShowMenu();
  void Menu();
  void BackToMenu();

  void printDelayed(const std::string& text, int delay);
  bool CheckGraph();

  void LoadFile();
  void BreadFirstSearch();
  void DepthFirstSearch();
  void ShortestPathTwoPeaks();
  void ShortestPathAllPeaks();
  void MinSpanningTree();
  void SalesmanProblem();

 private:
  int backInMenu = -1;
  int userInput;
  s21::Graph graph_;
  s21::GraphAlgorithms graphAlgorithms_;
};

#endif  //  SRC_INTERFACE_H_