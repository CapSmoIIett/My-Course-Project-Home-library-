#include "tempedition.h"

TempEdition::TempEdition()
{

}
TempEdition::TempEdition(std::string name, unsigned int pages):
Reading(name, pages)
{
    date_of_issue = QDateTime::currentDateTime();
}
bool TempEdition::operator > (const TempEdition& t)
{
    return static_cast<Reading>(*this) >  static_cast<Reading>(t);
}
bool TempEdition::operator < (const TempEdition& t)
{
    return static_cast<Reading>(*this) <  static_cast<Reading>(t);
}
bool TempEdition::operator== (const TempEdition& t)
{
    return static_cast<Reading>(*this) == static_cast<Reading>(t);
}
QDateTime TempEdition::getTimeIssue()
{
    return date_of_issue;
}
void TempEdition::setTimeIssue(QDateTime time)
{
    date_of_issue = time;
}
std::ofstream& operator<< (std::ofstream &out, TempEdition &r)
{
    std::string str = r.date_of_issue.toString("dd.MM.yyyy").toUtf8().constData();
    int t = str.size();
    out.write(reinterpret_cast<char*>(&t), sizeof (int));
    out.write((char*)str.c_str(), t);
    out << dynamic_cast<Reading&>(const_cast<TempEdition&>(r));
    return out;
}
std::ifstream& operator>> (std::ifstream &in , TempEdition &r)
{
    int len = 0;
    in.read((char*)&len, sizeof (int));                 // Чтение длинны имени автора
    char buf1[len + 1];
    in.read(buf1, len);                                 // Чтение имени автора
    buf1[len] = '\0';
    QDateTime temp = QDateTime::fromString(buf1, "dd.MM.yyyy");
    r.date_of_issue = temp;
    in >> dynamic_cast<Reading&>(const_cast<TempEdition&>(r));
    return in;
}
