#pragma once
#include <iostream>
#include <string.h>
#include <exception>
#include <QDateTime>

class Exception                                      // Мой класс исключений
{
    std::string message;
public:
    Exception() noexcept;                            // Конструкторы
    Exception(std::string message) noexcept;
    Exception(const Exception&) noexcept;
    Exception& operator= (const Exception&) noexcept;
    virtual ~Exception() noexcept;                   // Деструктор
    virtual const std::string what() noexcept ;      // Возвращает текстовой объяснение исключения
};


class excepProblemword : public Exception
{
    std::string text;                                // Слово вызвавшее исключение
public:
    explicit excepProblemword(const std::string& message) noexcept; // Конструкторы
    explicit excepProblemword(const std::string& message,
        const std::string& text) noexcept;
    virtual ~excepProblemword() {}                   // Деструктор
    const char* gettext() noexcept;                  // Вывод текста  с ошибкой
    
};

class NumberException: public Exception       // Исключение для натуральных чисел
{
    long double number;                       // число вызвавшее исключение
    long int size;                            // Его размер
public:
    explicit NumberException(const std::string& message, long double number = 0) noexcept;  // конструкторы
    explicit NumberException(const std::string& message, int number) noexcept;
    virtual ~NumberException();               // Деструкторы
    long double getnumber() noexcept;         // Геттеры
    long int getsize() noexcept;
};



bool checkNumber(int, int, int d = 0);        // Функции проверки
bool checkString(std::string);
bool stringWithInt(std::string);
bool checkDate(QDateTime);
