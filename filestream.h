#pragma once 

#include <iostream>
#include <fstream>
#include <string>
//#include "excep.h"

template <class T>
class BFile
{
private:
    std::string name;       // Имя файла
    std::ifstream fin;      // Поток ввода
    std::ofstream fout;     // Поток вывода

public:
    BFile(std::string, long int mode = std::ios::in | std::ios::out | std::ios::app);     // открыть поток
   ~BFile();               // закрыть поток

    void write(T&);      // запись
    void read (T&);     // чтение
    bool isOpened();   // проверка на открытие
    bool end();       // проверка на конец
    
};


#include "filestream.inl"
