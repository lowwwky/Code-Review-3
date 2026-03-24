#include <iostream>
#include <string>
#include "WordShuffler.h"

// ссылка на чат: https://gemini.google.com/app/2c9204e37dd58795?hl=ru

int main() {
    // Установка кодировки для корректного отображения кириллицы (для Windows)
    //setlocale(LC_ALL, "Russian");

    std::string input;
    std::cout << "Enter any word(russian/english): ";
    std::cin >> input;

    WordShuffler shuffler(input);
    shuffler.run();

    return 0;
}