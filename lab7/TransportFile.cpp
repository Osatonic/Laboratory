#include "TransportFile.h"

using namespace std;

TransportFile::TransportFile()
{
    strcpy(name, "");
    speed = 0;
    doors = 0;
}

TransportFile::TransportFile(const char* n, int s, int d)
{
    strncpy(name, n, 49);
    name[49] = '\0';
    speed = s;
    doors = d;
}

TransportFile::TransportFile(const TransportFile& other)
{
    strcpy(name, other.name);
    speed = other.speed;
    doors = other.doors;
}

TransportFile::~TransportFile()
{
}

TransportFile& TransportFile::operator=(const TransportFile& other)
{
    if (this != &other)
    {
        strcpy(name, other.name);
        speed = other.speed;
        doors = other.doors;
    }

    return *this;
}

void TransportFile::Input()
{
    cout << "Введите название транспорта: ";
    cin >> name;

    cout << "Введите скорость: ";
    cin >> speed;

    cout << "Введите количество дверей: ";
    cin >> doors;
}

void TransportFile::Show() const
{
    cout << "Название: " << name
         << ", скорость: " << speed
         << ", дверей: " << doors
         << endl;
}

const char* TransportFile::GetName() const
{
    return name;
}

ostream& operator<<(ostream& out, const TransportFile& object)
{
    out << object.name << " "
        << object.speed << " "
        << object.doors;

    return out;
}

istream& operator>>(istream& in, TransportFile& object)
{
    in >> object.name
       >> object.speed
       >> object.doors;

    return in;
}

bool TransportFile::operator==(const TransportFile& other) const
{
    return strcmp(name, other.name) == 0 &&
           speed == other.speed &&
           doors == other.doors;
}
