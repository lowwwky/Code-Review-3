#include <iostream>
#include <fstream>
#include "TreeManager.h"

// Ссылка на чат: https://gemini.google.com/app/bf16dee2ddbd0a5c?hl=ru

int main() {
    std::ifstream in("FN1.txt");
    std::ofstream out("FN2.txt");

    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string expression;
    if (!std::getline(in, expression) || expression.empty()) {
        std::cerr << "Input file is empty or invalid." << std::endl;
        return 1;
    }

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    int x_value;
    std::cout << "Expression read: " << expression << std::endl;
    std::cout << "Enter integer value for x: ";
    if (!(std::cin >> x_value)) {
        std::cerr << "Invalid input for x." << std::endl;
        return 1;
    }

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*TreeManager tm;*/
    TreeManager tree_manager;
    tree_manager.build_from_infix(expression);

    // ВЫВОД ДЕРЕВА НА ЭКРАН (До трансформации)
    std::cout << "\nInitial Tree:" << std::endl;
    tree_manager.print_tree_visual(tree_manager.get_root(), std::cout);

    // 1. Вычисляем и записываем результат в файл
    int result = tree_manager.evaluate(tree_manager.get_root(), x_value);
    out << result << std::endl;
    std::cout << "Evaluation result (x = " << x_value << " ): " << result << std::endl;

    // 2. Трансформируем дерево
    tree_manager.transform(tree_manager.get_root());

    // ВЫВОД ДЕРЕВА НА ЭКРАН (После трансформации)
    std::cout << "\nTransformed Tree (A+x -> x+A):" << std::endl;
    tree_manager.print_tree_visual(tree_manager.get_root(), std::cout);

    // 3. Выводим формы в файл FN2
    tree_manager.print_prefix(tree_manager.get_root(), out); out << "\n";
    tree_manager.print_postfix(tree_manager.get_root(), out); out << "\n";
    tree_manager.print_infix_redundant(tree_manager.get_root(), out); out << "\n";

    std::cout << "\nResults written to FN2." << std::endl;

    return 0;
}