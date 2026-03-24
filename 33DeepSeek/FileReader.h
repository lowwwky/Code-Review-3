#pragma once

#ifndef FILE_READER_H
#define FILE_READER_H

#include "Graph.h"
#include <string>

class FileReader {
private:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    /*std::string filename;*/
    std::string file_name;

public:
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // Конструктор
    /*explicit FileReader(const std::string& fileName);*/
    explicit FileReader(const std::string& file_name);

    // Деструктор
    ~FileReader() = default;

    // Чтение графа из файла
    /*Graph readGraph();*/
    Graph read_graph();

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    // Установка имени файла
   /* void setFilename(const std::string& fileName);*/
    void set_file_name(const std::string& file_name);

    // FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores.
    // Получение имени файла
    /*std::string getFilename() const;*/
    std::string get_file_name() const;
};

#endif // FILE_READER_H