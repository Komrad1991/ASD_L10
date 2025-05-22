#pragma once
#include <vector>

#include <tuple>
#include <string>


std::vector<std::tuple<int, int, int>> primMST(const std::vector<std::vector<std::pair<int, int>>>& graph, int start);

void writeMSTDot(const std::string& filename, int n, const std::vector<std::tuple<int, int, int>>& mstEdges);

void writeGraphDot(const std::string& filename, const std::vector<std::vector<std::pair<int, int>>>& graph);