#include "filestream.h"


template <class T>
BFile<T>::BFile(std::string str, long int mode) :           // Конструктор
name (str)
{
    fin.open(name, std::ios::binary | std::ios::openmode(mode));
}
template <class T>
BFile<T>::~BFile()                                          // Деструктор
{
    if(fin.is_open()) fin.close();
    if(fout.is_open()) fout.close();
}
template <class T>
void BFile<T>::write(T& t)                                   // Запись
{
    if( fin.is_open()) fin.close();
    if(!fout.is_open())fout.open(name, std::ios::binary | std::ios::trunc);
    fout << t;
    fout << '\n';
}
template <class T>
void BFile<T>::read(T& t)                                   // Чтение
{
    if(fout.is_open()) fout.close();
    if(!fin.is_open()) fin.open(name, std::ios::binary | std::ifstream::app);
    fin >> t;
}
template <class T>
bool BFile<T>::end()                                        // Проверка на конец
{
    return (fin.is_open()) ? fin.eof() : false;
}
template <class T>
bool BFile<T>::isOpened()                                   // Проверка на окрытие
{
    return fin.is_open() || fout.is_open();
}
