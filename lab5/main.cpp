#include <iostream>
#include "List.h"

using namespace std;


int main()
{
    // ==================================================
    // 1. LIST CHAR
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
    // 2. COPY CONSTRUCTOR
    // ==================================================

    cout << endl;
    cout << "Копирование списка:" << endl;

    List<char> copy(letters);

    cout << "Исходный: ";
    letters.Print();

    cout << "Копия:    ";
    copy.Print();


    // ==================================================
    // 3. OPERATOR =
    // ==================================================

    cout << endl;
    cout << "Присваивание:" << endl;

    List<char> assigned;

    assigned = letters;

    cout << "assigned: ";
    assigned.Print();


    // ==================================================
    // 4. OPERATOR ==
    // ==================================================

    cout << endl;
    cout << "Проверка == :" << endl;

    if (letters == copy)
    {
        cout << "Списки равны." << endl;
    }
    else
    {
        cout << "Списки не равны." << endl;
    }


    // ==================================================
    // 5. LIST INT
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
    // 6. LIST DOUBLE
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


    return 0;
}