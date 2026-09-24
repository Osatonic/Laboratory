#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

using namespace std;

// =====================================================
// Общий абстрактный объект для ЛР3 и дополнительной ЛР4
// =====================================================

class TObject
{
public:
    virtual void Show() = 0;
    virtual ~TObject() {}
};


// =====================================================
// Узел общего списка объектов ЛР3
// =====================================================

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


// =====================================================
// БАЗОВЫЙ КЛАСС "ТРАНСПОРТНОЕ СРЕДСТВО"
// =====================================================

class Transport : public TObject
{
protected:
    string name;
    int speed;

    static Node* begin;

public:
    Transport(string n = "", int s = 0, bool autoAdd = false);

    virtual ~Transport();

    void Show() override = 0;

    void Add();

    static void PrintList();

    void Remove();
};


// =====================================================
// АВТОМОБИЛЬ
// =====================================================

class Car : public Transport
{
protected:
    int doors;

public:
    Car(string n = "", int s = 0, int d = 0, bool autoAdd = false);

    void Show() override;
};


// =====================================================
// ПОЕЗД
// =====================================================

class Train : public Transport
{
protected:
    int wagons;

public:
    Train(string n = "", int s = 0, int w = 0, bool autoAdd = false);

    void Show() override;
};


// =====================================================
// ЭКСПРЕСС
// =====================================================

class Express : public Train
{
protected:
    bool highSpeed;

public:
    Express(
        string n = "",
        int s = 0,
        int w = 0,
        bool hs = false,
        bool autoAdd = false
    );

    void Show() override;
};

#endif