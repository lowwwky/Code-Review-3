#include <iostream>
#include <fstream>
#include "Parser.h"
#include "Tree.h"

// Ссылка на чат: https://chatgpt.com/c/69c28708-0230-832e-a437-c301b26c1761

int main() {
    std::ifstream in("FN1.txt");
    std::ofstream out("FN2.txt");

    // FIX_ME: Отсутсвует проверка на пустой файл и открытие файла.
    if (!in.is_open() || !out.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string expression;
    if (!std::getline(in, expression) || expression.empty()) {
        std::cerr << "Input file is empty or invalid." << std::endl;
        return 1;
    }

    Parser parser;
    Tree tree;

    tree.root = parser.parse(expression);

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //int x;
    int x_value;
    std::cout << "Enter x value: ";
    std::cin >> x_value;

    std::cout << "\nInitial Tree:\n";
    std::cout << "--- Tree Structure ---\n";
    tree.print_tree(tree.root);

    int result = tree.evaluate(tree.root, x_value);
    std::cout << "\nEvaluation result (x=" << x_value << "): " << result << "\n";

    out << "Result: " << result << "\n";

    tree.transform(tree.root);

    std::cout << "\nTransformed Tree (A+x -> x+A):\n";
    std::cout << "--- Tree Structure ---\n";
    tree.print_tree(tree.root);

    out << "\nPrefix:\n";
    tree.to_prefix(tree.root, out);

    out << "\nPostfix:\n";
    tree.to_postfix(tree.root, out);

    out << "\nInfix:\n";
    tree.to_infix(tree.root, out);

    std::cout << "\nDone. Results written to FN2.\n";
}