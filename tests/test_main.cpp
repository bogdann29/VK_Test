#include <gtest/gtest.h>
#include <sstream>
#include "../src/helper.h"

TEST(DijkstraTest, BasicGraph_1) {
    std::vector<std::vector<size_t>> graph = {
        {1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}
    };
    size_t vertices = 4, source = 0;
    auto distances = dijkstra(graph, vertices, source);

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 1);
    EXPECT_EQ(distances[3], 2);
}

TEST(DijkstraTest, BasicGraph_2) {
    std::vector<std::vector<size_t>> graph = {
        {1, 4}, {0, 2, 3}, {1}, {1}, {0}
    };
    size_t vertices = 5, source = 4;
    auto distances = dijkstra(graph, vertices, source);

    EXPECT_EQ(distances[0], 1);
    EXPECT_EQ(distances[1], 2);
    EXPECT_EQ(distances[2], 3);
    EXPECT_EQ(distances[3], 3);
    EXPECT_EQ(distances[4], 0);
}

TEST(DijkstraTest, EmptyGraph) {
    std::vector<std::vector<size_t>> graph;
    size_t vertices = 0, source = 0;
    auto distances = dijkstra(graph, vertices, source);

    EXPECT_TRUE(distances.empty());
}

TEST(DijkstraTest, OneVertexGraph) {
    std::vector<std::vector<size_t>> graph(1);
    size_t vertices = 1, source = 0;
    auto distances = dijkstra(graph, vertices, source);

    EXPECT_EQ(distances[0], 0);
}


TEST(ReadFileTest, BasicGraph) {
    std::istringstream s("5\n4\n0 1\n0 4\n1 2\n1 3\n4\n");
    size_t vertices, edges;
    std::vector<std::vector<size_t>> graph;
    auto source = read_file(s, graph, vertices, edges);

    std::vector<std::vector<size_t>> expected{{1, 4}, {0, 2, 3}, {1}, {1}, {0}};

    EXPECT_EQ(graph, expected);
    EXPECT_EQ(source, 4);
    EXPECT_EQ(vertices, 5);
    EXPECT_EQ(edges, 4);
}

TEST(ReadFileTest, MissingData) {
    std::istringstream input("5\n3\n0 1\n0 4\n1 2\n");
    size_t vertices, edges;
    std::vector<std::vector<size_t>> graph;

    EXPECT_THROW(read_file(input, graph, vertices, edges), std::runtime_error);
}

TEST(ReadFileTest, InvalidVertexIndex) {
    std::istringstream input("3\n2\n0 1\n0 5\n2\n");
    size_t vertices, edges;
    std::vector<std::vector<size_t>> graph;

    EXPECT_THROW(read_file(input, graph, vertices, edges), std::runtime_error);
}

TEST(ReadFileTest, SingleVertexNoEdges) {
    std::istringstream input("1\n0\n0\n");  
    size_t vertices, edges;
    std::vector<std::vector<size_t>> graph;
    auto source = read_file(input, graph, vertices, edges);

    std::vector<std::vector<size_t>> expected(1);

    EXPECT_EQ(graph, expected);
    EXPECT_EQ(source, 0);
    EXPECT_EQ(vertices, 1);
    EXPECT_EQ(edges, 0);
}

TEST(ReadFileTest, ExtraData) {
    std::istringstream input("3\n2\n0 1\n1 2\n0\nEXTRA DATA\n");
    size_t vertices, edges;
    std::vector<std::vector<size_t>> graph;
    auto source = read_file(input, graph, vertices, edges);

    std::vector<std::vector<size_t>> expected{{1}, {0, 2}, {1}};

    EXPECT_EQ(graph, expected);
    EXPECT_EQ(source, 0);
    EXPECT_EQ(vertices, 3);
    EXPECT_EQ(edges, 2);
}