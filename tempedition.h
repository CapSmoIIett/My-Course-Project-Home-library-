#pragma once
#include "reading.h"

class TempEdition : public Reading      // Перодическеие издания
{
private:
    QDateTime date_of_issue;            // Дата издания
public:
    TempEdition();                      // Конструкторы
    TempEdition(std::string name, unsigned int pages);

    QDateTime getTimeIssue();                // Геттер
    void setTimeIssue(QDateTime);            // Сеттер

    bool operator > (const TempEdition&); // ЛОгические операторы
    bool operator < (const TempEdition&);
    bool operator== (const TempEdition&);

    friend std::ofstream& operator<< (std::ofstream &out, TempEdition &); // Запись
    friend std::ifstream& operator>> (std::ifstream &in , TempEdition &); // и чтение из файла
};
