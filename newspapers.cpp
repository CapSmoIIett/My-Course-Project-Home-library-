#include "newspapers.h"

Newspapers::Newspapers()
{

}
Newspapers::Newspapers(std::string n, unsigned int p, std::string s) :
TempEdition(n, p),
location(s)
{

}
bool Newspapers::operator > (const Newspapers& t)
{
    return static_cast<TempEdition>(*this) >  static_cast<TempEdition>(t);
}
bool Newspapers::operator < (const Newspapers& t)
{
    return static_cast<TempEdition>(*this) <  static_cast<TempEdition>(t);
}
bool Newspapers::operator== (const Newspapers& t)
{
    return static_cast<TempEdition>(*this) == static_cast<TempEdition>(t);
}
std::string Newspapers::getLocation()
{
    return location;
}
void Newspapers::setLocation(std::string str)
{
    location = str;
}
std::ofstream& operator<< (std::ofstream &out, Newspapers &r)
{
    int t = r.location.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.location.c_str(), t);
    out << dynamic_cast<TempEdition&>(const_cast<Newspapers&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , Newspapers &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны жанра
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение жанра
    buf1[len] = '\0';
    r.setLocation(buf1);
    in >> dynamic_cast<TempEdition&>(const_cast<Newspapers&>(r));
    return in;
}

