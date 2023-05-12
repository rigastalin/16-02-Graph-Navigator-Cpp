#include "interface.h"

Interface::Interface() { Menu(); };

Interface::~Interface() {};

int Interface::ShowMenu() {
    system("clear");
   std::cout
   << ""
      "╔════════════════════════════════════════════════════════════════╗\n"
      "║                                                                ║\n"
      "║                            МЕНЮ                                ║\n"
      "║                      SIMPLE NAVIGATOR                          ║\n"
      "╠════════════════════════════════════════════════════════════════╣\n"
      "║ 1. Загрузка исходного графа из файла                           ║\n"
      "║ 2. Обход графа в ширину                                        ║\n"
      "║ 3. Обход графа в глубину                                       ║\n"
      "║ 4. Поиск кратчайшего пути между произвольными двумя вершинами  ║\n"
      "║ 5. Поиск кратчайших путей между всеми парами вершин в графе    ║\n"
      "║ 6. Поиск минимального остовного дерева в графе                 ║\n"
      "║ 7. Решение задачи комивояжера                                  ║\n"
      "║                                                                ║\n"
      "║                                                                ║\n"
      "║ 0. Выход                                                       ║\n"
      "╚═══════════════════CFLOSSIE & GCONN & TORELL════════════════════╝\n"
      << std::endl;
    return 666;
}

void Interface::Menu() {
    bool isNotExit = true;
    do {
        ShowMenu();
        std::cout << "ВЫБЕРИТЕ ПУНКТ МЕНЮ: ";
        std::cin >> userInput;
        switch (userInput) {
            case 1:
                LoadFile();
                break;
            case 2:
                BreadFirstSearch();
                break;
            case 3:
                DepthFirstSearch();
                break;
            case 4:
                ShortestPathTwoPeaks();
                break;
            case 5:
                ShortestPathAllPeaks();
                break;
            case 6:
                MinSpanningTree();
                break;
            case 7:
                SalesmanProblem();
                break;
            case 0:
                system("clear");
                isNotExit = false;
                break;
            default:
                std::cout << "НЕВЕРНЫЙ ПУНКТ МЕНЮ!\n";
                break;
        }
    } while (isNotExit);
    exit(0);
}

void Interface::LoadFile() {
    std::cout << "FUCK YOU 1" << std::endl;

    int backInMenu = -1;
    std::cout << "ЧТОБЫ ВЕРНУТЬСЯ В МЕНЮ, НАЖМИ \"1\" ИЛИ \"0\" ДЛЯ ВЫХОДА" << std::endl;
    std::cin >> backInMenu;
    if (backInMenu == 1) {
        Menu();
    } else {
        exit(0);
    }
}

void Interface::BreadFirstSearch() {
    std::cout << "FUCK YOU 2" << std::endl;
    exit(0);
}

void Interface::DepthFirstSearch() {
    std::cout << "FUCK YOU 3" << std::endl;
    exit(0);
}

void Interface::ShortestPathTwoPeaks() {
    std::cout << "FUCK YOU 4" << std::endl;
    exit(0);
}

void Interface::ShortestPathAllPeaks() {
    std::cout << "FUCK YOU 5" << std::endl;
    exit(0);
}

void Interface::MinSpanningTree() {
    std::cout << "FUCK YOU 6" << std::endl;
    exit(0);
}

void Interface::SalesmanProblem() {
    std::cout << "FUCK YOU 7" << std::endl;
    exit(0);
}