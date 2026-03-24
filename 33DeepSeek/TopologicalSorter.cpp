#include "TopologicalSorter.h"
#include <algorithm>
#include <functional>
#include <sstream>

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//TopologicalSorter::TopologicalSorter(const Graph& g)
// Конструктор класса TopologicalSorter
// Назначение: инициализирует объект для выполнения топологической сортировки графа
// Параметры:
//   sorting_grath - константная ссылка на граф, который будет отсортирован
// Инициализирует:
//   graph - сохраняет ссылку на граф для последующей обработки
//   visited - вектор флагов посещения вершин (размер = количество вершин, все false)
//   on_stack - вектор флагов нахождения вершины в текущем стеке рекурсии (все false)
//   has_cycle - флаг наличия цикла в графе (инициализируется false)
// Примечание: конструктор не выполняет сортировку, только подготавливает структуры данных.
//            Фактическая сортировка происходит при вызове метода sort()
TopologicalSorter::TopologicalSorter(const Graph& sorting_grath)
    : graph(sorting_grath),
    visited(sorting_grath.get_vertices_count(), false),
    on_stack(sorting_grath.get_vertices_count(), false),
    has_cycle(false) {
}

// Рекурсивный метод обхода в глубину (DFS) для построения топологического порядка
// Назначение: выполняет рекурсивный обход графа, добавляя вершины в результат
//            после обработки всех их потомков (пост-порядковый обход)
// Параметры:
//   vertex - индекс текущей вершины для обработки
// Алгоритм:
//   1. Отмечает вершину как посещенную и помещает в стек рекурсии
//   2. Собирает всех соседей, куда есть дуги (ненулевые веса ребер)
//   3. Сортирует соседей в порядке возрастания (детерминированный обход)
//   4. Рекурсивно обрабатывает каждого непосещенного соседа
//   5. При обнаружении ребра в вершину, находящуюся в стеке, фиксирует наличие цикла
//   6. После обработки всех соседей удаляет вершину из стека
//   7. Добавляет вершину в конец вектора результата
// Результат: result будет содержать вершины в обратном топологическом порядке
void TopologicalSorter::dfs(int vertex) {
    visited[vertex] = true;
    on_stack[vertex] = true;

    // Собираем всех соседей, куда есть дуги
    std::vector<int> neighbors;
    for (int i = 0; i < graph.get_vertices_count(); ++i) {
        if (graph.get_edge(vertex, i) != 0) {
            neighbors.push_back(i);
        }
    }

    // Сортируем соседей в порядке возрастания (для обхода в порядке возрастания)
    std::sort(neighbors.begin(), neighbors.end());

    // Обходим всех соседей
    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        else if (on_stack[neighbor]) {
            has_cycle = true;
        }
    }

    on_stack[vertex] = false;
    result.push_back(vertex);
}

// Вспомогательный метод для обнаружения цикла с помощью DFS
// Назначение: рекурсивно проверяет наличие цикла в графе, начиная с указанной вершины
// Параметры:
//   vertex - индекс текущей вершины для проверки
// Возвращает:
//   true - если цикл обнаружен в достижимой части графа
//   false - если цикл не обнаружен
// Алгоритм: аналогичен dfs(), но прерывается при первом обнаружении цикла
//           и возвращает true вместо продолжения обхода
bool TopologicalSorter::has_cycle_DFS(int vertex) {
    visited[vertex] = true;
    on_stack[vertex] = true;

    for (int i = 0; i < graph.get_vertices_count(); ++i) {
        if (graph.get_edge(vertex, i) != 0) {
            if (!visited[i]) {
                if (has_cycle_DFS(i)) {
                    return true;
                }
            }
            else if (on_stack[i]) {
                return true;
            }
        }
    }

    on_stack[vertex] = false;
    return false;
}


// Основной метод выполнения топологической сортировки
// Назначение: выполняет полный алгоритм топологической сортировки:
//            1. Проверяет наличие цикла в графе
//            2. Если цикла нет, строит топологический порядок вершин
// Возвращает:
//   std::vector<int> - вектор вершин в топологическом порядке (индексы от 0)
//                     если граф содержит цикл, возвращает пустой вектор
// Алгоритм:
//   Фаза 1 - Проверка цикла:
//     - Сбрасывает флаги visited и on_stack
//     - Запускает has_cycle_DFS() для каждой непосещенной вершины
//     - При обнаружении цикла устанавливает has_cycle = true и прекращает проверку
//   Фаза 2 - Построение порядка (если цикла нет):
//     - Сбрасывает флаги visited и on_stack
//     - Очищает result
//     - Обходит вершины в обратном порядке (от n-1 до 0) для детерминированности
//     - Для каждой непосещенной вершины запускает dfs()
//     - Разворачивает результат (так как dfs добавляет вершины в обратном порядке)
//   Возвращает топологический порядок или пустой вектор при наличии цикла
std::vector<int> TopologicalSorter::sort() {
    // Сначала проверяем наличие цикла
    std::fill(visited.begin(), visited.end(), false);
    std::fill(on_stack.begin(), on_stack.end(), false);
    has_cycle = false;

    for (int i = 0; i < graph.get_vertices_count(); ++i) {
        if (!visited[i]) {
            if (has_cycle_DFS(i)) {
                has_cycle = true;
                break;
            }
        }
    }

    if (has_cycle) {
        return std::vector<int>();
    }

    // Если цикла нет, выполняем топологическую сортировку
    std::fill(visited.begin(), visited.end(), false);
    std::fill(on_stack.begin(), on_stack.end(), false);
    result.clear();

    // Обходим вершины в порядке возрастания номеров
    // чтобы при наличии нескольких равноправных вершин,
    // они обрабатывались в правильном порядке
    for (int i = graph.get_vertices_count() - 1; i >= 0; --i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Результат получен в обратном порядке
    std::reverse(result.begin(), result.end());

    return result;
}

// Метод проверки возможности топологической сортировки
// Назначение: возвращает информацию о том, является ли граф ациклическим
// Возвращает:
//   true - граф не содержит циклов, топологическая сортировка возможна
//   false - граф содержит циклы, топологическая сортировка невозможна
// Примечание: требует предварительного вызова sort() для установки флага has_cycle
bool TopologicalSorter::is_sortable() const {
    return !has_cycle;
}

// Метод получения результата в строковом формате
// Назначение: преобразует результат топологической сортировки в строку
//            для удобного вывода или логирования
// Возвращает:
//   std::string - строковое представление топологического порядка:
//                 - При успешной сортировке: номера вершин через пробел (с нумерацией с 1)
//                 - При наличии цикла: "No solution"
// Формат вывода: "1 2 3 4" (вершины разделены пробелами)
// Примечание: номера вершин в выводе увеличиваются на 1 (result[i] + 1),
//            так как в задаче нумерация вершин, вероятно, начинается с 1
std::string TopologicalSorter::get_result_string() const {
    if (has_cycle || result.empty()) {
        return "No solution";
    }

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::stringstream ss;*/
    std::stringstream streamed_string;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) {
            streamed_string << " ";
        }
        // Номера вершин в задаче, вероятно, с 1
        streamed_string << (result[i] + 1);
    }

    return streamed_string.str();
}