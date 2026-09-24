#ifndef TRANSPORTFILE_H
#define TRANSPORTFILE_H

#include <iostream>
#include <cstring>

using namespace std;

class TransportFile
{
private:
    char name[50];
    int speed;
    int doors;

public:
    TransportFile();
    TransportFile(const char* n, int s, int d);
    TransportFile(const TransportFile& other);
    ~TransportFile();

    TransportFile& operator=(const TransportFile& other);

    void Input();
    void Show() const;

    const char* GetName() const;
    int GetSpeed() const;
    int GetDoors() const;

    friend ostream& operator<<(ostream& out, const TransportFile& object);
    friend istream& operator>>(istream& in, TransportFile& object);

    bool operator==(const TransportFile& other) const;
};

#endif
