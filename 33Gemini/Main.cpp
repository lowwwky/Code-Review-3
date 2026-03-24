#include <iostream>
#include "Graph.h"

// Ссылка на чат: https://gemini.google.com/app/39ac15b72027c8c4?hl=ru

int main() {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::string fileName = "graph_cycle.txt"; 
    std::string file_name = "graph_cycle.txt"; 

    try {
        // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
       /* Graph g(file_name);*/
        Graph graph(file_name);
        if (graph.topological_sort()) {
            graph.print_result();
        }
        else {
            std::cout << "No solution" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}