#pragma once

#ifndef TOPOLOGICAL_SORTER_H
#define TOPOLOGICAL_SORTER_H

#include "Graph.h"
#include <vector>
#include <string>

class TopologicalSorter {
private:
    const Graph& graph;
    std::vector<bool> visited;
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::vector<bool> onStack;  // для обнаружения циклов
    std::vector<bool> on_stack;  // для обнаружения циклов
    std::vector<int> result;
    /*bool hasCycle;*/
    bool has_cycle;

    // Рекурсивный DFS обход
    void dfs(int vertex);

    // Проверка наличия цикла
   /* bool hasCycleDFS(int vertex);*/
    bool has_cycle_DFS(int vertex);

public:
    // Конструктор
   /* explicit TopologicalSorter(const Graph& g);*/
    explicit TopologicalSorter(const Graph& sorting_graph);

    // Деструктор
    ~TopologicalSorter() = default;

    // Выполнение топологической сортировки
    std::vector<int> sort();

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    // Проверка возможности сортировки
    /* bool isSortable() const; */
    bool is_sortable() const;

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    // Получение результата сортировки в виде строки
    /*std::string getResultString() const;*/
    std::string get_result_string() const;
};

#endif // TOPOLOGICAL_SORTER_H