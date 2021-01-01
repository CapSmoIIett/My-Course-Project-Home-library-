#include "artbooks.h"

ARTBooks::ARTBooks() : Books()
{
        genre = "unknown";
}
ARTBooks::ARTBooks(std::string n, unsigned int p,
          std::string a, std::string g) :
Books(n, p, a),
genre(g)
{

}
bool ARTBooks::operator > (const ARTBooks& t)
{
    return static_cast<Books>(*this) >  static_cast<Books>(t);
}
bool ARTBooks::operator < (const ARTBooks& t)
{
    return static_cast<Books>(*this) <  static_cast<Books>(t);
}
bool ARTBooks::operator== (const ARTBooks& t)
{
    return static_cast<Books>(*this) == static_cast<Books>(t);
}

std::string ARTBooks::getGenre()
{
    return genre;
}
void ARTBooks::setGenre(std::string str)
{
    genre = str;
}
std::ofstream& operator<< (std::ofstream &out, ARTBooks &r)
{
    int t = r.genre.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)r.genre.c_str(), t);
    out << dynamic_cast<Books&>(const_cast<ARTBooks&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , ARTBooks &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны жанра
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение жанра
    buf1[len] = '\0';
    r.setGenre(buf1);
    in >> dynamic_cast<Books&>(const_cast<ARTBooks&>(r));
    return in;
}
