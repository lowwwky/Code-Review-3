#pragma once

#ifndef TREE_MANAGER_H
#define TREE_MANAGER_H

#include "ExpressionNode.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream> 

class TreeManager {
private:
    ExpressionNode* root;
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //int getPriority(char op);
    //bool isOperator(char c);
    //long long power(int base, int exp);
    //// Вспомогательная функция для красивого вывода
    //void printTreeRecursive(ExpressionNode* node, int level, std::ostream& out);

    int get_priority(char op);
    bool is_operator(char c);
    long long power(int base, int exp);

    // Вспомогательная функция для красивого вывода
    void print_tree_recursive(ExpressionNode* node, int level, std::ostream& out);

public:
    TreeManager();
    ~TreeManager();

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //void buildFromInfix(const std::string& infix);
    //int evaluate(ExpressionNode* node, int xValue);
    //void transform(ExpressionNode* node); // Исправленная сигнатура
    //void printPrefix(ExpressionNode* node, std::ostream& out);
    //void printPostfix(ExpressionNode* node, std::ostream& out);
    //void printInfixRedundant(ExpressionNode* node, std::ostream& out);
    // Новая функция для вывода дерева на экран (или в файл)
    /*void printTreeVisual(ExpressionNode* node, std::ostream& out);*/

    void build_from_infix(const std::string& infix);
    int evaluate(ExpressionNode* node, int xValue);
    void transform(ExpressionNode* node); // Исправленная сигнатура

    void print_prefix(ExpressionNode* node, std::ostream& out);
    void print_postfix(ExpressionNode* node, std::ostream& out);
    void print_infix_redundant(ExpressionNode* node, std::ostream& out);

    // Новая функция для вывода дерева на экран (или в файл)
    void print_tree_visual(ExpressionNode* node, std::ostream& out);

  /*  ExpressionNode* getRoot() { return root; }*/

    ExpressionNode* get_root() { return root; }
};

#endif
