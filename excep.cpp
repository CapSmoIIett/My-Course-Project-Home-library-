#include "excep.h"


#include "limits.h"

using namespace std;

Exception::Exception() noexcept                                        // Конструктор
{
    message = "Indefinitely";
}
Exception::Exception(string str) noexcept                              // Конструктор
{
    message = str;
}
Exception::Exception(const Exception& excep) noexcept                  // Конструктор
{
    message = excep.message;
}
Exception& Exception::operator= (const Exception& excep) noexcept
{
    this->message = excep.message;
    return *this;
}
Exception::~Exception()                                                 // Деструктор
{

}
const std::string Exception::what() noexcept
{
    return message;
}   

excepProblemword::excepProblemword(const std::string& str) noexcept :   // Конструктор
Exception(str)
{
    text = " ";
}
excepProblemword::excepProblemword(const std::string& str,              // Конструктор
        const std::string& text) noexcept :
Exception(str),
text(text)
{

}
const char* excepProblemword::gettext() noexcept                         // Взятие проблемной строки
{
    return text.c_str();
}


NumberException::NumberException(const std::string& str, long double n) noexcept :  // Конструктор
Exception(str),
number(n)
{
    size = sizeof(n);
}
NumberException::NumberException(const std::string& str, int n) noexcept :          // Конструктор
Exception(str)
{
    number = static_cast<long double>(n);
    size = sizeof(n);
}
NumberException::~NumberException()
{

}
long double NumberException::getnumber() noexcept                                   // Взятие проблемного числа
{
    return number;
}
long int NumberException::getsize() noexcept
{
    return size;
}






/* Проверки */
bool checkNumber(int n, int h, int d)
{
    if (n < d || n > h) throw NumberException ("Wrong number", n);
    return 1;
}
bool checkString(std::string str)
{
    for(int i = 0; i < (int)str.length(); i++){
        if( str[i] == '!' || str[i] == '?' ||
            str[i] == '@' || str[i] == '#'){
            throw excepProblemword("Unexpected symbols");
        }
    }
    return 1;
}
bool stringWithInt(std::string str)
{
    for(int i = 0; i < (int)str.length(); i++){
        if(!(str[i] >= '0' && str[i] <= '9')){
            throw excepProblemword("This is not a number");
        }
    }
    return 1;
}
bool checkDate(QDateTime date)
{
    if(date > QDateTime::currentDateTime()) throw Exception("Wrong data");
    return 1;
}

