#include <iostream>

#include "List.h"
#include "../lab1/Hospital.h"

using namespace std;


int main()
{
    // ==================================================
    // 1. LIST <char>
    // ==================================================

    cout << "====================================" << endl;
    cout << "LIST <char>" << endl;
    cout << "====================================" << endl;

    List<char> letters;

    letters.Input();

    cout << endl;
    cout << "Исходный список: ";
    letters.Print();

    // + — добавить в начало

    letters = letters + 'X';

    cout << "После letters + 'X': ";
    letters.Print();

    // -- — удалить из начала

    --letters;

    cout << "После --letters: ";
    letters.Print();


    // ==================================================
    // 2. КОНСТРУКТОР КОПИРОВАНИЯ
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "КОНСТРУКТОР КОПИРОВАНИЯ" << endl;
    cout << "====================================" << endl;

    List<char> copy(letters);

    cout << "Исходный: ";
    letters.Print();

    cout << "Копия:    ";
    copy.Print();


    // ==================================================
    // 3. ОПЕРАТОР =
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "ОПЕРАТОР =" << endl;
    cout << "====================================" << endl;

    List<char> assigned;

    assigned = letters;

    cout << "assigned: ";
    assigned.Print();


    // ==================================================
    // 4. ОПЕРАТОР ==
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "ОПЕРАТОР ==" << endl;
    cout << "====================================" << endl;

    if (letters == copy)
    {
        cout << "Списки равны." << endl;
    }
    else
    {
        cout << "Списки не равны." << endl;
    }


    // ==================================================
    // 5. LIST <int>
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "LIST <int>" << endl;
    cout << "====================================" << endl;

    List<int> numbers;

    numbers.Input();

    cout << "Исходный список: ";
    numbers.Print();

    numbers = numbers + 100;

    cout << "После numbers + 100: ";
    numbers.Print();

    --numbers;

    cout << "После --numbers: ";
    numbers.Print();


    // ==================================================
    // 6. LIST <double>
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "LIST <double>" << endl;
    cout << "====================================" << endl;

    List<double> values;

    values.Input();

    cout << "Исходный список: ";
    values.Print();

    values = values + 9.99;

    cout << "После values + 9.99: ";
    values.Print();

    --values;

    cout << "После --values: ";
    values.Print();


    // ==================================================
    // 7. LIST <HOSPITAL>
    // ==================================================

    cout << endl;
    cout << "====================================" << endl;
    cout << "LIST <HOSPITAL>" << endl;
    cout << "====================================" << endl;

    List<HOSPITAL> hospitals;

    hospitals.Input();

    cout << endl;
    cout << "Исходный список больниц:" << endl;
    hospitals.Print();


    // ==================================================
    // 8. OPERATOR + ДЛЯ HOSPITAL
    // ==================================================

    cout << endl;
    cout << "Добавляем новую больницу в начало:" << endl;

    HOSPITAL newHospital(
        70,
        35,
        2800,
        110,
        360,
        850000,
        "Строительство"
    );

    hospitals = hospitals + newHospital;

    cout << "После hospitals + newHospital:" << endl;
    hospitals.Print();


    // ==================================================
    // 9. OPERATOR -- ДЛЯ HOSPITAL
    // ==================================================

    cout << endl;
    cout << "Удаляем первую больницу:" << endl;

    --hospitals;

    hospitals.Print();


    // ==================================================
    // 10. КОПИРОВАНИЕ LIST <HOSPITAL>
    // ==================================================

    cout << endl;
    cout << "Копирование списка больниц:" << endl;

    List<HOSPITAL> hospitalCopy(hospitals);

    cout << "Исходный список:" << endl;
    hospitals.Print();

    cout << "Копия:" << endl;
    hospitalCopy.Print();


    // ==================================================
    // 11. ОПЕРАТОР = ДЛЯ LIST <HOSPITAL>
    // ==================================================

    cout << endl;
    cout << "Присваивание списка больниц:" << endl;

    List<HOSPITAL> hospitalAssigned;

    hospitalAssigned = hospitals;

    cout << "Присвоенный список:" << endl;
    hospitalAssigned.Print();


    // ==================================================
    // 12. ОПЕРАТОР == ДЛЯ LIST <HOSPITAL>
    // ==================================================

    cout << endl;
    cout << "Проверка равенства списков больниц:" << endl;

    if (hospitals == hospitalCopy)
    {
        cout << "Списки больниц равны." << endl;
    }
    else
    {
        cout << "Списки больниц не равны." << endl;
    }


    cout << endl;
    cout << "====================================" << endl;
    cout << "КОНЕЦ ПРОГРАММЫ" << endl;
    cout << "====================================" << endl;

    return 0;
}