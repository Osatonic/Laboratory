#include <iostream>
#include <stdexcept>

#include "List.h"

using namespace std;


// ============================================
// MAIN
// ============================================

int main()
{
    cout << "========================================" << endl;
    cout << "      ЛАБОРАТОРНАЯ РАБОТА №6" << endl;
    cout << "      ИСКЛЮЧИТЕЛЬНЫЕ СИТУАЦИИ" << endl;
    cout << "      ВАРИАНТ №11" << endl;
    cout << "========================================" << endl;


    // ========================================
    // 1. СОЗДАЁМ СПИСОК
    // ========================================

    List list;

    list.Input();

    cout << endl;

    cout << "Полученный список: ";
    list.Print();


    // ========================================
    // 2. ИСКЛЮЧЕНИЕ out_of_range
    //
    // Выход за границы списка
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "1. ПРОВЕРКА out_of_range" << endl;
    cout << "========================================" << endl;

    try
    {
        int index;

        cout << "Введите индекс элемента: ";
        cin >> index;

        cout << "Элемент: "
             << list[index]
             << endl;
    }
    catch (const out_of_range& error)
    {
        cout << "Перехвачено исключение out_of_range!" << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;
    }


    // ========================================
    // 3. ЕЩЁ ОДНО out_of_range
    //
    // Доступ к первому элементу пустого списка
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "2. ПРОВЕРКА ПУСТОГО СПИСКА" << endl;
    cout << "========================================" << endl;

    List emptyList;

    try
    {
        cout << "Первый элемент: "
             << emptyList.Front()
             << endl;
    }
    catch (const out_of_range& error)
    {
        cout << "Перехвачено исключение!" << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;
    }


    // ========================================
    // 4. RemoveAt()
    //
    // Попытка удалить неправильный индекс
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "3. ПРОВЕРКА RemoveAt()" << endl;
    cout << "========================================" << endl;

    try
    {
        int index;

        cout << "Введите индекс для удаления: ";
        cin >> index;

        list.RemoveAt(index);

        cout << "Элемент успешно удалён." << endl;

        cout << "Список после удаления: ";
        list.Print();
    }
    catch (const out_of_range& error)
    {
        cout << "Ошибка удаления!" << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;
    }


    // ========================================
    // 5. invalid_argument
    //
    // Демонстрация другого типа исключения
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "4. ПРОВЕРКА invalid_argument" << endl;
    cout << "========================================" << endl;

    try
    {
        int value;

        cout << "Введите количество элементов: ";
        cin >> value;

        if (value < 0)
        {
            throw invalid_argument(
                "Количество элементов не может быть отрицательным."
            );
        }

        cout << "Количество элементов: "
             << value
             << endl;
    }
    catch (const invalid_argument& error)
    {
        cout << "Перехвачено исключение invalid_argument!" << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;
    }


    // ========================================
    // 6. runtime_error
    //
    // Проверяем ошибку ввода
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "5. ПРОВЕРКА runtime_error" << endl;
    cout << "========================================" << endl;

    try
    {
        int number;

        cout << "Введите целое число: ";
        cin >> number;

        if (cin.fail())
        {
            throw runtime_error(
                "Вместо целого числа введено некорректное значение."
            );
        }

        cout << "Вы ввели: "
             << number
             << endl;
    }
    catch (const runtime_error& error)
    {
        cout << "Перехвачено исключение runtime_error!" << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;

        // Сбрасываем состояние потока
        cin.clear();
        cin.ignore(10000, '\n');
    }


    // ========================================
    // 7. ОБЩИЙ catch
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "6. ОБЩИЙ ОБРАБОТЧИК exception" << endl;
    cout << "========================================" << endl;

    try
    {
        // Специально генерируем исключение
        throw runtime_error(
            "Демонстрационная ошибка."
        );
    }
    catch (const out_of_range& error)
    {
        cout << "out_of_range: "
             << error.what()
             << endl;
    }
    catch (const invalid_argument& error)
    {
        cout << "invalid_argument: "
             << error.what()
             << endl;
    }
    catch (const exception& error)
    {
        cout << "Общий обработчик exception." << endl;
        cout << "Сообщение: "
             << error.what()
             << endl;
    }


    // ========================================
    // ЗАВЕРШЕНИЕ
    // ========================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "       ПРОГРАММА ЗАВЕРШЕНА" << endl;
    cout << "========================================" << endl;

    return 0;
}