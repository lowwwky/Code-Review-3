#pragma once

#include <string>
#include <memory>

#pragma once
#include <string>
#include <memory>

class Node {
public:
    std::string value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*Node(const std::string& val);*/
    Node(const std::string& value);

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
  /*  bool isOperator() const;
    bool isNumber() const;
    bool isVariable() const;*/
    bool is_operator() const;
    bool is_number() const;
    bool is_variable() const;
};