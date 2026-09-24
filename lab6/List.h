#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

class List
{
private:

    // Один элемент списка
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

    // Первый элемент списка
    Node* head;

    // Количество элементов
    int size;

    // Добавление элемента в конец
    void pushBack(char value);

    // Удаление всех элементов
    void clear();

public:

    // Конструктор
    List();

    // Конструктор копирования
    List(const List& other);

    // Деструктор
    ~List();

    // Ввод списка
    void Input();

    // Вывод списка
    void Print() const;

    // Оператор присваивания
    List& operator=(const List& other);

    // Оператор []
    char& operator[](int index);

    // Оператор +
    List operator+(const List& other) const;

    // Оператор !=
    bool operator!=(const List& other) const;

    // Получить количество элементов
    int GetSize() const;

    // Получить первый элемент
    char& Front();

    // Удалить элемент по индексу
    void RemoveAt(int index);
};

#endif