#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.

    //int n;
    //std::vector<std::vector<int>> adjMatrix;
    //std::vector<int> visited; // 0 - white, 1 - gray, 2 - black
    //std::vector<int> result;
    //bool hasCycle;

    //void dfs(int v);

    int amount_of_vertices;
    std::vector<std::vector<int>> adj_matrix;
    std::vector<int> visited; // 0 - white, 1 - gray, 2 - black
    std::vector<int> result;
    bool has_cycle;

    void dfs(int vertices);

public:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    /*Graph(const std::string& fileName);
    bool topologicalSort();
    void printResult() const;*/
    Graph(const std::string& file_name);
    bool topological_sort();
    void print_result() const;

};

#endif