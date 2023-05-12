#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <unistd.h>

class Interface {
 public:
    Interface();
    ~Interface();

    int Intro();
    int ShowMenu();
    void Menu();
    void BackToMenu();

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
};


#endif  //  SRC_INTERFACE_H_