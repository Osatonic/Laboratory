#include <iostream>
#include <fstream>
#include <streambuf>
#include <cstring>
#include <cstdio>

#include "TransportFile.h"

using namespace std;

// Ищем запись по ключевому полю и возвращаем её смещение.
long find(istream& file, const char* key)
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

void del(const char* fileName, long position)
{
    ifstream in(fileName, ios::binary);

    if (!in)
    {
        cout << "Ошибка открытия исходного файла!" << endl;
        return;
    }

    ofstream out("temp.dat", ios::binary);

    if (!out)
    {
        cout << "Ошибка создания временного файла!" << endl;
        in.close();
        return;
    }

    TransportFile object;
    long currentPosition = 0;

    while (in.read(
        reinterpret_cast<char*>(&object),
        sizeof(TransportFile)))
    {
        if (currentPosition != position)
        {
            out.write(
                reinterpret_cast<const char*>(&object),
                sizeof(TransportFile)
            );
        }

        currentPosition += sizeof(TransportFile);
    }

    in.close();
    out.close();

    remove(fileName);
    rename("temp.dat", fileName);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const char* fileName = "transport.dat";
    char key[50];

    cout << "Введите название транспорта для удаления: ";
    cin >> key;

    // Третий способ: отдельно открываем filebuf и связываем его с istream.
    filebuf buffer;
    if (!buffer.open(fileName, ios::in | ios::binary))
    {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    istream file(&buffer);
    long position = find(file, key);
    buffer.close();

    if (position == -1)
    {
        cout << "Объект не найден." << endl;
        return 0;
    }

    cout << "Объект найден." << endl;
    cout << "Смещение от начала файла: "
         << position << " байт" << endl;

    del(fileName, position);

    cout << "Объект удалён." << endl;

    return 0;
}
