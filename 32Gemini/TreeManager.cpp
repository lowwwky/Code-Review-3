#include "TreeManager.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip> // Для setw

// Конструктор класса TreeManager
// Назначение: инициализирует объект, устанавливая корень дерева в nullptr
// Создает пустой объект для последующего построения дерева выражения
TreeManager::TreeManager() : root(nullptr) {}

// Деструктор класса TreeManager
// Назначение: освобождает всю выделенную память, удаляя дерево выражений
// Вызывает delete root, который рекурсивно удаляет все узлы дерева
TreeManager::~TreeManager() { delete root; }

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//int TreeManager::get_priority(char op) {
// Метод определения приоритета оператора
// Назначение: возвращает числовой приоритет математической операции
// Параметры:
//   operated - символ оператора (+, -, *, /, %, ^)
// Возвращает:
//   1 - для операторов сложения и вычитания (наименьший приоритет)
//   2 - для операторов умножения, деления и взятия остатка
//   3 - для оператора возведения в степень (наивысший приоритет)
//   0 - если передан не оператор
// Используется при построении дерева для правильной расстановки скобок
int TreeManager::get_priority(char operated) {
    if (operated == '+' || operated == '-') return 1;
    if (operated == '*' || operated == '/' || operated == '%') return 2;
    if (operated == '^') return 3;
    return 0;
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//bool TreeManager::is_operator(char c) {
// Метод проверки, является ли символ оператором
// Назначение: определяет, относится ли переданный символ к математическим операторам
// Параметры:
//   character - проверяемый символ
// Возвращает:
//   true - если символ является оператором (+, -, *, /, %, ^)
//   false - в противном случае
bool TreeManager::is_operator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '%' || character == '^');
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//long long TreeManager::power(int base, int exp) {
// Метод возведения в степень (целочисленное)
// Назначение: вычисляет base^expression для целых неотрицательных показателей
// Параметры:
//   base - основание степени
//   expression - показатель степени (неотрицательное целое число)
// Возвращает: результат возведения в степень (long long для предотвращения переполнения)
// Примечание: реализован через последовательное умножение, O(n) сложность
long long TreeManager::power(int base, int expression) {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //long long res = 1;
    long long result = 1;
    for (int i = 0; i < expression; i++) {
        result *= base;
    }
    return result;
}

// Метод построения дерева выражения из инфиксной строки
// Назначение: парсит математическое выражение в инфиксной записи и строит
//            бинарное дерево, представляющее порядок операций
// Алгоритм: использует алгоритм сортировочной станции (Shunting Yard)
// Параметры:
//   infix - строка с математическим выражением (может содержать цифры, x, +, -, *, /, %, ^, скобки)
// Процесс:
//   1. Обход строки слева направо
//   2. При обнаружении числа - создает узел-число
//   3. При обнаружении 'x' - создает узел-переменную
//   4. При обнаружении '(' - помещает в стек операторов
//   5. При обнаружении ')' - выталкивает операторы до '('
//   6. При обнаружении оператора - выталкивает операторы с бОльшим или равным приоритетом
//   7. По окончании - выталкивает все оставшиеся операторы
// Результат: корень дерева сохраняется в поле root
void TreeManager::build_from_infix(const std::string& infix) {
    std::stack<ExpressionNode*> nodes;
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
   /* std::stack<char> ops;*/
    std::stack<char> operators;

    for (int i = 0; i < infix.length(); i++) {
        if (isspace(infix[i])) continue;

        if (isdigit(infix[i])) {
            int value = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                value = value * 10 + (infix[i++] - '0');
            }
            i--;
            // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
           /* nodes.push(new ExpressionNode(val));*/
            nodes.push(new ExpressionNode(value));
        }
        else if (infix[i] == 'x') {
            nodes.push(new ExpressionNode(NodeType::VARIABLE, "x"));
        }
        else if (infix[i] == '(') {
            operators.push('(');
        }
        else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
               /* char op = operators.top(); operators.pop();*/
                char temporary_operator = operators.top(); operators.pop();
               /* ExpressionNode* r = nodes.top(); nodes.pop();
                ExpressionNode* l = nodes.top(); nodes.pop();*/
                ExpressionNode* right_node = nodes.top(); nodes.pop();
                ExpressionNode* left_node = nodes.top(); nodes.pop();
                ExpressionNode* newNode = new ExpressionNode(NodeType::OPERATOR, std::string(1, temporary_operator));
                newNode->left = left_node; newNode->right = right_node;
                nodes.push(newNode);
            }
            if (!operators.empty()) operators.pop(); // Pop '('
        }
        else if (is_operator(infix[i])) {
            while (!operators.empty() && operators.top() != '(' && get_priority(operators.top()) >= get_priority(infix[i])) {
                // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
                /* char op = operators.top(); operators.pop();*/
                char temporary_operator = operators.top(); operators.pop();
               /* ExpressionNode* r = nodes.top(); nodes.pop();
                ExpressionNode* l = nodes.top(); nodes.pop();*/
                ExpressionNode* right_node = nodes.top(); nodes.pop();
                ExpressionNode* left_node = nodes.top(); nodes.pop();
                ExpressionNode* newNode = new ExpressionNode(NodeType::OPERATOR, std::string(1, temporary_operator));
                newNode->left = left_node; newNode->right = right_node;
                nodes.push(newNode);
            }
            operators.push(infix[i]);
        }
    }
    while (!operators.empty()) {
        // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
       /* char op = operators.top(); operators.pop();*/
        char temporary_operator = operators.top(); operators.pop();
       /* ExpressionNode* r = nodes.top(); nodes.pop();
        ExpressionNode* l = nodes.top(); nodes.pop();*/
        ExpressionNode* right_node = nodes.top(); nodes.pop();
        ExpressionNode* left_node = nodes.top(); nodes.pop();
        ExpressionNode* newNode = new ExpressionNode(NodeType::OPERATOR, std::string(1, temporary_operator));
        newNode->left = left_node; newNode->right = right_node;
        nodes.push(newNode);
    }
    if (!nodes.empty()) root = nodes.top();
}

