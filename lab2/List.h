#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

class List
{
private:
    struct Node
    {
        char data;
        Node* next;

        Node(char value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    int size;

    void pushBack(char value);
    void clear();

public:
    List();
    List(const List& other);
    List(List&& other);
    ~List();

    void Input();
    void Print() const;

    //List& operator=(const List& other);
    List& operator=(List&& other);

    // Доступ к элементу списка по индексу.
    char& operator[](int index);

    // Объединение двух списков.
    List operator+(const List& other) const;

    // Проверка списков на неравенство.
    bool operator!=(const List& other) const;
    int GetSize() const;
};

#endif
