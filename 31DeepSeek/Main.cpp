#include "WordShuffler.h"
#include <iostream>
#include <string>

// ссылка на чат: https://chat.deepseek.com/a/chat/s/2af12412-9675-4c48-9256-c642b8572458

int main() {
    std::string word;

    std::cout << "Enter any word(russian/english): ";
    std::cin >> word;

    // Проверка на пустую строку
    if (word.empty()) {
        std::cout << "Word can not be empty!" << std::endl;
        return 1;
    }

    // Создаем объект для перемешивания
    word_shuffler shuffler(word);

    // Запускаем процесс перестановок
    int attempts = shuffler.run_shuffling();

    // Выводим количество попыток
    std::cout << attempts << " attempts" << std::endl;

    return 0;
}