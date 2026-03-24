#pragma once

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "TreeNode.h"
#include <string>
#include <memory>
#include <vector>

class ExpressionTree {
private:
    std::shared_ptr<TreeNode> root;

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.

    //int getPriority(char op);
    //bool isOperator(char c);
    //std::vector<std::string> infixToPostfix(const std::string& expression);
    //std::shared_ptr<TreeNode> buildTree(const std::vector<std::string>& postfix);
    //std::shared_ptr<TreeNode> transformTree(std::shared_ptr<TreeNode> node, bool& transformed);

    int get_priority(char operated);
    bool is_operator(char character);
    std::vector<std::string> infix_to_postfix(const std::string& expression);
    std::shared_ptr<TreeNode> build_tree(const std::vector<std::string>& postfix);
    std::shared_ptr<TreeNode> transform_tree(std::shared_ptr<TreeNode> node, bool& transformed);

public:
    ExpressionTree(const std::string& expression);

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*int evaluate(int x);*/
    int evaluate(int x_value);
    void transform();

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
   /* void printTree() const;
    void printTreeToFile(const std::string& filename, int xValue);
    void printToConsole();

    std::shared_ptr<TreeNode> getRoot() const { return root; }*/

    void print_tree() const;
    void print_tree_to_file(const std::string& file_name, int x_value);
    void print_to_console();

    std::shared_ptr<TreeNode> get_root() const { return root; }
};

#endif