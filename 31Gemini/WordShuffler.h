#pragma once

#ifndef WORD_SHUFFLER_H
#define WORD_SHUFFLER_H

#include <string>
#include <vector>
#include <algorithm>
#include <random>

class WordShuffler {
public:
    // Конструктор принимает исходное слово
    explicit WordShuffler(const std::string& target);

    // Основной цикл перемешивания
    void run();

private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::string targetWord;
    //std::string currentWord;
    std::string target_word;
    std::string current_word;
    long long attempts;

    // Метод для случайной перестановки букв
    void shuffleOnce();
};

#endif