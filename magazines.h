#pragma once

#include "tempedition.h"

class Magazines : public TempEdition    // Журналы
{
    std::string subject;                // Тема
public:
    Magazines();                        // Конструкторы
    Magazines(std::string name, unsigned int pages = 0, std::string subjects =  "unknown");

    std::string getSubject();           // Геттер
    void setSubject(std::string);       // Сеттер

    bool operator > (const Magazines&); // Логические операторы
    bool operator < (const Magazines&);
    bool operator== (const Magazines&);

    friend std::ofstream& operator<< (std::ofstream &out, Magazines &); // Запись
    friend std::ifstream& operator>> (std::ifstream &in , Magazines &); // и чтение из файла
};


