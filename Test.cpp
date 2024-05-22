//207275215
//amitgini0369@gmail.com 
#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;

TEST_CASE("Test graph operator + graph")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 + g2;
    CHECK(expectedGraph == g3);
}

TEST_CASE("Test graph operator - graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 - g2;
    CHECK(expectedGraph == g3);
}

TEST_CASE("Test graph operator += graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    g1 += g2;
    CHECK(expectedGraph == g1);

}
TEST_CASE("Test print graph to ostream"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    std::cout<<"Test print graph to ostream"<<std::endl;
    CHECK_NOTHROW(std::cout<<g1<<std::endl);
}

TEST_CASE("Test print graph to ostream with operator"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    std::cout<<"Test print graph to ostream with operator"<<std::endl;
    CHECK_NOTHROW(std::cout<<++g1<<std::endl); //add 1 to all edges
    CHECK_NOTHROW(std::cout<<g1--<<std::endl); //sub 1 from all edges but wont be seein in the next print
    CHECK_NOTHROW(std::cout<<g1<<std::endl); //now the edges are back to the original
}

TEST_CASE("Test graph operator * ")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedMatrix = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph expected;
    expected.loadGraph(expectedMatrix);
    CHECK(g3 == expected);
}

TEST_CASE("Test graph operator *= ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *= g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph expected;
    expected.loadGraph(expectedGraph);
    CHECK(g1==expected);
}
TEST_CASE("Test graph operator >"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g2>g1);
}

TEST_CASE("Test graph operator >"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g2>g1);
    
}
TEST_CASE("Test graph operator <="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<=g2);
}

TEST_CASE("Test graph operator <"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<g2);
}


TEST_CASE("Test graph operator ++ postfix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1++ != g2);
    CHECK(g1 == g2);

}

TEST_CASE("Test graph operator ++ prefix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(++g1 == g2);
}

TEST_CASE("Test graph operator --prefix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(g1 == --g2);
}

TEST_CASE("Test graph operator --postfix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2--);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph operator !="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(g1++ != g2);
}

TEST_CASE("Test graph operator =="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    ariel::Graph g3;
    vector<vector<int>> matrix3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(matrix3);
    CHECK(g3 == g1);
    CHECK(++g1 == g2);
    ++g1;
    CHECK(--g1 == g2);
}

