#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* int n;
    std::vector<std::vector<int>> adjMatrix;*/
    int amount_of_vertices;
    std::vector<std::vector<int>> adj_matrix;

public:
    Graph();

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* bool loadFromFile(const std::string& filename);*/
    /*int getSize() const;*/
    /*const std::vector<std::vector<int>>& getMatrix() const;*/

    bool load_from_file(const std::string& file_name);
    int get_size() const;  
    const std::vector<std::vector<int>>& get_matrix() const;

};

#endif