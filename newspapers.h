#pragma once
#include "tempedition.h"

class Newspapers : public TempEdition   // Газета
{
private:
    std::string location;               // Местоположение
public:
    Newspapers();                       // КОнструктор
    Newspapers(std::string name, unsigned int pages = 0, std::string location =  "unknown");

    std::string getLocation();          // Геттер
    void setLocation(std::string);      // Сеттер

    bool operator > (const Newspapers&);// Логические операторы
    bool operator < (const Newspapers&);
    bool operator== (const Newspapers&);

    friend std::ofstream& operator<< (std::ofstream &out, Newspapers &); // Запись
    friend std::ifstream& operator>> (std::ifstream &in , Newspapers &); // и чтение из файла
};
