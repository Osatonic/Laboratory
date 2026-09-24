#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

#include "TransportSTL.h"

using namespace std;

// Условие поиска:
// транспорт со скоростью не менее 180.
bool condition(const TransportSTL& object)
{
    return object.GetSpeed() >= 180;
}

// Сравнение для сортировки по убыванию.
bool compDescending(
    const TransportSTL& left,
    const TransportSTL& right)
{
    if (left.GetSpeed() != right.GetSpeed())
        return left.GetSpeed() > right.GetSpeed();

    return left.GetName() > right.GetName();
}

void printVector(const vector<TransportSTL>& container)
{
    for (vector<TransportSTL>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << "  " << *it << endl;
    }
}

void printMap(const map<int, TransportSTL>& container)
{
    for (map<int, TransportSTL>::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        cout << "  [" << it->first << "] "
             << it->second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "========================================" << endl;
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8 - ПРОГРАММА №3" << endl;
    cout << "Алгоритмы STL" << endl;
    cout << "========================================" << endl;

    // 1. Первый контейнер по варианту: vector.
    vector<TransportSTL> first;

    first.push_back(TransportSTL("BMW", 200, 4));
    first.push_back(TransportSTL("Mercedes", 220, 4));
    first.push_back(TransportSTL("RZD", 120, 0));
    first.push_back(TransportSTL("Sapsan", 250, 0));
    first.push_back(TransportSTL("Lastochka", 180, 0));
    first.push_back(TransportSTL("Audi", 160, 4));

    // 2. Сортировка по убыванию.
    sort(
        first.begin(),
        first.end(),
        compDescending
    );

    cout << "\n1-2. Первый контейнер после "
         << "сортировки по убыванию:" << endl;
    printVector(first);

    // 3-4. Поиск подходящего элемента.
    vector<TransportSTL>::iterator found =
        find_if(
            first.begin(),
            first.end(),
            condition
        );

    cout << "\n3-4. Результат find_if:" << endl;

    if (found != first.end())
    {
        cout << "Найден элемент: "
             << *found << endl;
    }
    else
    {
        cout << "Элемент не найден." << endl;
    }

    // 5. Второй контейнер по варианту: map.
    // В map переносим все элементы, удовлетворяющие условию.
    map<int, TransportSTL> second;

    int key = 1;

    for (vector<TransportSTL>::const_iterator it =
             first.begin();
         it != first.end();
         ++it)
    {
        if (condition(*it))
        {
            second[key] = *it;
            ++key;
        }
    }

    cout << "\n5-6. Второй контейнер map:" << endl;
    printMap(second);

    // Для merge преобразуем значения map в отсортированную
    // последовательность. Сам map содержит pair<const int, T>,
    // поэтому его напрямую с vector<T> объединить нельзя.
    vector<TransportSTL> secondValues;

    for (map<int, TransportSTL>::const_iterator it =
             second.begin();
         it != second.end();
         ++it)
    {
        secondValues.push_back(it->second);
    }

    // 7. Сортируем оба набора по возрастанию.
    sort(first.begin(), first.end());

    sort(
        secondValues.begin(),
        secondValues.end()
    );

    cout << "\n7-8. Первый контейнер по возрастанию:"
         << endl;
    printVector(first);

    cout << "\n7-8. Значения второго map по возрастанию:"
         << endl;
    printVector(secondValues);

    // 9. Третий контейнер получаем слиянием
    // отсортированных последовательностей.
    vector<TransportSTL> third;

    merge(
        first.begin(),
        first.end(),
        secondValues.begin(),
        secondValues.end(),
        back_inserter(third)
    );

    cout << "\n9-10. Третий контейнер после merge:"
         << endl;
    printVector(third);

    // 11. Подсчет элементов по условию.
    int count = static_cast<int>(
        count_if(
            third.begin(),
            third.end(),
            condition
        )
    );

    cout << "\n11. Количество элементов третьего "
         << "контейнера со скоростью >= 180: "
         << count << endl;

    // 12. Проверяем наличие элемента по условию.
    vector<TransportSTL>::const_iterator check =
        find_if(
            third.begin(),
            third.end(),
            condition
        );

    cout << "\n12. Есть ли в третьем контейнере "
         << "элемент со скоростью >= 180? ";

    if (check != third.end())
        cout << "Да." << endl;
    else
        cout << "Нет." << endl;

    cout << "\nРабота программы №3 завершена." << endl;

    return 0;
}
