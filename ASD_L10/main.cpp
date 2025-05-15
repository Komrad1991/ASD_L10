#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "graph.h"



int main()
{
    std::vector<std::vector<std::pair<int, int>>> graph(4);

    graph[0].emplace_back(1, 1);
    graph[0].emplace_back(2, 3);
    graph[1].emplace_back(0, 1);
    graph[1].emplace_back(2, 2);
    graph[2].emplace_back(0, 3);
    graph[2].emplace_back(1, 2);
    graph[2].emplace_back(3, 4);
    graph[3].emplace_back(2, 4);
    primMST(graph, 0);
}