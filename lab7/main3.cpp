#include <iostream>
#include <fstream>

#include "TransportFile.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Программа №3: добавляем новые записи в конец файла.
    const char* fileName = "transport.dat";

    ofstream out;
    out.open(fileName, ios::binary | ios::app);

    if (!out)
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int count;

    cout << "Сколько объектов добавить? ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        TransportFile object;

        cout << "\nНовый объект №" << i + 1 << endl;

        cin >> object;

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
    int objectCount = fileSize / sizeof(TransportFile);

    in.close();

    cout << "\nПосле добавления:" << endl;
    cout << "Количество объектов: " << objectCount << endl;
    cout << "Размер файла: " << fileSize << " байт" << endl;

    return 0;
}
