#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int vertices;  // количество вершин
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::vector<std::vector<int>> adjacencyMatrix;  // матрица смежности
    std::vector<std::vector<int>> adjacency_matrix;  // матрица смежности

public:
    // Конструктор
    Graph(int n);

    // Деструктор
    ~Graph() = default;

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //// Установка веса дуги
    //void setEdge(int from, int to, int weight);

    //// Получение веса дуги
    //int getEdge(int from, int to) const;

    //// Получение количества вершин
    //int getVerticesCount() const;

    //// Получение матрицы смежности
    //const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

    // Установка веса дуги
    void set_edge(int from, int to, int weight);

    // Получение веса дуги
    int get_edge(int from, int to) const;

    // Получение количества вершин
    int get_vertices_count() const;

    // Получение матрицы смежности
    const std::vector<std::vector<int>>& get_adjacency_matrix() const;

    // Очистка графа
    void clear();
};

#endif // GRAPH_H