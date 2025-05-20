#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "graph.h"



int main()
{
    std::vector<std::vector<std::pair<int, int>>> graph(4);

    graph[0].push_back(std::make_pair(1, 1));
    graph[0].push_back(std::make_pair(2, 3));
    graph[1].push_back(std::make_pair(0, 1));
    graph[1].push_back(std::make_pair(2, 2));
    graph[2].push_back(std::make_pair(0, 3));
    graph[2].push_back(std::make_pair(1, 2));
    graph[2].push_back(std::make_pair(3, 4));
    graph[3].push_back(std::make_pair(2, 4));
    std::cout << primMST(graph, 0);
}