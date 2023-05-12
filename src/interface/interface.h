#ifndef SRC_INTERFACE_H_
#define SRC_INTERFACE_H_

#include <iostream>
#include <string>

class Interface {
 public:
    Interface();
    ~Interface();

    int ShowMenu();
    void Menu();
    void LoadFile();
    void BreadFirstSearch();
    void DepthFirstSearch();
    void ShortestPathTwoPeaks();
    void ShortestPathAllPeaks();
    void MinSpanningTree();
    void SalesmanProblem();

private:
    int userInput;
};


#endif  //  SRC_INTERFACE_H_