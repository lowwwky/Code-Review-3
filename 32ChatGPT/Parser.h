#pragma once

#pragma once
#include "Node.h"
#include <string>
#include <vector>

class Parser {
public:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::shared_ptr<Node> parse(const std::string& expr);*/
    std::shared_ptr<Node> parse(const std::string& expression);

private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* std::vector<std::string> to_postfix(const std::string& expr);
    int priority(const std::string& op);*/
    std::vector<std::string> to_postfix(const std::string& expression);
    int priority(const std::string& operated);
};