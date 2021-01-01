#pragma once
#include <string>
#include <fstream>
#include <QTime>

class Reading                       // Кдасс литературы - книг
{
private:
    std::string name;               // Имя
    unsigned int pages;             // Количество страниц
    unsigned int top;               // закладка

public:
    Reading();                      // Конструкторы
    Reading(std::string name, unsigned int pages);

    void setName(std::string);      // Сеттеры
    void setPages(unsigned int);
    void setTop(unsigned int);
    void setTime(QTime);

    std::string getName();          // Геттеры
    QDateTime   getTime();
    unsigned    getTop();
    int         getPages();

    bool operator > (const Reading&);// Логические операторы
    bool operator < (const Reading&);
    bool operator== (const Reading&);

    friend std::ofstream& operator<< (std::ofstream &out, Reading &); // Запись и чтение из файла
    friend std::ifstream& operator>> (std::ifstream &in , Reading &);

    template <class T>
    friend bool conditionPagesIncr(T t1, T t2);   // условия для дерева
    template <class T>
    friend bool conditionPagesDecr(T t1, T t2);
};

