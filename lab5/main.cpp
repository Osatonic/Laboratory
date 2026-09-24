#include <iostream>
#include "List.h"
#include "../lab1/Hospital.h"

using namespace std;


// =====================================================
// Общая функция проверки стандартного типа.
// Для каждого типа проверяются:
// +, --, копирование, =, ==.
// =====================================================

template <class T>
void TestStandardType(const char* title, const T& value)
{
    cout << endl;
    cout << "========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;

    List<T> list;

    // Добавляем несколько элементов.
    list = list + value;
    list = list + value;
    list = list + value;

    cout << "Исходный список: ";
    list.Print();

    // Проверка +
    list = list + value;
    cout << "После operator+: ";
    list.Print();

    // Проверка --
    --list;
    cout << "После operator--: ";
    list.Print();

    // Проверка конструктора копирования.
    List<T> copy(list);
    cout << "Копия: ";
    copy.Print();

    // Проверка operator=
    List<T> assigned;
    assigned = list;
    cout << "После operator=: ";
    assigned.Print();

    // Проверка operator==
    if (list == copy)
        cout << "operator==: списки равны." << endl;
    else
        cout << "operator==: списки не равны." << endl;
}


int main()
{
    cout << "========================================" << endl;
    cout << "       LABORATORY WORK 5" << endl;
    cout << "       VARIANT 11" << endl;
    cout << "========================================" << endl;

    // =================================================
    // 1. CHAR
    // =================================================

    char ch;
    cout << endl;
    cout << "Введите символ для List<char>: ";
    cin >> ch;

    TestStandardType<char>("LIST <char>", ch);


    // =================================================
    // 2. INT
    // =================================================

    int number;
    cout << endl;
    cout << "Введите целое число для List<int>: ";
    cin >> number;

    TestStandardType<int>("LIST <int>", number);


    // =================================================
    // 3. REAL TYPE
    // =================================================

    double real;
    cout << endl;
    cout << "Введите вещественное число для List<double>: ";
    cin >> real;

    TestStandardType<double>("LIST <double>", real);


    // =================================================
    // 4. USER TYPE FROM LABORATORY WORK №1
    // =================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "LIST <HOSPITAL>" << endl;
    cout << "========================================" << endl;

    cout << "Введите данные больницы:" << endl;
    cout << "палаты оборудование детали работники часы фонд состояние" << endl;

    HOSPITAL hospital;

    cin >> hospital;

    List<HOSPITAL> hospitals;

    // + 
    hospitals = hospitals + hospital;
    hospitals = hospitals + hospital;

    cout << "Исходный список больниц: " << endl;
    hospitals.Print();

    // +
    hospitals = hospitals + hospital;

    cout << "После operator+: " << endl;
    hospitals.Print();

    // --
    --hospitals;

    cout << "После operator--: " << endl;
    hospitals.Print();

    // Конструктор копирования
    List<HOSPITAL> hospitalCopy(hospitals);

    cout << "Копия списка больниц: " << endl;
    hospitalCopy.Print();

    // =
    List<HOSPITAL> hospitalAssigned;
    hospitalAssigned = hospitals;

    cout << "После operator=: " << endl;
    hospitalAssigned.Print();

    // ==
    if (hospitals == hospitalCopy)
        cout << "operator==: списки больниц равны." << endl;
    else
        cout << "operator==: списки больниц не равны." << endl;


    cout << endl;
    cout << "========================================" << endl;
    cout << "КОНЕЦ ПРОГРАММЫ" << endl;
    cout << "========================================" << endl;

    return 0;
}