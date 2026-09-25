#include "List.h"
#include <stdexcept>

using namespace std;

// Создаёт пустой список.
List::List()
{
    head = nullptr;
    size = 0;
}

// Глубокая копия списка: создаются новые узлы.
List::List(const List& other)
{
    head = nullptr;
    size = 0;

    Node* current = other.head;

    while (current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }
}

List::List(List&& other) {
    head = other.head;
    size = other.size;

    other.head = nullptr;
    other.size = 0;
}

List::~List()
{
    clear();
}

// Добавляет символ в конец списка.
void List::pushBack(char value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    size++;
}

// Освобождает все узлы списка.
void List::clear()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    size = 0;
}

void List::Input()
{
    clear();

    char value;

    cout << "Введите символы списка." << endl;
    cout << "Для окончания ввода введите #." << endl;

    while (true)
    {
        cin >> value;

        if (value == '#')
               break;

        pushBack(value);
    }
}

void List::Print() const
{
    Node* current = head;

    cout << "[";

    while (current != nullptr)
    {
        cout << current->data;

        if (current->next != nullptr)
            cout << " -> ";

        current = current->next;
    }

    cout << "]" << endl;
}

// Глубокое присваивание с защитой от A = A.
/*
List& List::operator=(const List& other)
{
    if (this == &other)
        return *this;

    clear();

    Node* current = other.head;

    while (current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
}

*/

List& List::operator=(List&& other)
{
    if (this != &other)
    {
        clear();

        head = other.head;
        size = other.size;

        other.head = nullptr;
        other.size = 0;
    }

    return *this;
}

// Возвращает ссылку на символ в заданной позиции.
char& List::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range(
            "Индекс находится за пределами списка."
        );
    }

    Node* current = head;

    for (int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}

// Вариант 11: объединение двух списков.
List List::operator+(const List& other) const
{
    List result(*this);

    Node* current = other.head;

    while (current != nullptr)
    {
        result.pushBack(current->data);
        current = current->next;
    }

    return result;
}

// Вариант 11: проверка списков на неравенство.
bool List::operator!=(const List& other) const
{
    if (size != other.size)
        return true;

    /*List first(*this);
    List second(other);

    //Node* firstNode = first.head;
    Node* secondNode = second.head;

    while (firstNode != nullptr)
    {
        if (firstNode->data != secondNode->data)
            return true;

        firstNode = firstNode->next;
        secondNode = secondNode->next;
    } */

    auto first = head;
    auto second = other.head;

    while (first != nullptr)
    {
        if (first->data != second->data)
            return true;

        first = first->next;
        second = second->next;
    }

    return false;
}

// Возвращает количество элементов списка.
int List::GetSize() const
{
    return size;
}
