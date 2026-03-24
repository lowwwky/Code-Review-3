#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <memory>
#include <vector>

enum class NodeType {
    OPERATOR,
    NUMBER,
    VARIABLE
};

class TreeNode {
private:
    NodeType type;
    char operation;
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

public:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*TreeNode(char op);
    TreeNode(int val);
    TreeNode(const std::string& var);*/
    TreeNode(char operation);
    TreeNode(int value);
    TreeNode(const std::string& var);

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    /*NodeType getType() const;
    char getOperation() const;
    int getValue() const;

    std::shared_ptr<TreeNode> getLeft() const;
    std::shared_ptr<TreeNode> getRight() const;
    void setLeft(std::shared_ptr<TreeNode> node);
    void setRight(std::shared_ptr<TreeNode> node);

    bool isVariable() const;
    bool isNumber() const;
    bool is_operator() const;

    int evaluate(int x) const;
    std::string toPrefix() const;
    std::string toPostfix() const;
    std::string toInfixWithParens() const;*/

    NodeType get_type() const;
    char get_operation() const;
    int get_value() const;

    std::shared_ptr<TreeNode> get_left() const;
    std::shared_ptr<TreeNode> get_right() const;
    void set_left(std::shared_ptr<TreeNode> node);
    void set_right(std::shared_ptr<TreeNode> node);

    bool is_variable() const;
    bool is_number() const;
    bool is_operator() const;

    int evaluate(int x_value) const;
    std::string to_prefix() const;
    std::string to_postfix() const;
    std::string to_infix_with_parens() const;

    std::shared_ptr<TreeNode> clone() const;

    void print_tree(int space, int indent) const;
};

#endif