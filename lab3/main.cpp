#include <iostream>
#include "Transport.h"

using namespace std;

int main()
{
    cout << "Creating objects...\n\n";

    Car car("BMW", 200, 4);
    Train train("RZD", 120, 10);
    Express express("Sapsan", 250, 10, true);

    cout << "Adding objects to list...\n";

    car.Add();
    train.Add();
    express.Add();

    Transport::PrintList();

    return 0;
}