#include "Graph.h"
#include "TopologicalSort.h"
#include <iostream>

// Ссылка на чат: https://chatgpt.com/c/69c28307-d51c-832b-b309-0ba2dd4208b5

int main() {
    Graph graph;

    if (!graph.load_from_file("input.txt")) {
        return 1;
    }

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*TopologicalSort topo(graph);*/
    TopologicalSort topological_sort(graph);

    if (!topological_sort.sort()) {
        std::cout << "No solution\n";
    }
    else {
        topological_sort.print_result();
    }

    return 0;
}