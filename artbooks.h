#pragma once

#include "books.h"

class ARTBooks : public Books       // Художественные книги
{
private:
    std::string genre;              // Жанр
public:
    ARTBooks();                     // Конструкторы
    ARTBooks(std::string name, unsigned int pages = 0,
          std::string author =  "unknown", std::string genre =  "unknown");

    std::string getGenre();         // Геттер
    void setGenre(std::string);     // Сеттер

    bool operator > (const ARTBooks&);// Логичесие операторы
    bool operator < (const ARTBooks&);
    bool operator== (const ARTBooks&);

    friend std::ofstream& operator<< (std::ofstream &out, ARTBooks &);  // Запись
    friend std::ifstream& operator>> (std::ifstream &in , ARTBooks &);  // и чтение из файла
};

