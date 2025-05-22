#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
#include <fstream>

#include <cstdlib> 

std::vector<std::tuple<int, int, int>> primMST(const std::vector<std::vector<std::pair<int, int>>>& graph, int start)
{
    int n = graph.size();
    std::vector<int> key(n, INT_MAX);
    std::vector<int> parent(n, -1);
    std::vector<bool> inMST(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    key[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto& edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({ key[v], v });
            }
        }
    }

    std::vector<std::tuple<int, int, int>> mstEdges;
    for (int v = 0; v < n; ++v)
    {
        if (parent[v] != -1)
        {
            mstEdges.emplace_back(parent[v], v, key[v]);
        }
    }
    return mstEdges;
}

void writeGraphDot(const std::string& filename,const std::vector<std::vector<std::pair<int, int>>>& graph)
{
    std::ofstream ofs(filename);
    ofs << "graph G {\n";
    int n = graph.size();
    for (int u = 0; u < n; ++u)
    {
        for (auto& edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (u < v)
            {
                ofs << "    " << u << " -- " << v << " [label=" << w << "];\n";
            }
        }
    }
    ofs << "}\n";
    ofs.close();
}

void writeMSTDot(const std::string& filename, int n,const std::vector<std::tuple<int, int, int>>& mstEdges)
{
    std::ofstream ofs(filename);
    ofs << "graph MST {\n";
    for (int i = 0; i < n; ++i)
    {
        ofs << "    " << i << ";\n";
    }
    for (auto& e : mstEdges)
    {
        int u, v, w;
        std::tie(u, v, w) = e;
        ofs << "    " << u << " -- " << v << " [label=" << w << ", color=red, penwidth=2.0];\n";
    }
    ofs << "}\n";
    ofs.close();
}