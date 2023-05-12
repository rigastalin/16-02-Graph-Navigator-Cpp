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

s21_graph_algorithms.a:


build:
	$(CC) $(STD) main.cc interface/interface.cpp -o main
	./main

test:

leaks:
	CK_FORK=no leaks --atExit -- ./test/tests

clang:
	@cp ../materials/linters/.clang-format  ./interface/.clang-format
	@cp ../materials/linters/.clang-format  ./lib/.clang-format
	clang-format -i ./*/*.h ./*/*.cpp
	@rm -rf ./interface/.clang-format
	@rm -rf ./lib/.clang-format

check:
	cppcheck --suppress=missingIncludeSystem --std=c++17 --language=c++ ./* *.cc *.h *.cpp

clean:
	@rm -rf *.o *.a *.dSYM .out
	@rm -rf main

.PHONY: all install uninstall clean tests gcov_report clang leaks check