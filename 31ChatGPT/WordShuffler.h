#pragma once

#ifndef WORDSHUFFLER_H
#define WORDSHUFFLER_H

#include <string>

class word_shuffler {
private:
    //// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    //std::string originalWord;
    //int shuffleCount;
    std::string original_word;
    int shuffle_count;

public:
    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    //WordShuffler(const std::string& word);
    // void shuffleUntilMatch();
    word_shuffler(const std::string& word);
    void shuffle_until_match();
};

#endif