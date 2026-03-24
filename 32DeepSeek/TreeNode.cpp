#include "TreeNode.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

TreeNode::TreeNode(char op) : type(NodeType::OPERATOR), operation(op), value(0) {}

TreeNode::TreeNode(int val) : type(NodeType::NUMBER), operation('\0'), value(val) {}

TreeNode::TreeNode(const std::string& var) : type(NodeType::VARIABLE), operation('\0'), value(0) {}

NodeType TreeNode::get_type() const { return type; }
char TreeNode::get_operation() const { return operation; }
int TreeNode::get_value() const { return value; }

std::shared_ptr<TreeNode> TreeNode::get_left() const { return left; }
std::shared_ptr<TreeNode> TreeNode::get_right() const { return right; }

void TreeNode::set_left(std::shared_ptr<TreeNode> node) { left = node; }
void TreeNode::set_right(std::shared_ptr<TreeNode> node) { right = node; }

bool TreeNode::is_variable() const { return type == NodeType::VARIABLE; }
bool TreeNode::is_number() const { return type == NodeType::NUMBER; }
bool TreeNode::is_operator() const { return type == NodeType::OPERATOR; }

int TreeNode::evaluate(int x) const {
    if (type == NodeType::NUMBER) {
        return value;
    }
    else if (type == NodeType::VARIABLE) {
        return x;
    }
    else if (type == NodeType::OPERATOR) {
        // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
        /*int leftVal = left->evaluate(x);
        int rightVal = right->evaluate(x);*/
        int left_value = left->evaluate(x);
        int right_value = right->evaluate(x);


        switch (operation) {
        case '+': return left_value + right_value;
        case '-': return left_value - right_value;
        case '*': return left_value * right_value;
        case '/':
            if (right_value == 0) throw std::runtime_error("Division by zero");
            return left_value / right_value;
        case '%':
            if (right_value == 0) throw std::runtime_error("Modulo by zero");
            return left_value % right_value;
        case '^':
            return static_cast<int>(std::pow(left_value, right_value));
        default: throw std::runtime_error("Unknown operator");
        }
    }
    throw std::runtime_error("Unknown node type");
}

std::string TreeNode::to_prefix() const {
    if (type == NodeType::NUMBER) {
        return std::to_string(value);
    }
    else if (type == NodeType::VARIABLE) {
        return "x";
    }
    else {
        return std::string(1, operation) + " " + left->to_prefix() + " " + right->to_prefix();
    }
}

std::string TreeNode::to_postfix() const {
    if (type == NodeType::NUMBER) {
        return std::to_string(value);
    }
    else if (type == NodeType::VARIABLE) {
        return "x";
    }
    else {
        return left->to_postfix() + " " + right->to_postfix() + " " + std::string(1, operation);
    }
}

std::string TreeNode::to_infix_with_parens() const {
    if (type == NodeType::NUMBER) {
        return std::to_string(value);
    }
    else if (type == NodeType::VARIABLE) {
        return "x";
    }
    else {
        return "(" + left->to_infix_with_parens() + " " + operation + " " + right->to_infix_with_parens() + ")";
    }
}

std::shared_ptr<TreeNode> TreeNode::clone() const {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::shared_ptr<TreeNode> newNode;*/
    std::shared_ptr<TreeNode> new_node;

    if (type == NodeType::NUMBER) {
        new_node = std::make_shared<TreeNode>(value);
    }
    else if (type == NodeType::VARIABLE) {
        new_node = std::make_shared<TreeNode>("x");
    }
    else {
        new_node = std::make_shared<TreeNode>(operation);
        new_node->set_left(left->clone());
        new_node->set_right(right->clone());
    }

    return new_node;
}

void TreeNode::print_tree(int space, int indent) const {
    if (!this) return;

    space += indent;

    if (right) {
        right->print_tree(space, indent);
    }

    std::cout << std::endl;
    for (int i = indent; i < space; i++) {
        std::cout << " ";
    }

    if (type == NodeType::NUMBER) {
        std::cout << value;
    }
    else if (type == NodeType::VARIABLE) {
        std::cout << "x";
    }
    else if (type == NodeType::OPERATOR) {
        std::cout << "[" << operation << "]";
    }

    if (left) {
        left->print_tree(space, indent);
    }
}