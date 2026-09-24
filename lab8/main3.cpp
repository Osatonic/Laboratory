#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <clocale>

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
    sort(first.begin(), first.end(), compDescending);

    cout << endl;
    cout << "1-2. Первый контейнер после "
         << "сортировки по убыванию:" << endl;
    printVector(first);

    // 3-4. Поиск подходящего элемента.
    vector<TransportSTL>::iterator found =
        find_if(first.begin(), first.end(), condition);

    cout << endl;
    cout << "3-4. Результат find_if:" << endl;

    if (found != first.end())
        cout << "Найден элемент: " << *found << endl;
    else
        cout << "Элемент не найден." << endl;

    // 5. Второй контейнер по варианту: map.
    // Сначала используем remove_copy_if, как рекомендует
    // методичка, чтобы получить только подходящие объекты.
    vector<TransportSTL> selected;

    remove_copy_if(
        first.begin(),
        first.end(),
        back_inserter(selected),
        [](const TransportSTL& object)
        {
            return !condition(object);
        }
    );

    map<int, TransportSTL> second;

    int key = 1;

    for (vector<TransportSTL>::const_iterator it =
             selected.begin();
         it != selected.end();
         ++it)
    {
        second[key] = *it;
        ++key;
    }

    cout << endl;
    cout << "5-6. Второй контейнер map:" << endl;
    printMap(second);

    // Для merge преобразуем значения map в последовательность.
    // map хранит pair<const int, TransportSTL>, поэтому его
    // элементы нельзя напрямую слить с vector<TransportSTL>.
    vector<TransportSTL> secondValues;

    for (map<int, TransportSTL>::const_iterator it =
             second.begin();
         it != second.end();
         ++it)
    {
        secondValues.push_back(it->second);
    }

    // 7. Сортируем первый и второй наборы по возрастанию.
    sort(first.begin(), first.end());
    sort(secondValues.begin(), secondValues.end());

    cout << endl;
    cout << "7-8. Первый контейнер по возрастанию:"
         << endl;
    printVector(first);

    cout << endl;
    cout << "7-8. Значения второго map по возрастанию:"
         << endl;
    printVector(secondValues);

    // 9. Третий контейнер получаем слиянием.
    vector<TransportSTL> third;

    merge(
        first.begin(),
        first.end(),
        secondValues.begin(),
        secondValues.end(),
        back_inserter(third)
    );

    cout << endl;
    cout << "9-10. Третий контейнер после merge:"
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

    cout << endl;
    cout << "11. Количество элементов третьего "
         << "контейнера со скоростью >= 180: "
         << count << endl;

    // 12. Проверяем наличие элемента по условию.
    vector<TransportSTL>::const_iterator check =
        find_if(
            third.begin(),
            third.end(),
            condition
        );

    cout << endl;
    cout << "12. Есть ли в третьем контейнере "
         << "элемент со скоростью >= 180? ";

    if (check != third.end())
        cout << "Да." << endl;
    else
        cout << "Нет." << endl;

    cout << endl;
    cout << "Работа программы №3 завершена." << endl;

    return 0;
}
