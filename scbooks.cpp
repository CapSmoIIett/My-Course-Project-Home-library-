#include "scbooks.h"

SCBooks::SCBooks() : Books()
{
    section = "unknown";
}
SCBooks::SCBooks(std::string n, unsigned int p,
        std::string a, std::string s) :
Books(n, p, a),
section(s)
{

}
bool SCBooks::operator > (const SCBooks& t)
{
    return static_cast<Books>(*this) >  static_cast<Books>(t);
}
bool SCBooks::operator < (const SCBooks& t)
{
    return static_cast<Books>(*this) <  static_cast<Books>(t);
}
bool SCBooks::operator== (const SCBooks& t)
{
    return static_cast<Books>(*this) == static_cast<Books>(t);
}
std::string SCBooks::getSection()
{
    return section;
}
void SCBooks::setSection(std::string str)
{
    section = str;
}
std::ofstream& operator<< (std::ofstream &out, SCBooks &r)
{
    int t = r.section.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.section.c_str(), t);
    out << dynamic_cast<Books&>(const_cast<SCBooks&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , SCBooks &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны жанра
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение жанра
    buf1[len] = '\0';
    r.setSection(buf1);
    in >> dynamic_cast<Books&>(const_cast<SCBooks&>(r));
    return in;
}
