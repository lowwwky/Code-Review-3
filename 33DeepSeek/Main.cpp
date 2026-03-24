#include "Graph.h"
#include "TopologicalSorter.h"
#include "FileReader.h"
#include <iostream>
#include <string>

// Ссылка на чат: https://chat.deepseek.com/a/chat/s/22678e6b-ef22-4417-9b9d-80f317949794

int main() {
    setlocale(LC_ALL, "Russian.utf8");

    std::string file_name;
    std::cout << "Введите имя файла(например: result.txt): ";
    std::cin >> file_name;

    try {
        // Чтение графа из файла
        FileReader reader(file_name);
        Graph graph = reader.read_graph();

        // Вывод матрицы смежности для проверки
        std::cout << "\nМатрица смежности:" << std::endl;
        const auto& matrix = graph.get_adjacency_matrix();
        for (int i = 0; i < graph.get_vertices_count(); ++i) {
            for (int j = 0; j < graph.get_vertices_count(); ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Топологическая сортировка
        TopologicalSorter sorter(graph);
        std::vector<int> result = sorter.sort();

        // Вывод результата
        std::cout << "\nРезультат топологической сортировки:" << std::endl;
        std::cout << sorter.get_result_string() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}