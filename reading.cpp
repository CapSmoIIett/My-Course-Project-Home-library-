#include "reading.h"
#include <string.h>
#include <stdio.h>

Reading::Reading()
{
    name = "unknown";
    pages = 0;
    top = 0;
}
Reading::Reading(std::string n, unsigned int p) :
name(n),
pages(p)
{
    top = 0;
}
bool Reading::operator > (const Reading& m)
{
    return (strcmp(name.c_str(), m.name.c_str())  > 0) ? 1 : 0;
}
bool Reading::operator < (const Reading& m)
{
    return (strcmp(name.c_str(), m.name.c_str())  < 0) ? 1 : 0;
}
bool Reading::operator== (const Reading& m)
{
    return (strcmp(name.c_str(), m.name.c_str()) == 0) ? 1 : 0;
}

void Reading::setName(std::string str)
{
    name = str;
}
void Reading::setPages(unsigned int n )
{
    pages = n;
}
void Reading::setTop(unsigned int n)
{
    top = n;
}
//void Reading::setTime(QTime)

std::string Reading::getName()
{
    return name;
}

unsigned    Reading::getTop()
{
    return top;
}
int         Reading::getPages()
{
    return pages;
}
std::ofstream& operator<< (std::ofstream &out, Reading &r)
{
    int t = r.name.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.name.c_str(), t);
    out.write(reinterpret_cast<char*>(&r.pages),sizeof(int));
    out.write(reinterpret_cast<char*>(&r.top), sizeof(int));
    return out;
}
std::ifstream& operator>> (std::ifstream &in, Reading &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны имени
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение имени
    buf1[len] = '\0';
    r.setName(buf1);

    in.read((char*)&r.pages, sizeof(int));      // Чтение кол страниц
    in.read((char*)&r.top, sizeof(int));        // Чтение закладки

    in.ignore(1);
    return in;
}

