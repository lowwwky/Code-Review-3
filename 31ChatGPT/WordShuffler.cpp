#include "WordShuffler.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//WordShuffler::WordShuffler(const std::string& word)
//    : originalWord(word), shuffleCount(0) {
//}
// Конструктор класса word_shuffler
// Инициализирует объект начальным словом и обнуляет счетчик перемешиваний
// Параметр: word - исходное слово, которое будет использоваться для процесса перемешивания
// Назначение: создает экземпляр класса с заданным словом, готовый к выполнению операций перемешиван
word_shuffler::word_shuffler(const std::string& word)
    : original_word(word), shuffle_count(0) {

}

// Основной метод, выполняющий процесс перемешивания до совпадения с исходным словом
// Назначение: многократно перемешивает символы исходного слова до тех пор, пока
// случайным образом не получит исходное слово. В процессе выводит каждое полученное
// слово на экран и по завершении выводит общее количество попыток.
// Алгоритм работы:
// 1. Создает копию исходного слова для работы
// 2. Преобразует строку в вектор символов для удобства перемешивания
// 3. Инициализирует генератор случайных чисел
// 4. В цикле do-while:
//    - Перемешивает символы в векторе
//    - Формирует новую строку из перемешанных символов
//    - Увеличивает счетчик попыток
//    - Выводит полученное слово
//    - Продолжает, пока текущее слово не совпадет с исходным
// 5. Выводит итоговое количество попыток
void word_shuffler::shuffle_until_match() {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::string currentWord = originalWord;
    std::string current_word = original_word;
    std::vector<char> letters(current_word.begin(), current_word.end());

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    do {
        std::shuffle(letters.begin(), letters.end(), rng);
        current_word = std::string(letters.begin(), letters.end());
        shuffle_count++;
        std::cout << current_word << std::endl;
    } while (current_word != original_word);

    std::cout << shuffle_count << " attempts" << std::endl; // латиница
}