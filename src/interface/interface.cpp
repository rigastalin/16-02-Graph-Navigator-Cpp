#include "interface.h"

Interface::Interface() {}

Interface::~Interface() {}

int Interface::Intro() {
  system("clear");

  std::string text =
      "УВАЖАЕМЫЕ ГОСПОДА И ДАМЫ! Я ГОРД ПРЕДСТАВИТЬ ВАМ ПРОЕКТ, КОТОРЫЙ "
      "НАВСЕГДА ИЗМЕНИТ МИР И ПОВЕРНЕТ \n"
      "ЕГО В НОВОЕ НАПРАВЛЕНИЕ. НАША КОМАНДА ТРУДИЛАСЬ ДНИ И НОЧИ, ЧТОБЫ "
      "СОЗДАТЬ НЕЧТО НЕВЕРОЯТНОЕ, \n"
      "НЕЧТО, ЧТО СТАНЕТ СИМВОЛОМ НОВОЙ ЭРЫ В ИНДУСТРИИ. БУДУЩЕЕ НАХОДИТСЯ В "
      "НАШИХ РУКАХ, И МЫ ГОТОВЫ \n"
      "СДЕЛАТЬ ЕГО ЯРКИМ, УДИВИТЕЛЬНЫМ И УНИКАЛЬНЫМ...... BEHOLD, BITCHES! \n";

  std::cout << "" << std::endl;

  int delay = 30;
  for (std::size_t i = 0; i < text.length(); i++) {
    std::cout << text[i] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }
  std::cout << std::endl;

  usleep(1000000);
  std::cout
      << "  ███████╗██╗███╗   ███╗██████╗ ██╗     ███████╗    ███╗   ██╗ "
         "█████╗ ██╗   ██╗██╗ ██████╗  █████╗ ████████╗ ██████╗ ██████╗    "
      << std::endl;
  std::cout
      << "  ██╔════╝██║████╗ ████║██╔══██╗██║     ██╔════╝    ████╗  "
         "██║██╔══██╗██║   ██║██║██╔════╝ ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗   "
      << std::endl;
  std::cout
      << "  ███████╗██║██╔████╔██║██████╔╝██║     █████╗      ██╔██╗ "
         "██║███████║██║   ██║██║██║  ███╗███████║   ██║   ██║   ██║██████╔╝   "
      << std::endl;
  std::cout << "  ╚════██║██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝      "
               "██║╚██╗██║██╔══██║╚██╗ ██╔╝██║██║   ██║██╔══██║   ██║   ██║   "
               "██║██╔══██╗   "
            << std::endl;
  std::cout
      << "  ███████║██║██║ ╚═╝ ██║██║     ███████╗███████╗    ██║ ╚████║██║  "
         "██║ ╚████╔╝ ██║╚██████╔╝██║  ██║   ██║   ╚██████╔╝██║  ██║   "
      << std::endl;
  std::cout
      << "  ╚══════╝╚═╝╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝    ╚═╝  ╚═══╝╚═╝  "
         "╚═╝  ╚═══╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   "
      << std::endl;
  std::cout << "" << std::endl;
  usleep(1000000);

  std::string loadStr = "ЗАГРУЗКА";
  for (std::size_t i = 0; i < loadStr.length(); i++) {
    std::cout << loadStr[i] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }

  for (int i = 0; i < 10; i++) {
    std::cout << "." << std::flush;
    ;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  std::cout << " Готово!" << std::endl;
  std::cout << "" << std::endl;
  return 0;
}

int Interface::ShowMenu() {
  std::cout
      << ""
         "╔════════════════════════════════════════════════════════════════╗\n"
         "║                                                                ║\n"
         "║                            МЕНЮ                                ║\n"
         "║                      SIMPLE NAVIGATOR                          ║\n"
         "╠════════════════════════════════════════════════════════════════╣\n"
         "║ 1. ЗАГРУЗКА ИСХОДНОГО ГРАФА ИЗ ФАЙЛА                           ║\n"
         "║ 2. ОБХОД ГРАФА В ШИРИНУ                                        ║\n"
         "║ 3. ОБХОД ГРАФА В ГЛУБИНУ                                       ║\n"
         "║ 4. ПОИСК КРАТЧАЙШЕГО ПУТИ МЕЖДУ ПРОИЗВОЛЬНЫМИ ДВУМЯ ВЕРШИНАМИ  ║\n"
         "║ 5. ПОИСК КРАТЧАЙШИХ ПУТЕЙ МЕЖДУ ВСЕМИ ПАРАМИ ВЕРШИН В ГРАФЕ    ║\n"
         "║ 6. ПОИСК МИНИМАЛЬНОГО ОСТОВНОГО ДЕРЕВА В ГРАФЕ                 ║\n"
         "║ 7. РЕШЕНИЕ ЗАДАЧИ КОММИВОЯЖЕРА                                 ║\n"
         "║                                                                ║\n"
         "║                                                                ║\n"
         "║ 0. Выход                                                       ║\n"
         "╚═══════════════════CFLOSSIE & GCONN & TORELL════════════════════╝\n"
      << std::endl;

  return 0;
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

void Interface::BackToMenu() {
  std::cout << std::endl;
  std::cout
      << "╔════════════════════════════════════════════════════════════════╗\n"
      << "║  ЧТОБЫ ВЕРНУТЬСЯ В МЕНЮ, НАЖМИ \"1\" ИЛИ \"0\" ДЛЯ ВЫХОДА          "
         "║\n"
      << "╚════════════════════════════════════════════════════════════════╝\n";

  while (true) {
    std::string input;
    std::cin >> input;
    std::cin.ignore();  // Чтобы проигнорировать символ перевода строки,
                        // оставшийся в буфере ввода
    std::stringstream ss(input);
    if (ss >> backInMenu && ss.eof() && (backInMenu == 0 || backInMenu == 1)) {
      break;
    }
    std::cout << " " << std::endl;
    std::cout
        << "╔════════════════════════════════════════════════════════════════╗"
        << std::endl;
    std::cout << "║ WHAT THE FUCK, MAN! ПРОСТО ВЫБЕРИ \"1\" ИЛИ \"0\"   "
                 "凸(￣ヘ￣)凸   ║"
              << std::endl;
    std::cout
        << "╚════════════════════════════════════════════════════════════════╝"
        << std::endl;
  }
  if (backInMenu == 1) {
    system("clear");
    Menu();
  } else if (backInMenu == 0) {
    exit(0);
  }
}

void Interface::printDelayed(const std::string& text, int delay) {
  for (char c : text) {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }
}

void Interface::LoadFile() {
  system("clear");
  graph_.loadGraphFromFile(
      "/opt/goinfre/cflossie/A2_SimpleNavigator_v1.0-0/src/dataset/graph1.txt");
  int delay = 30;
  std::string textLoading = "\nLOADING SUCCESSFULLY COMPLETE!";
  printDelayed(textLoading, delay);
  std::cout << std::endl;
  BackToMenu();
}

bool Interface::CheckGraph() { return graph_.empty(); }

void Interface::BreadFirstSearch() {
  system("clear");
  int startVertex = 0;
  if (!CheckGraph()) {
    std::vector<int> dfsResult =
        graphAlgorithms_.DepthFirstSearch(graph_, startVertex);
    std::cout << std::endl;
    std::string text = "DEPTH-FIRST SEARCH: \n";
    printDelayed(text, 30);
    for (auto vertex : dfsResult) {
      std::string str = std::to_string(vertex + 1);
      printDelayed(str, 50);
      std::cout << " ";
    }
    std::cout << std::endl;
    BackToMenu();
  } else {
    BackToMenu();
  }
}

void Interface::DepthFirstSearch() {
  system("clear");
  int startVertex = 0;
  if (!CheckGraph()) {
    std::vector<int> bfsResult =
        graphAlgorithms_.DepthFirstSearch(graph_, startVertex);

    std::cout << std::endl;
    std::string text = "BREADTH-FIRST SEARCH: \n";
    printDelayed(text, 30);
    for (auto vertex : bfsResult) {
      std::string str = std::to_string(vertex + 1);
      printDelayed(str, 50);
      std::cout << " ";
    }
    std::cout << std::endl;
    BackToMenu();
  } else {
    BackToMenu();
  }
}

void Interface::ShortestPathTwoPeaks() {
  system("clear");
  int vertex1, vertex2;
  if (!CheckGraph()) {
    std::cout << std::endl;
    std::string inputStr = "ENTER TWO VETICES: \n";
    printDelayed(inputStr, 30);
    std::cin >> vertex1 >> vertex2;
    int gspbvRes = graphAlgorithms_.GetShortestPathBetweenVertices(
        graph_, vertex1, vertex2);

    std::cout << std::endl;
    std::string text1 = "WEIGHT: " + std::to_string(gspbvRes) + "\n";
    printDelayed(text1, 30);
    BackToMenu();
  } else {
    BackToMenu();
  }
}

void Interface::ShortestPathAllPeaks() {
  system("clear");
  if (!CheckGraph()) {
    auto res = graphAlgorithms_.GetShortestPathsBetweenAllVertices(graph_);

    std::cout << std::endl;
    std::string text = "SHORTEST PATHS BETWEEN ALL VERTICES: \n";
    printDelayed(text, 30);
    for (int i = 0; i < graph_.getNumVertices(); i++) {
      for (int j = 0; j < graph_.getNumVertices(); j++) {
        std::string resIJ = std::to_string(res[i][j]);
        std::cout << std::setw(4) << std::left << resIJ << " ";
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
      }
      std::cout << std::endl;
    }
    BackToMenu();
  } else {
    BackToMenu();
  }
}

void Interface::MinSpanningTree() {
  system("clear");
  if (!CheckGraph()) {
    std::vector<std::vector<int> > mst =
        graphAlgorithms_.GetLeastSpanningTree(graph_);
    int sum = 0;

    std::cout << std::endl;
    std::string text = "THE ADJACENCY MATRIX FOR A MINIMUM SPANNING TREE: \n";
    printDelayed(text, 30);
    for (const auto& row : mst) {
      for (int weight : row) {
        std::string weightStr = std::to_string(weight);
        std::cout << std::setw(3) << std::left << weightStr << " ";
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        std::cout << "  ";
        sum += weight;
      }
      std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "MINIMAL WEIGHT: " << sum << std::endl;
    BackToMenu();
  } else {
    BackToMenu();
  }
}

void Interface::SalesmanProblem() {
  system("clear");
  if (!CheckGraph()) {
    s21::TsmResult result;
    result = graphAlgorithms_.SolveTravelingSalesmanProblem(graph_);

    std::cout << std::endl;
    std::string text = "VERTICES: ";
    printDelayed(text, 30);
    std::cout << "";
    for (int vertex = 0; vertex < result.vertices.size() - 1; vertex++) {
      std::string vertexStr = std::to_string(result.vertices[vertex] + 1);
      printDelayed(vertexStr, 50);
      std::cout << " ";
    }
    std::cout << std::endl;
    std::string text1 =
        "DISTANCE: " + std::to_string(static_cast<int>(result.distance)) + "\n";
    printDelayed(text1, 30);
    BackToMenu();
  } else {
    BackToMenu();
  }
}