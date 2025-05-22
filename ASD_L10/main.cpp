#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "graph.h"



int main()
{
    std::vector<std::vector<std::pair<int, int>>> graph(9);
    graph[0].push_back({ 1, 4 });
    graph[0].push_back({ 7, 8 });
    graph[1].push_back({ 0, 4 });
    graph[1].push_back({ 2, 8 });
    graph[1].push_back({ 7, 11 });
    graph[2].push_back({ 1, 8 });
    graph[2].push_back({ 3, 7 });
    graph[2].push_back({ 8, 2 });
    graph[2].push_back({ 5, 4 });
    graph[3].push_back({ 2, 7 });
    graph[3].push_back({ 4, 9 });
    graph[3].push_back({ 5, 14 });
    graph[4].push_back({ 3, 9 });
    graph[4].push_back({ 5, 10 });
    graph[5].push_back({ 2, 4 });
    graph[5].push_back({ 3, 14 });
    graph[5].push_back({ 4, 10 });
    graph[5].push_back({ 6, 2 });
    graph[6].push_back({ 5, 2 });
    graph[6].push_back({ 7, 1 });
    graph[6].push_back({ 8, 6 });
    graph[7].push_back({ 0, 8 });
    graph[7].push_back({ 1, 11 });
    graph[7].push_back({ 6, 1 });
    graph[7].push_back({ 8, 7 });
    graph[8].push_back({ 2, 2 });
    graph[8].push_back({ 6, 6 });
    graph[8].push_back({ 7, 7 });


    writeGraphDot("graph.dot", graph);
    auto mstEdges = primMST(graph, 0);
    writeMSTDot("mst.dot", graph.size(), mstEdges);

    system("dot -Kneato -Tpng graph.dot -o graph.png");
    system("dot -Kneato -Tpng mst.dot -o mst.png");
    system("start graph.png");
    system("start mst.png");

}