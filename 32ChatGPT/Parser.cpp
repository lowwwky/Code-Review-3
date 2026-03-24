#include "Parser.h"
#include <stack>
#include <cctype>


// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//int Parser::priority(const std::string& op) {
// Метод определения приоритета оператора
// Назначение: возвращает числовой приоритет математической операции для использования
//            в алгоритме сортировочной станции (Shunting Yard Algorithm)
// Параметры:
//   operators - строка с оператором (+, -, *, /, %, ^)
// Возвращает:
//   1 - для операторов сложения и вычитания (наименьший приоритет)
//   2 - для операторов умножения, деления и взятия остатка
//   3 - для оператора возведения в степень (наивысший приоритет, правоассоциативный)
//   0 - если передан не оператор
// Используется при преобразовании инфиксной записи в постфиксную для правильной
// расстановки порядка операций
int Parser::priority(const std::string& operators) {
    if (operators == "+" || operators == "-") return 1;
    if (operators == "*" || operators == "/" || operators == "%") return 2;
    if (operators == "^") return 3;
    return 0;
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//std::vector<std::string> Parser::to_postfix(const std::string& expr) {
// Метод преобразования инфиксного выражения в постфиксную (обратную польскую) запись
// Назначение: преобразует математическое выражение в стандартной инфиксной нотации
//            в постфиксную форму, удобную для последующего построения дерева разбора
// Алгоритм: использует алгоритм сортировочной станции (Edsger Dijkstra, 1961)
// Параметры:
//   expression - строка с математическим выражением в инфиксной форме
//                Поддерживает: цифры (многозначные числа), переменную 'x',
//                операторы (+, -, *, /, %, ^) и скобки
// Возвращает:
//   вектор строк, где каждый элемент - токен (число, переменная или оператор)
//   в порядке постфиксной записи
// Алгоритм работы:
//   1. Инициализирует выходной вектор и стек операторов
//   2. Обходит выражение слева направо:
//      - Числа и 'x' сразу добавляются в выходной вектор
//      - '(' помещается в стек операторов
//      - ')' выталкивает операторы из стека в выходной вектор до '('
//      - Операторы выталкивают из стека операторы с бОльшим или равным приоритетом,
//        затем текущий оператор помещается в стек
//   3. После обработки всего выражения выталкивает оставшиеся операторы из стека
std::vector<std::string> Parser::to_postfix(const std::string& expression) {
    std::vector<std::string> output;
    /*std::stack<std::string> ops;*/
    std::stack<std::string> operators;

    for (size_t i = 0; i < expression.size();) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
           /* std::string num;*/
            std::string number_value;
            while (i < expression.size() && isdigit(expression[i])) {
                number_value += expression[i++];
            }
            output.push_back(number_value);
        }
        else if (expression[i] == 'x') {
            output.push_back("x");
            i++;
        }
        else {
            std::string op(1, expression[i]);

            if (op == "(") {
                operators.push(op);
            }
            else if (op == ")") {
                while (!operators.empty() && operators.top() != "(") {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.pop();
            }
            else {
                while (!operators.empty() && priority(operators.top()) >= priority(op)) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.push(op);
            }
            i++;
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//std::shared_ptr<Node> Parser::parse(const std::string& expr) {
// Метод построения абстрактного синтаксического дерева (AST) из инфиксного выражения
// Назначение: принимает математическое выражение в инфиксной форме и строит
//            бинарное дерево разбора, представляющее структуру выражения
// Параметры:
//   expression - строка с математическим выражением (поддерживает числа, x, операторы, скобки)
// Возвращает:
//   shared_ptr<Node> - умный указатель на корень построенного дерева
// Алгоритм работы:
//   1. Преобразует инфиксное выражение в постфиксную запись с помощью to_postfix()
//   2. Использует стек для построения дерева:
//      - Для чисел и переменной 'x' создает листовые узлы и помещает в стек
//      - Для операторов извлекает два верхних узла из стека (правый и левый операнды),
//        создает узел-оператор, связывает с ними и помещает в стек
//   3. Корень дерева остается единственным элементом в стеке
// Преимущество подхода: постфиксная запись позволяет строить дерево за один проход
//                      без необходимости учитывать приоритеты операций
std::shared_ptr<Node> Parser::parse(const std::string& expression) {
    auto postfix = to_postfix(expression);
    /*std::stack<std::shared_ptr<Node>> st;*/
    std::stack<std::shared_ptr<Node>> parsed_stack;

    for (auto& token : postfix) {
        if (isdigit(token[0]) || token == "x") {
            parsed_stack.push(std::make_shared<Node>(token));
        }
        else {
            auto right = parsed_stack.top(); parsed_stack.pop();
            auto left = parsed_stack.top(); parsed_stack.pop();
            auto node = std::make_shared<Node>(token);
            node->left = left;
            node->right = right;
            parsed_stack.push(node);
        }
    }

    return parsed_stack.top();
}