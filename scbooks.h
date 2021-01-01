#pragma once

#include "books.h"

class SCBooks : public Books        // Научные книги
{
private:
    std::string section;            // Раздел науки
public:
    SCBooks();                      // Конструкторы
    SCBooks(std::string name, unsigned int pages = 0,
            std::string author =  "unknown", std::string section =  "unknown");

    std::string getSection();       // Геттер
    void setSection(std::string);   // Сеттер

    bool operator > (const SCBooks&);   // Логический оператор
    bool operator < (const SCBooks&);
    bool operator== (const SCBooks&);

    friend std::ofstream& operator<< (std::ofstream &out, SCBooks &); // Запись
    friend std::ifstream& operator>> (std::ifstream &in , SCBooks &); // и  чтение из файла
};


