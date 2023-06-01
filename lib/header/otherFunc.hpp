#pragma once

#include <IGraph.hpp>

#include <vector>
#include <deque>
#include <functional>

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::function<void(int)> &func);
void BFS(const IGraph &graph, std::function<void(int)> func);

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::function<void(int)> &func);
void DFS(const IGraph &graph, std::function<void(int)> func);

void topologicalSort(const IGraph &graph, int vertex, std::vector<bool> &visited, std::deque<int> &sorted);

std::deque<int> topologicalSort(const IGraph &graph);