#include <iostream>
#include "WordShuffler.h"

// ссылка на диалог: https://chatgpt.com/c/69bf9c91-57c8-832b-884a-1c5e91dce71d

int main() {

    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::string inputWord;
    std::string input_word;
    std::cout << "Enter any word(russian/english): ";
    std::cin >> input_word;

    word_shuffler shuffler(input_word);
    shuffler.shuffle_until_match();

    return 0;
}