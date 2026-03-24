#pragma once

#ifndef EXPRESSION_NODE_H
#define EXPRESSION_NODE_H

#include <string>

enum class NodeType { OPERATOR, NUMBER, VARIABLE };

struct ExpressionNode {
    NodeType type;
    std::string value;
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    int number_value;
    ExpressionNode* left, * right;

    ExpressionNode(NodeType type, std::string value);
    ExpressionNode(int val);
    ~ExpressionNode();
};

#endif