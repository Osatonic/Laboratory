#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

using namespace std;


// Узел связанного списка
struct Node
{
    class Transport* object;
    Node* next;

    Node(Transport* obj)
    {
        object = obj;
        next = nullptr;
    }
};


// Базовый абстрактный класс
class Transport
{
protected:
    string name;
    int speed;

    // Указатель на начало общего списка
    static Node* begin;

public:
    // Конструктор.
    // autoAdd = true означает автоматическое добавление в список.
    Transport(string n = "", int s = 0, bool autoAdd = false);

    // Виртуальный деструктор
    virtual ~Transport();

    // Чистая виртуальная функция
    virtual void Show() = 0;

    // Ручное добавление объекта в список
    void Add();

    // Просмотр всего списка
    static void PrintList();

    // Удаление объекта из списка
    void Remove();
};


// Автомобиль
class Car : public Transport
{
protected:
    int doors;

public:
    Car(string n = "", int s = 0, int d = 0, bool autoAdd = false);

    void Show() override;
};


// Поезд
class Train : public Transport
{
protected:
    int wagons;

public:
    Train(string n = "", int s = 0, int w = 0, bool autoAdd = false);

    void Show() override;
};


// Экспресс наследуется от поезда
class Express : public Train
{
protected:
    bool highSpeed;

public:
    Express(string n = "", int s = 0, int w = 0,
            bool hs = false, bool autoAdd = false);

    void Show() override;
};

#endif