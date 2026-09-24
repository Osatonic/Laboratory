#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVector(const vector<double>& container)
{
    cout << "vector<double>: ";

    for (vector<double>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
}

void printMap(const map<int, double>& container)
{
    cout << "map<int, double>: ";

    for (map<int, double>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << "[" << it->first << "] = "
             << it->second << " ";
    }

    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "========================================" << endl;
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8 - ПРОГРАММА №1" << endl;
    cout << "Вариант 11: vector / map / double" << endl;
    cout << "========================================" << endl;

    // 1. Первый контейнер по варианту: vector<double>.
    vector<double> first;

    first.push_back(10.5);
    first.push_back(20.5);
    first.push_back(30.5);
    first.push_back(40.5);
    first.push_back(50.5);
    first.push_back(60.5);

    cout << "\n1. Исходный первый контейнер:" << endl;
    printVector(first);

    // 2. Изменяем контейнер:
    // заменяем один элемент и удаляем другой.
    first[2] = 99.9;
    first.erase(first.begin() + 1);

    cout << "\n2. Первый контейнер после изменения:" << endl;
    printVector(first);

    // 3. Просмотр через итераторы.
    cout << "\n3. Просмотр первого контейнера итераторами:" << endl;

    for (vector<double>::iterator it = first.begin();
         it != first.end();
         ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // 4. Второй контейнер по варианту: map<int, double>.
    map<int, double> second;

    second[1] = 1.1;
    second[2] = 2.2;
    second[3] = 3.3;

    cout << "\n4. Второй контейнер:" << endl;
    printMap(second);

    // 5. Удаляем n элементов после заданного элемента.
    // После элемента с индексом 1 удаляем два следующих.
    int n = 2;

    if (first.size() > 1)
    {
        vector<double>::iterator start = first.begin() + 2;

        vector<double>::iterator finish = start + n;

        if (finish > first.end())
            finish = first.end();

        first.erase(start, finish);
    }

    cout << "\n5. Первый контейнер после удаления "
         << n << " элементов после заданного:" << endl;
    printVector(first);

    // 6. Добавляем в первый контейнер значения второго.
    for (map<int, double>::const_iterator it = second.begin();
         it != second.end();
         ++it)
    {
        first.push_back(it->second);
    }

    cout << "\n6. Первый контейнер после добавления "
         << "элементов второго:" << endl;
    printVector(first);

    // 7. Просмотр обоих контейнеров.
    cout << "\n7. Итоговые контейнеры:" << endl;
    printVector(first);
    printMap(second);

    cout << "\nРабота программы №1 завершена." << endl;

    return 0;
}
