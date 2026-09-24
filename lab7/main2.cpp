#include <iostream>
#include <fstream>

#include "TransportFile.h"
#include "Manipulator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const char* fileName = "transport.dat";

    ifstream in(fileName, ios::binary);

    if (!in)
    {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    in.seekg(0, ios::end);
    long fileSize = in.tellg();
    in.seekg(0, ios::beg);

    int count = fileSize / sizeof(TransportFile);

    cout << "Размер файла: " << fileSize << " байт" << endl;
    cout << "Количество объектов: " << count << endl;

    if (count == 0)
    {
        cout << "Файл пуст." << endl;
        in.close();
        return 0;
    }

    TransportFile* objects = new TransportFile[count];

    for (int i = 0; i < count; i++)
    {
        in.read(
            reinterpret_cast<char*>(&objects[i]),
            sizeof(TransportFile)
        );
    }

    cout << "\n=== ОБЪЕКТЫ ИЗ ФАЙЛА ===" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\n";
        cout << mymanip(40, '=') << endl;
        cout << "Объект №" << i + 1 << endl;
        cout << objects[i] << endl;
    }

    cout << "\n=== СОСТОЯНИЕ ПОТОКА ===" << endl;

    if (in.good())
        cout << "Поток находится в хорошем состоянии." << endl;
    else
        cout << "При чтении возникла проблема." << endl;

    in.close();
    delete[] objects;

    return 0;
}
