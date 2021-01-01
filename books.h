#pragma once

#include "reading.h"

class Books : public Reading            // Книги
{
private:
    std::string author;                 // Автор

public:
    Books();                            // Конструкторы
    Books(std::string name, unsigned int pages,
          std::string author);

    std::string getAuth();              // Геттеры
    void setAuth(std::string);          // Сеттры

    bool operator > (const Books&);     //  Логические операторы
    bool operator < (const Books&);
    bool operator== (const Books&);

    friend std::ofstream& operator<< (std::ofstream &out, Books &); // Запись
    friend std::ifstream& operator>> (std::ifstream &in , Books &); // и чтение из файла
};

