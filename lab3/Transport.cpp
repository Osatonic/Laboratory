#include "Transport.h"

using namespace std;


// Инициализация статического указателя
Node* Transport::begin = nullptr;


// Конструктор Transport
Transport::Transport(string n, int s)
{
    name = n;
    speed = s;
}


// Деструктор
Transport::~Transport()
{
    Remove();
}


// Добавление объекта в список
void Transport::Add()
{
    Node* newNode = new Node(this);

    newNode->next = begin;
    begin = newNode;
}


// Удаление объекта из списка
void Transport::Remove()
{
    Node* current = begin;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->object == this)
        {
            if (previous == nullptr)
            {
                begin = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}


// Просмотр списка
void Transport::PrintList()
{
    Node* current = begin;

    cout << "\n===== LIST =====\n";

    while (current != nullptr)
    {
        current->object->Show();
        current = current->next;
    }

    cout << "================\n";
}


// Конструктор автомобиля
Car::Car(string n, int s, int d)
    : Transport(n, s)
{
    doors = d;
}


// Вывод автомобиля
void Car::Show()
{
    cout << "Car: "
         << name
         << ", speed = " << speed
         << ", doors = " << doors
         << endl;
}


// Конструктор поезда
Train::Train(string n, int s, int w)
    : Transport(n, s)
{
    wagons = w;
}


// Вывод поезда
void Train::Show()
{
    cout << "Train: "
         << name
         << ", speed = " << speed
         << ", wagons = " << wagons
         << endl;
}


// Конструктор экспресса
Express::Express(string n, int s, int w, bool hs)
    : Train(n, s, w)
{
    highSpeed = hs;
}


// Вывод экспресса
void Express::Show()
{
    cout << "Express: "
         << name
         << ", speed = " << speed
         << ", wagons = " << wagons
         << ", high speed = ";

    if (highSpeed)
        cout << "yes";
    else
        cout << "no";

    cout << endl;
}