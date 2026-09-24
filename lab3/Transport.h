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

    // Начало общего списка объектов
    static Node* begin;

public:
    Transport(string n, int s);
    virtual ~Transport();

    // Чистая виртуальная функция
    virtual void Show() = 0;

    // Добавление объекта в список
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
    Car(string n, int s, int d);

    void Show() override;
};


// Поезд
class Train : public Transport
{
protected:
    int wagons;

public:
    Train(string n, int s, int w);

    void Show() override;
};


// Экспресс наследуется от поезда
class Express : public Train
{
protected:
    bool highSpeed;

public:
    Express(string n, int s, int w, bool hs);

    void Show() override;
};

#endif