CC := g++
STD := -std=c++17 -g
CFLAGS := -Wall -Werror -Wextra

ifeq ($(OS), Linux)
	LIBS=-lgtest -g -lgtest_main -lpthread
	LEAKS= valgrind --leak-check=full
else
	LIBS=-lgtest
	LEAKS=CK_FORK=no leaks --atExit --
endif

all: clean build

s21_graph.a:
	$(CC) -c lib/s21_graph.cpp -o lib/s21_graph.o
	ar rcs lib/s21_graph.a lib/s21_graph.o

s21_graph_algorithms.a:
	$(CC) -c lib/s21_graph_algorithms.cpp -o lib/s21_graph_algorithms.o
	ar rcs lib/s21_graph_algorithms.a lib/s21_graph_algorithms.o

build: s21_graph.a s21_graph_algorithms.a
	$(CC) $(STD) main.cpp  -o main ./interface/interface.cpp ./lib/s21_graph.cpp ./lib/s21_graph_algorithms.cpp
	./main

tests: clean
	$(CC) $(STD) -c --coverage lib/*.cpp
	$(CC) $(STD) -c test/tests.cpp -I lib
	$(CC) $(STD) *.o -lgtest -lgcov
	./a.out

gcov_report: clean tests
	lcov -o report.info -c -d . --no-external
	genhtml -o report report.info
	open -a "Google Chrome" report/index.html

leaks: clean tests
	CK_FORK=no leaks --atExit -- ./a.out

clang:
	@cp ../materials/linters/.clang-format  ./interface/.clang-format
	@cp ../materials/linters/.clang-format  ./lib/.clang-format
	clang-format -i ./*/*.h ./*/*.cpp
	@rm -rf ./interface/.clang-format
	@rm -rf ./lib/.clang-format

check:
	cppcheck --suppress=missingIncludeSystem --suppress=negativeContainerIndex --force --std=c++17 --language=c++ ./* *.cc *.h *.cpp

clean:
	@rm -rf *.o *.a *.dSYM *.out *.gcda *.gcno *.info
	@rm -rf lib/*.o lib/*.a
	@rm -rf main
	@rm -rf ./report

.PHONY: all install uninstall clean tests gcov_report clang leaks check