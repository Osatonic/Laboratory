#include <iostream>
#include <fstream>

#include "TransportFile.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Программа №1: создаём бинарный файл и записываем минимум 5 объектов.
    const char* fileName = "transport.dat";

    ofstream out(fileName, ios::binary);

    if (!out)
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    cout << "=== СОЗДАНИЕ ФАЙЛА ===" << endl;

    int count;

    cout << "Сколько объектов записать? ";
    cin >> count;

    if (count < 5)
    {
        cout << "По условию необходимо записать минимум 5 объектов."
             << endl;
        count = 5;
    }

    for (int i = 0; i < count; i++)
    {
        TransportFile object;

        cout << "\nОбъект №" << i + 1 << endl;

        cin >> object;

        cout << "Введено: " << object << endl;

        out.write(
            reinterpret_cast<const char*>(&object),
            sizeof(TransportFile)
        );
    }

    out.close();

    ifstream in(fileName, ios::binary);

    if (!in)
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    in.seekg(0, ios::end);

    long fileSize = in.tellg();

    in.close();

    int objectCount = fileSize / sizeof(TransportFile);

    cout << "\n================================" << endl;
    cout << "Количество объектов: "
         << objectCount << endl;
    cout << "Размер файла: "
         << fileSize << " байт" << endl;
    cout << "Размер одного объекта: "
         << sizeof(TransportFile) << " байт" << endl;
    cout << "================================" << endl;

    return 0;
}
