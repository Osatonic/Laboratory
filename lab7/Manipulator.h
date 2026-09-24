#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <iostream>
#include <iomanip>

using namespace std;

class MyManipulator
{
private:
    int width;
    char fill;

public:
    MyManipulator(int w, char f)
    {
        width = w;
        fill = f;
    }

    friend ostream& operator<<(ostream& out, const MyManipulator& manip)
    {
        out << setfill(manip.fill)
            << setw(manip.width);

        return out;
    }
};

MyManipulator mymanip(int width, char fill)
{
    return MyManipulator(width, fill);
}

#endif
