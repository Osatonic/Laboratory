#include "List.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "===== ЛАБОРАТОРНАЯ РАБОТА №2 =====" << endl;
    cout << "===== ПЕРЕГРУЗКА ОПЕРАЦИЙ =====" << endl;
    cout << "===== ВАРИАНТ №11 =====" << endl;

    cout << "
1. ВВОД ПЕРВОГО СПИСКА" << endl;

    List L1;
    L1.Input();

    cout << "L1 = ";
    L1.Print();

    cout << "
2. ВВОД ВТОРОГО СПИСКА" << endl;

    List L2;
    L2.Input();

    cout << "L2 = ";
    L2.Print();

    cout << "
3. КОНСТРУКТОР КОПИРОВАНИЯ" << endl;

    List L3(L1);

    cout << "L3 = ";
    L3.Print();

    cout << "
4. ОПЕРАТОР ПРИСВАИВАНИЯ" << endl;

    List L4;
    L4 = L2;

    cout << "L4 = ";
    L4.Print();

    cout << "
5. ОПЕРАТОР []" << endl;

    try
    {
        cout << "Введите индекс для проверки: ";

        int index;
        cin >> index;

        cout << "L1[" << index << "] = "
             << L1[index] << endl;

        L1[index] = '*';

        cout << "После изменения: ";
        L1.Print();
    }
    catch (const out_of_range& error)
    {
        cout << "Ошибка: " << error.what() << endl;
    }

    cout << "
6. ОПЕРАТОР +" << endl;

    List L5 = L1 + L2;

    cout << "L1 = ";
    L1.Print();

    cout << "L2 = ";
    L2.Print();

    cout << "L5 = L1 + L2 = ";
    L5.Print();

    cout << "
7. ОПЕРАТОР !=" << endl;

    if (L1 != L2)
        cout << "L1 и L2 не равны." << endl;
    else
        cout << "L1 и L2 равны." << endl;

    cout << "
8. ПРОВЕРКА НЕЗАВИСИМОСТИ КОПИИ" << endl;

    cout << "L1 = ";
    L1.Print();

    cout << "L3 = ";
    L3.Print();

    if (L3[0] || true)
    {
        try
        {
            L3[0] = '#';
        }
        catch (const out_of_range& error)
        {
            cout << "L3 пуст: " << error.what() << endl;
        }
    }

    cout << "
После изменения L3:" << endl;

    cout << "L1 = ";
    L1.Print();

    cout << "L3 = ";
    L3.Print();

    cout << "
===== КОНЕЦ ПРОГРАММЫ =====" << endl;

    return 0;
}
