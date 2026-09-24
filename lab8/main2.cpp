#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "../lab7/TransportFile.h"
#include "TransportSTL.h"

using namespace std;

const char* FILE_NAME = "transport.dat";

void printVector(const vector<TransportSTL>& container)
{
    cout << "vector<TransportSTL>:" << endl;

    for (vector<TransportSTL>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << "  " << *it << endl;
    }
}

void printMap(const map<int, TransportSTL>& container)
{
    cout << "map<int, TransportSTL>:" << endl;

    for (map<int, TransportSTL>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << "  [" << it->first << "] "
             << it->second << endl;
    }
}

bool loadFromLab7(
    const char* fileName,
    vector<TransportSTL>& container)
{
    ifstream in(fileName, ios::binary);

    if (!in)
        return false;

    in.seekg(0, ios::end);
    long fileSize = static_cast<long>(in.tellg());
    in.seekg(0, ios::beg);

    if (fileSize <= 0 ||
        fileSize % static_cast<long>(sizeof(TransportFile)) != 0)
    {
        in.close();
        return false;
    }

    int count =
        static_cast<int>(
            fileSize / sizeof(TransportFile)
        );

    for (int i = 0; i < count; ++i)
    {
        TransportFile source;

        in.read(
            reinterpret_cast<char*>(&source),
            sizeof(TransportFile)
        );

        if (!in)
        {
            in.close();
            return false;
        }

        container.push_back(
            TransportSTL(
                source.GetName(),
                source.GetSpeed(),
                source.GetDoors()
            )
        );
    }

    in.close();

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "========================================" << endl;
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8 - ПРОГРАММА №2" << endl;
    cout << "Пользовательский тип + данные ЛР7" << endl;
    cout << "========================================" << endl;

    vector<TransportSTL> first;

    // По методическим указаниям объекты пользовательского
    // типа загружаются из потока, созданного в ЛР7.
    if (!loadFromLab7(FILE_NAME, first))
    {
        cerr << "\nНе удалось прочитать " << FILE_NAME << "." << endl;
        cerr << "Сначала запусти lab7_1 и создай файл transport.dat." << endl;
        return 1;
    }

    if (first.empty())
    {
        cerr << "Файл не содержит объектов." << endl;
        return 1;
    }

    cout << "\n1. Исходный vector:" << endl;
    printVector(first);

    // 2. Изменяем контейнер:
    // заменяем первый элемент и удаляем второй.
    if (first.size() >= 2)
    {
        first[0] = first[1];
        first.erase(first.begin() + 1);
    }

    cout << "\n2. Vector после изменения:" << endl;
    printVector(first);

    // 3. Просмотр через итераторы.
    cout << "\n3. Просмотр итераторами:" << endl;

    for (vector<TransportSTL>::iterator it = first.begin();
         it != first.end();
         ++it)
    {
        cout << "  " << *it << endl;
    }

    // 4. Второй контейнер по варианту: map.
    map<int, TransportSTL> second;

    int key = 1;

    for (vector<TransportSTL>::const_iterator it = first.begin();
         it != first.end();
         ++it)
    {
        second[key] = *it;
        ++key;
    }

    cout << "\n4. Второй контейнер:" << endl;
    printMap(second);

    // 5. Удаляем n элементов после заданного.
    int n = 1;

    if (first.size() > 1)
    {
        vector<TransportSTL>::iterator start =
            first.begin() + 1;

        vector<TransportSTL>::iterator finish =
            start + n;

        if (finish > first.end())
            finish = first.end();

        first.erase(start, finish);
    }

    cout << "\n5. Vector после удаления "
         << n << " элемента после заданного:" << endl;
    printVector(first);

    // 6. Добавляем все значения map в vector.
    for (map<int, TransportSTL>::const_iterator it =
             second.begin();
         it != second.end();
         ++it)
    {
        first.push_back(it->second);
    }

    cout << "\n6. Vector после добавления элементов map:"
         << endl;
    printVector(first);

    // 7. Итоговый просмотр.
    cout << "\n7. Итоговые контейнеры:" << endl;
    printVector(first);
    printMap(second);

    cout << "\nРабота программы №2 завершена." << endl;

    return 0;
}
