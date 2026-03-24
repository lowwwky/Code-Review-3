#pragma once

#ifndef WORDSHUFFLER_H
#define WORDSHUFFLER_H

#include <string>

class word_shuffler {
private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::string originalWord;
    std::string currentWord;
    int attemptCount;*/
    std::string original_word;
    std::string current_word;
    int attempt_count;

    /**
     * Перемешивает буквы в слове случайным образом
     * @param word Исходное слово для перемешивания
     * @return Перемешанное слово
     */
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //std::string shuffleWord(const std::string& word);
    std::string shuffle_word(const std::string& word);

public:
    /**
     * Конструктор класса
     * @param word Исходное слово
     */
     // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //explicit WordShuffler(const std::string& word);
    explicit word_shuffler(const std::string& word);

    /**
     * Запускает процесс перестановок до совпадения с исходным словом
     * Возвращает количество попыток
     */
     // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //int runShuffling();
    int run_shuffling();

    /**
     * Получить текущее слово
     */
     // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //std::string getCurrentWord() const;
    std::string get_current_word() const;

    /**
     * Получить количество попыток
     */
     // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //int getAttemptCount() const;
    int get_attempt_count() const;
};

#endif // WORDSHUFFLER_H