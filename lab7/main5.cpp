#include <iostream>
#include <fstream>
#include <cstring>

#include "TransportFile.h"

using namespace std;

// Ищем запись перед её заменой.
long find(fstream& file, const char* key)
{
    TransportFile object;

    file.clear();
    file.seekg(0, ios::beg);

    long position = 0;

    while (file.read(
        reinterpret_cast<char*>(&object),
        sizeof(TransportFile)))
    {
        if (strcmp(object.GetName(), key) == 0)
            return position;

        position += sizeof(TransportFile);
    }

    return -1;
}

void repl(
    fstream& file,
    long position,
    const TransportFile& newObject)
{
    file.clear();

    file.seekp(position, ios::beg);

    file.write(
        reinterpret_cast<const char*>(&newObject),
        sizeof(TransportFile)
    );

    file.flush();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const char* fileName = "transport.dat";

    fstream file(
        fileName,
        ios::in | ios::out | ios::binary
    );

    if (!file)
    {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    char key[50];

    cout << "Введите название транспорта для изменения: ";
    cin >> key;

    long position = find(file, key);

    if (position == -1)
    {
        cout << "Объект не найден." << endl;
        file.close();
        return 0;
    }

    cout << "\nОбъект найден." << endl;
    cout << "Смещение: " << position << " байт" << endl;

    TransportFile newObject;

    cout << "\nВведите новые данные:" << endl;
    cin >> newObject;

    repl(file, position, newObject);

    cout << "\nОбъект успешно изменён." << endl;

    file.close();

    return 0;
}
