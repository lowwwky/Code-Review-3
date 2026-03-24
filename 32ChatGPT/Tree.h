#pragma once

#include "Node.h"
#include <memory>
#include <fstream>

class Tree {
public:
    std::shared_ptr<Node> root;

    int evaluate(std::shared_ptr<Node> node, int x);

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    /*void printTree(std::shared_ptr<Node> node, int space = 0);
    void toPrefix(std::shared_ptr<Node> node, std::ofstream& out);
    void toPostfix(std::shared_ptr<Node> node, std::ofstream& out);
    void toInfix(std::shared_ptr<Node> node, std::ofstream& out);*/

    void print_tree(std::shared_ptr<Node> node, int space = 0);
    void to_prefix(std::shared_ptr<Node> node, std::ofstream& out);
    void to_postfix(std::shared_ptr<Node> node, std::ofstream& out);
    void to_infix(std::shared_ptr<Node> node, std::ofstream& out);

    void transform(std::shared_ptr<Node> node);
};