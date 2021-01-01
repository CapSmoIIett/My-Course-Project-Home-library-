#include "books.h"

Books::Books() : Reading()
{
    author = "unknown";
}
Books::Books(std::string n, unsigned int p,
      std::string a) :
Reading(n, p),
author(a)
{

}
bool Books::operator > (const Books& t)
{
    return static_cast<Reading>(*this) >  static_cast<Reading>(t);
}
bool Books::operator < (const Books& t)
{
    return static_cast<Reading>(*this) <  static_cast<Reading>(t);
}
bool Books::operator== (const Books& t)
{
    return static_cast<Reading>(*this) == static_cast<Reading>(t);
}
std::string Books::getAuth()
{
    return author;
}
void Books::setAuth(std::string str)
{
    author = str;
}
std::ofstream& operator<< (std::ofstream &out, Books &r)
{
    int t = r.author.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.author.c_str(), t);
    out << dynamic_cast<Reading&>(const_cast<Books&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , Books &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны имени автора
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение имени автора
    buf1[len] = '\0';
    r.setAuth(buf1);
    in >> dynamic_cast<Reading&>(const_cast<Books&>(r));
    return in;
}
