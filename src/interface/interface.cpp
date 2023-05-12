#include "interface.h"

Interface::Interface() {};

Interface::~Interface() {};

int Interface::Intro() {
    system("clear");

    std::string text = "УВАЖАЕМЫЕ ГОСПОДА И ДАМЫ! Я ГОРД ПРЕДСТАВИТЬ ВАМ ПРОЕКТ, КОТОРЫЙ НАВСЕГДА ИЗМЕНИТ МИР И ПОВЕРНЕТ \n"
                       "ЕГО В НОВОЕ НАПРАВЛЕНИЕ. НАША КОМАНДА ТРУДИЛАСЬ ДНИ И НОЧИ, ЧТОБЫ СОЗДАТЬ НЕЧТО НЕВЕРОЯТНОЕ, \n"
                       "НЕЧТО, ЧТО СТАНЕТ СИМВОЛОМ НОВОЙ ЭРЫ В ИНДУСТРИИ. БУДУЩЕЕ НАХОДИТСЯ В НАШИХ РУКАХ, И МЫ ГОТОВЫ \n"
                       "СДЕЛАТЬ ЕГО ЯРКИМ, УДИВИТЕЛЬНЫМ И УНИКАЛЬНЫМ...... BEHOLD, BITCHES! \n";

    std::cout << "" << std::endl;

    int delay = 30;
    for (int i = 0; i < text.length(); i++) {
        std::cout << text[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;

    usleep(1000000);
    std::cout << "  ███████╗██╗███╗   ███╗██████╗ ██╗     ███████╗    ███╗   ██╗ █████╗ ██╗   ██╗██╗ ██████╗  █████╗ ████████╗ ██████╗ ██████╗    "<< std::endl;
    std::cout << "  ██╔════╝██║████╗ ████║██╔══██╗██║     ██╔════╝    ████╗  ██║██╔══██╗██║   ██║██║██╔════╝ ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗   "<< std::endl;
    std::cout << "  ███████╗██║██╔████╔██║██████╔╝██║     █████╗      ██╔██╗ ██║███████║██║   ██║██║██║  ███╗███████║   ██║   ██║   ██║██████╔╝   "<< std::endl;
    std::cout << "  ╚════██║██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝      ██║╚██╗██║██╔══██║╚██╗ ██╔╝██║██║   ██║██╔══██║   ██║   ██║   ██║██╔══██╗   "<< std::endl;
    std::cout << "  ███████║██║██║ ╚═╝ ██║██║     ███████╗███████╗    ██║ ╚████║██║  ██║ ╚████╔╝ ██║╚██████╔╝██║  ██║   ██║   ╚██████╔╝██║  ██║   "<< std::endl;
    std::cout << "  ╚══════╝╚═╝╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   "<< std::endl;
    std::cout << "" << std::endl;
    usleep(1000000);


    std::string loadStr = "ЗАГРУЗКА" ;
    for (int i = 0; i < loadStr.length(); i++) {
        std::cout << loadStr[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    for(int i = 0; i < 10; i++) {
        std::cout << "."<< std::flush;;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << " Готово!" << std::endl;

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
    std::cout << " " << std::endl;
    std::cout << "╔══════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║ ЧТОБЫ ВЕРНУТЬСЯ В МЕНЮ, НАЖМИ \"1\" ИЛИ \"0\" ДЛЯ ВЫХОДА ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════╝"  << std::endl;

    while (true) {
        std::string input;
        std::cin >> input;
        std::cin.ignore(); // Чтобы проигнорировать символ перевода строки, оставшийся в буфере ввода
        std::stringstream ss(input);
        if (ss >> backInMenu && ss.eof() && (backInMenu == 0 || backInMenu == 1)) {
            break; // Ввод корректен, можно выйти из цикла
        }
        std::cout << " " << std::endl;
        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║ WHAT THE FUCK, MAN! ПРОСТО ВЫБЕРИ \"1\" ИЛИ \"0\"   凸(￣ヘ￣)凸   ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    }
    if (backInMenu == 1) {
        system("clear");
        Menu();
    } else if (backInMenu == 0) {
        exit(0);
    }
}


void Interface::LoadFile() {
    std::cout << "FUCK YOU 1" << std::endl;

    BackToMenu();
}

void Interface::BreadFirstSearch() {
    std::cout << "FUCK YOU 2" << std::endl;
    BackToMenu();
}

void Interface::DepthFirstSearch() {
    std::cout << "FUCK YOU 3" << std::endl;
    BackToMenu();
}

void Interface::ShortestPathTwoPeaks() {
    std::cout << "FUCK YOU 4" << std::endl;
    BackToMenu();
}

void Interface::ShortestPathAllPeaks() {
    std::cout << "FUCK YOU 5" << std::endl;
    BackToMenu();
}

void Interface::MinSpanningTree() {
    std::cout << "FUCK YOU 6" << std::endl;
    BackToMenu();
}

void Interface::SalesmanProblem() {
    std::cout << "FUCK YOU 7" << std::endl;
    BackToMenu();
}