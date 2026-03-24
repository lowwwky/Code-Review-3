#pragma once

#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "Graph.h"
#include <vector>

class TopologicalSort {
private:
    const Graph& graph;
    std::vector<int> visited; // 0 = не посещена, 1 = в процессе, 2 = обработана
    std::vector<int> result;
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    /*bool hasCycle;*/
    bool has_cycle;

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
   /* void dfs(int v);*/
    void dfs(int vertices);

public:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* TopologicalSort(const Graph& g);*/
    TopologicalSort(const Graph& searched_graph);

    bool sort();
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    /*void printResult() const;*/
    void print_result() const;
};

#endif