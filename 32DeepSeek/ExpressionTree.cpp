#include "ExpressionTree.h"
#include <fstream>
#include <sstream>
#include <stack>
#include <cctype>
#include <iostream>
#include <algorithm>

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//int ExpressionTree::get_priority(char op) {
int ExpressionTree::get_priority(char prioritized_operation) {
    if (prioritized_operation == '^') return 3;
    if (prioritized_operation == '*' || prioritized_operation == '/' || prioritized_operation == '%') return 2;
    if (prioritized_operation == '+' || prioritized_operation == '-') return 1;
    return 0;
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//bool ExpressionTree::is_operator(char c) {
bool ExpressionTree::is_operator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/' || character == '%' || character == '^';
}


std::vector<std::string> ExpressionTree::infix_to_postfix(const std::string& expression) {
    std::vector<std::string> output;
    std::stack<char> operators;
    std::string num;

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            num.clear();
            while (i < expression.length() && isdigit(expression[i])) {
                num += expression[i];
                i++;
            }
            i--;
            output.push_back(num);
        }
        else if (c == 'x') {
            output.push_back("x");
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        }
        else if (is_operator(c)) {
            while (!operators.empty() && operators.top() != '(' &&
                (get_priority(operators.top()) > get_priority(c) ||
                    (get_priority(operators.top()) == get_priority(c) && c != '^'))) {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

std::shared_ptr<TreeNode> ExpressionTree::build_tree(const std::vector<std::string>& postfix) {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::stack<std::shared_ptr<TreeNode>> st;
    std::stack<std::shared_ptr<TreeNode>> build_stack;

    for (const auto& token : postfix) {
        if (token == "x") {
            build_stack.push(std::make_shared<TreeNode>("x"));
        }
        else if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
            build_stack.push(std::make_shared<TreeNode>(std::stoi(token)));
        }
        else if (token.length() == 1 && is_operator(token[0])) {
            auto right = build_stack.top(); build_stack.pop();
            auto left = build_stack.top(); build_stack.pop();
            auto node = std::make_shared<TreeNode>(token[0]);
            node->set_left(left);
            node->set_right(right);
            build_stack.push(node);
        }
    }

    return build_stack.top();
}

ExpressionTree::ExpressionTree(const std::string& expression) {
    auto postfix = infix_to_postfix(expression);
    root = build_tree(postfix);
}

int ExpressionTree::evaluate(int x) {
    if (!root) return 0;
    return root->evaluate(x);
}

std::shared_ptr<TreeNode> ExpressionTree::transform_tree(std::shared_ptr<TreeNode> node, bool& transformed) {
    if (!node) return nullptr;

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //auto newNode = node->clone();
    auto new_node = node->clone();

    if (new_node->is_operator() && new_node->get_operation() == '+') {
        new_node->set_left(transform_tree(node->get_left(), transformed));
        new_node->set_right(transform_tree(node->get_right(), transformed));

        auto left = new_node->get_left();
        auto right = new_node->get_right();

        if (right && right->is_variable() && left && !left->is_variable()) {
            // Already x+A - no change needed
        }
        else if (left && left->is_variable() && right && !right->is_variable()) {
            // A+x pattern - swap to x+A
            std::cout << "Found A+x pattern, swapping to x+A" << std::endl;
            auto temp = new_node->get_left();
            new_node->set_left(new_node->get_right());
            new_node->set_right(temp);
            transformed = true;
        }
    }
    else {
        new_node->set_left(transform_tree(node->get_left(), transformed));
        new_node->set_right(transform_tree(node->get_right(), transformed));
    }

    return new_node;
}

void ExpressionTree::transform() {
    bool transformed = false;
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* auto newRoot = transform_tree(root, transformed);*/
    auto new_root = transform_tree(root, transformed);
    if (transformed) {
        root = new_root;
    }
}

void ExpressionTree::print_tree() const {
    if (!root) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    std::cout << "--- Tree Structure (Rotated 90ccw) ---" << std::endl;
    root->print_tree(0, 4);
    std::cout << std::endl << "--------------------------------------" << std::endl;
}

void ExpressionTree::print_tree_to_file(const std::string& filename, int xValue) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int result = evaluate(xValue);
    file << "Result: " << result << std::endl;
    file << std::endl;

    file << "Prefix form:" << std::endl;
    file << root->to_prefix() << std::endl;
    file << std::endl;

    file << "Postfix form:" << std::endl;
    file << root->to_postfix() << std::endl;
    file << std::endl;

    file << "Infix form with redundant parentheses:" << std::endl;
    file << root->to_infix_with_parens() << std::endl;

    file.close();
}

void ExpressionTree::print_to_console() {
    std::cout << "\nAfter transformation:" << std::endl;
    std::cout << "Prefix: " << root->to_prefix() << std::endl;
    std::cout << "Postfix: " << root->to_postfix() << std::endl;
    std::cout << "Infix: " << root->to_infix_with_parens() << std::endl;
}