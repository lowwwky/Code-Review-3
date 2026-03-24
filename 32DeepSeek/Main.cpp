#include "ExpressionTree.h"
#include <iostream>
#include <fstream>
#include <string>

// Ссылка на чат: https://chat.deepseek.com/a/chat/s/4ff2e682-fa7b-4077-9a92-7d97aba4b918

int main() {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::string inputFile = "FN1.txt";
    std::string outputFile = "FN2.txt";*/
    //int xValue;
    int x_value;
    std::string input_file = "FN1.txt";
    std::string output_file = "FN2.txt";

    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Error opening input file: " << input_file << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(file, expression);
    file.close();

    std::cout << "Expression: " << expression << std::endl;
    std::cout << std::endl;

    ExpressionTree tree(expression);

    std::cout << "Initial Tree:" << std::endl;
    tree.print_tree();

    std::cout << "Enter value for x: ";
    std::cin >> x_value;

    int result = tree.evaluate(x_value);
    std::cout << "Evaluation result (x=" << x_value << "): " << result << std::endl;
    std::cout << std::endl;

    std::cout << "Transformed Tree (A+x -> x+A):" << std::endl;
    tree.transform();
    tree.print_tree();

    tree.print_to_console();

    tree.print_tree_to_file(output_file, x_value);

    std::cout << "\nResults written to " << output_file << std::endl;

    return 0;
}