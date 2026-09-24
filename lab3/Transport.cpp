#include "Transport.h"

using namespace std;


// Инициализация статического указателя
Node* Transport::begin = nullptr;


// Конструктор базового класса
Transport::Transport(string n, int s, bool autoAdd)
{
    name = n;
    speed = s;

    cout << "Transport constructor: " << name << endl;

    // Автоматическое добавление в список
    if (autoAdd)
    {
        Add();
    }
}


// Виртуальный деструктор
Transport::~Transport()
{
    cout << "Transport destructor: " << name << endl;

    // Удаляем объект из списка
    Remove();
}


// Ручное добавление объекта в список
void Transport::Add()
{
    Node* newNode = new Node(this);

    // Добавляем в начало списка
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
        // Нашли объект
        if (current->object == this)
        {
            // Если это первый элемент
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

    cout << "\n=================================\n";
    cout << "        TRANSPORT LIST\n";
    cout << "=================================\n";

    while (current != nullptr)
    {
        // Благодаря virtual здесь вызывается
        // Show() именно нужного класса
        current->object->Show();

        current = current->next;
    }

    cout << "=================================\n";
}


// ================================
// Car
// ================================

Car::Car(string n, int s, int d, bool autoAdd)
    : Transport(n, s, autoAdd)
{
    doors = d;

    cout << "Car constructor: " << name << endl;
}


void Car::Show()
{
    cout << "Car: "
         << "name = " << name
         << ", speed = " << speed
         << ", doors = " << doors
         << endl;
}


// ================================
// Train
// ================================

Train::Train(string n, int s, int w, bool autoAdd)
    : Transport(n, s, autoAdd)
{
    wagons = w;

    cout << "Train constructor: " << name << endl;
}


void Train::Show()
{
    cout << "Train: "
         << "name = " << name
         << ", speed = " << speed
         << ", wagons = " << wagons
         << endl;
}


// ================================
// Express
// ================================

Express::Express(string n, int s, int w,
                 bool hs, bool autoAdd)
    : Train(n, s, w, autoAdd)
{
    highSpeed = hs;

    cout << "Express constructor: " << name << endl;
}


void Express::Show()
{
    cout << "Express: "
         << "name = " << name
         << ", speed = " << speed
         << ", wagons = " << wagons
         << ", high speed = ";

    if (highSpeed)
        cout << "yes";
    else
        cout << "no";

    cout << endl;
}