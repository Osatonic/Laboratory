#ifndef TRANSPORT_STL_H
#define TRANSPORT_STL_H

#include <iostream>
#include <string>

using namespace std;

// Пользовательский тип для ЛР8.
// Поля соответствуют данным транспортного класса из ЛР3
// и загружаются из бинарного потока ЛР7.
class TransportSTL
{
private:
    string name;
    int speed;
    int doors;

public:
    TransportSTL(
        string n = "",
        int s = 0,
        int d = 0
    );

    const string& GetName() const;
    int GetSpeed() const;
    int GetDoors() const;

    void Show() const;

    bool operator<(const TransportSTL& other) const;
    bool operator==(const TransportSTL& other) const;

    friend ostream& operator<<(
        ostream& out,
        const TransportSTL& object
    );

    friend istream& operator>>(
        istream& in,
        TransportSTL& object
    );
};

#endif
