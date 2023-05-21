#include <gtest/gtest.h>

#include "../lib/s21_graph.h"
#include "../lib/s21_graph_algorithms.h"

TEST(dfs, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("dataset/graph1.txt");

    std::vector<int> result = graphAlgorithms.DepthFirstSearch(graph, 0);
    std::vector<int> answer;
    answer.push_back(0);
    answer.push_back(1);
    answer.push_back(2);
    answer.push_back(3);
    answer.push_back(4);
    answer.push_back(5);
    answer.push_back(6);
    answer.push_back(7);
    answer.push_back(8);
    answer.push_back(9);
    answer.push_back(10);

    for (int i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i], answer[i]);
    }
}

TEST(bfs, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("dataset/graph1.txt");

    std::vector<int> result = graphAlgorithms.BreadthFirstSearch(graph, 0);
    std::vector<int> answer;
    answer.push_back(0);
    answer.push_back(1);
    answer.push_back(2);
    answer.push_back(3);
    answer.push_back(4);
    answer.push_back(5);
    answer.push_back(6);
    answer.push_back(7);
    answer.push_back(8);
    answer.push_back(9);
    answer.push_back(10);

    for (int i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i], answer[i]);
    }
}

TEST(BetweenTwoVertices, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("dataset/graph1.txt");

    int result = graphAlgorithms.GetShortestPathBetweenVertices(graph, 0, 1);
    int answer = 29;

    ASSERT_EQ(result, answer);
}

TEST(BetweenAllVertices, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("test/test_data/notOriented.txt");

    std::vector<std::vector<int> > result = graphAlgorithms.GetShortestPathsBetweenAllVertices(graph);
    std::vector<std::vector<int> > answer;
    answer.push_back({2, 1, 1, 2, 2});
    answer.push_back({1, 2, 1, 1, 2});
    answer.push_back({1, 1, 2, 2, 1});
    answer.push_back({2, 1, 2, 2, 1});
    answer.push_back({2, 2, 1, 1, 2});

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result.size(); ++j) {
            ASSERT_EQ(result[i][j], answer[i][j]);
        }
    }
}

TEST(SpanningTree, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("dataset/graph1.txt");

    std::vector<std::vector<int> > result = graphAlgorithms.GetLeastSpanningTree(graph);
    std::vector<std::vector<int> > answer;
    answer.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    answer.push_back({0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    answer.push_back({0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0});
    answer.push_back({0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0});
    answer.push_back({0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0});
    answer.push_back({0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0});
    answer.push_back({0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0});
    answer.push_back({0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0});
    answer.push_back({0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0});
    answer.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0});
    answer.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13});

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result.size(); ++j) {
            ASSERT_EQ(result[i][j], answer[i][j]);
        }
    }
}

TEST(STSP, test1) {
    s21::Graph graph;
    s21::GraphAlgorithms graphAlgorithms;
    graph.loadGraphFromFile("dataset/graph1.txt");
    s21::TsmResult result = graphAlgorithms.SolveTravelingSalesmanProblem(graph);
    graph.exportGraphToDot("test/test_data/export.txt");
    ASSERT_EQ(result.distance, 253);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}