#include "WordShuffler.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

// Конструктор класса word_shuffler
// Инициализирует объект начальным словом, устанавливает текущее слово
// равным исходному и обнуляет счетчик попыток
// Параметр: word - исходное слово для перемешивания
word_shuffler::word_shuffler(const std::string& word)
    : original_word(word), current_word(word), attempt_count(0) {
}

// Статический метод для перемешивания символов в слове
// Создает случайную перестановку символов переданной строки
// Параметр: word - строка для перемешивания
// Возвращает: новую строку с перемешанными символами
// Если длина слова <= 1, возвращает исходное слово без изменений
std::string word_shuffler::shuffle_word(const std::string& word) {
    if (word.length() <= 1) {
        return word;
    }

    // Создаем копию слова для перемешивания
    std::string shuffled = word;

    // Инициализируем генератор случайных чисел
    static std::mt19937 generator(
        std::chrono::system_clock::now().time_since_epoch().count()
    );

    // Перемешиваем символы
    std::shuffle(shuffled.begin(), shuffled.end(), generator);

    return shuffled;
}

// Основной метод, выполняющий процесс перемешивания
// Многократно перемешивает текущее слово до тех пор, пока
// случайно не получит исходное слово
// Возвращает: количество попыток, потребовавшихся для получения исходного слова
// Выводит на экран каждое полученное в процессе перемешивания слово
int word_shuffler::run_shuffling() {
    attempt_count = 0;
    current_word = original_word;

    // Если слово состоит из одной буквы, перемешивание не требуется
    if (original_word.length() <= 1) {
        std::cout << "The word consists of one digit, no reshuffles needed." << std::endl;
        return 0;
    }

    while (true) {
        // Перемешиваем текущее слово
        // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
        //std::string newWord = shuffle_word(current_word);
        std::string new_word = shuffle_word(current_word);

        // Выводим полученное слово
        std::cout << new_word << std::endl;
        attempt_count++;

        // Проверяем, совпадает ли с исходным
        if (new_word == original_word) {
            break;
        }

        current_word = new_word;
    }

    return attempt_count;
}

// Геттер для получения текущего (последнего перемешанного) слова
// Возвращает: текущее состояние слова в виде строки
// Используется для доступа к результату последнего перемешивания
std::string word_shuffler::get_current_word() const {
    return current_word;
}

// Геттер для получения количества попыток перемешивания
// Возвращает: количество выполненных перемешиваний
// Используется для получения статистики о процессе перемешивания
int word_shuffler::get_attempt_count() const {
    return attempt_count;
}