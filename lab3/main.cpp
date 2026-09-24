#include <iostream>
#include "Transport.h"

using namespace std;


int main()
{
    cout << "=================================\n";
    cout << "       LABORATORY WORK 3\n";
    cout << "=================================\n\n";


    // =================================
    // 1. РУЧНОЕ ДОБАВЛЕНИЕ
    // =================================

    cout << "1. MANUAL ADD\n\n";

    Car car("BMW", 200, 4, false);
    Train train("RZD", 120, 10, false);
    Express express("Sapsan", 250, 10, true, false);

    cout << "\nAdding objects manually...\n";

    car.Add();
    train.Add();
    express.Add();


    // Просмотр списка
    // Статический метод вызывается через класс
    Transport::PrintList();


    // =================================
    // 2. АВТОМАТИЧЕСКОЕ ДОБАВЛЕНИЕ
    // =================================

    cout << "\n\n2. AUTOMATIC ADD IN CONSTRUCTOR\n\n";

    Car autoCar("Mercedes", 220, 4, true);
    Train autoTrain("Siemens", 160, 12, true);
    Express autoExpress("Lastochka", 180, 5, false, true);


    // Объекты уже находятся в списке,
    // потому что autoAdd = true

    Transport::PrintList();


    cout << "\nProgram finished.\n";

    return 0;
}