#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int primMST(const std::vector<std::vector<std::pair<int, int>>>& graph, int start)
{
    int n = graph.size();
    std::vector<int> key(n, INT_MAX);
    std::vector<bool> inMST(n, false);
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>> pq;

    key[start] = 0;
    pq.emplace(0, start);

    int totalWeight = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int currentKey = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += currentKey;

        for (const auto& edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.emplace(key[v], v);
            }
        }
    }

    return totalWeight;
}