// Метод преобразования дерева (оптимизация)
// Назначение: выполняет пост-порядковый обход дерева и применяет
//            оптимизирующие преобразования
// Текущее преобразование: меняет местами левого и правого потомка у оператора '+',
//                         если справа переменная, а слева - не переменная
//                         (для унификации представления)
// Параметры:
//   node - корень поддерева для преобразования
void TreeManager::transform(ExpressionNode* node) {
    if (!node) return;
    transform(node->left);
    transform(node->right);
    if (node->type == NodeType::OPERATOR && node->value == "+") {
        if (node->right && node->right->type == NodeType::VARIABLE &&
            node->left && node->left->type != NodeType::VARIABLE) {
            std::swap(node->left, node->right);
        }
    }
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//int TreeManager::evaluate(ExpressionNode* node, int xVal) {
// Метод вычисления значения выражения
// Назначение: вычисляет значение дерева выражения при заданном значении переменной x
// Параметры:
//   node - корень дерева (или поддерева) для вычисления
//   x_value - значение переменной x
// Возвращает: результат вычисления выражения
// Алгоритм:
//   1. Для узла-числа возвращает его значение
//   2. Для узла-переменной возвращает x_value
//   3. Для узла-оператора рекурсивно вычисляет левое и правое поддеревья,
//      затем применяет оператор
// Обработка ошибок: при делении на ноль возвращает 0
int TreeManager::evaluate(ExpressionNode* node, int x_value) {
    if (!node) return 0;
    if (node->type == NodeType::NUMBER) return node->number_value;
    if (node->type == NodeType::VARIABLE) return x_value;
   /* int l = evaluate(node->left, x_value);
    int r = evaluate(node->right, x_value);*/
    int left_node = evaluate(node->left, x_value);
    int right_node = evaluate(node->right, x_value);
    if (node->value == "+") return left_node + right_node;
    if (node->value == "-") return left_node - right_node;
    if (node->value == "*") return left_node * right_node;
    if (node->value == "/") return (right_node == 0) ? 0 : left_node / right_node;
    if (node->value == "%") return (right_node == 0) ? 0 : left_node % right_node;
    if (node->value == "^") return (int)power(left_node, right_node);
    return 0;
}

// --- Функции печати ---

// Печать в префиксной форме (польская запись)
// Назначение: выводит выражение в формате: оператор левый_операнд правый_операнд
// Пример: + * 2 x 3  (для 2*x+3)
void TreeManager::print_prefix(ExpressionNode* node, std::ostream& out) {
    if (!node) return;
    out << node->value << " ";
    print_prefix(node->left, out);
    print_prefix(node->right, out);
}

// Печать в постфиксной форме (обратная польская запись)
// Назначение: выводит выражение в формате: левый_операнд правый_операнд оператор
// Пример: 2 x * 3 +  (для 2*x+3)
void TreeManager::print_postfix(ExpressionNode* node, std::ostream& out) {
    if (!node) return;
    print_postfix(node->left, out);
    print_postfix(node->right, out);
    out << node->value << " ";
}

// Печать в инфиксной форме с избыточными скобками
// Назначение: выводит выражение в обычной инфиксной записи, но с полными скобками
// Пример: ((2*x)+3)  (для 2*x+3)
void TreeManager::print_infix_redundant(ExpressionNode* node, std::ostream& out) {
    if (!node) return;
    if (node->type == NodeType::OPERATOR) out << "(";
    print_infix_redundant(node->left, out);
    out << node->value;
    print_infix_redundant(node->right, out);
    if (node->type == NodeType::OPERATOR) out << ")";
}

// --- НОВЫЕ МЕТОДЫ ВИЗУАЛИЗАЦИИ ---

// Печать дерева в визуальном виде
// Назначение: выводит структуру дерева в виде иерархии с отступами
// Параметры:
//   node - корень дерева
//   out - поток вывода
void TreeManager::print_tree_visual(ExpressionNode* node, std::ostream& out) {
    out << "--- Tree Structure ---\n";
    print_tree_recursive(node, 0, out);
    out << "--------------------------------------\n";
}

// Рекурсивная печать дерева с отступами (повернутое на 90° дерево)
// Назначение: визуализирует структуру дерева, где корень слева,
//            правое поддерево выводится выше левого
// Параметры:
//   node - текущий узел
//   level - уровень вложенности (определяет отступ)
//   out - поток вывода
// Алгоритм: сначала печатает правое поддерево (сверху),
//           затем текущий узел, затем левое поддерево (снизу)
void TreeManager::print_tree_recursive(ExpressionNode* node, int level, std::ostream& out) {
    if (!node) return;

    // Сначала печатаем ПРАВОЕ поддерево (оно будет сверху)
    print_tree_recursive(node->right, level + 1, out);

    // Печатаем текущий узел с отступом
    if (level > 0) {
        out << std::setw(level * 4) << " "; // Отступ
    }

    // Выводим значение и, если это оператор, показываем связь
    if (node->type == NodeType::OPERATOR) {
        out << "[" << node->value << "]" << "\n";
    }
    else {
        out << node->value << "\n";
    }

    // Потом печатаем ЛЕВОЕ поддерево (оно будет снизу)
    print_tree_recursive(node->left, level + 1, out);
}