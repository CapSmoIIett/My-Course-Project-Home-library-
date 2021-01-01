#include "magazines.h"

Magazines::Magazines()
{

}
Magazines::Magazines(std::string n, unsigned int p, std::string s) :
TempEdition(n, p),
subject(s)
{

}
bool Magazines::operator > (const Magazines& t)
{
    return static_cast<TempEdition>(*this) >  static_cast<TempEdition>(t);
}
bool Magazines::operator < (const Magazines& t)
{
    return static_cast<TempEdition>(*this) <  static_cast<TempEdition>(t);
}
bool Magazines::operator== (const Magazines& t)
{
    return static_cast<TempEdition>(*this) == static_cast<TempEdition>(t);
}
std::string Magazines::getSubject()
{
    return subject;
}
void Magazines::setSubject(std::string str)
{
    subject = str;
}
std::ofstream& operator<< (std::ofstream &out, Magazines &r)
{
    int t = r.subject.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.subject.c_str(), t);
    out << dynamic_cast<TempEdition&>(const_cast<Magazines&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , Magazines &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны тематики
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение тематики
    buf1[len] = '\0';
    r.setSubject(buf1);
    in >> dynamic_cast<TempEdition&>(const_cast<Magazines&>(r));
    return in;
}
