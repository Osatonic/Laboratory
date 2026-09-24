#include "TransportSTL.h"

using namespace std;

TransportSTL::TransportSTL(string n, int s, int d)
{
    name = n;
    speed = s;
    doors = d;
}

const string& TransportSTL::GetName() const
{
    return name;
}

int TransportSTL::GetSpeed() const
{
    return speed;
}

int TransportSTL::GetDoors() const
{
    return doors;
}

void TransportSTL::Show() const
{
    cout << "Название: " << name
         << ", скорость: " << speed
         << ", дверей: " << doors
         << endl;
}

bool TransportSTL::operator<(const TransportSTL& other) const
{
    if (speed != other.speed)
        return speed < other.speed;

    return name < other.name;
}

bool TransportSTL::operator==(const TransportSTL& other) const
{
    return name == other.name &&
           speed == other.speed &&
           doors == other.doors;
}

ostream& operator<<(
    ostream& out,
    const TransportSTL& object)
{
    out << object.name
        << " | скорость = " << object.speed
        << " | дверей = " << object.doors;

    return out;
}

istream& operator>>(
    istream& in,
    TransportSTL& object)
{
    in >> object.name
       >> object.speed
       >> object.doors;

    return in;
}
