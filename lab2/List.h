#ifndef LIST_H
#define LIST_H

#include <iostream>

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

    // Указатель на первый элемент
    Node* head;

    // Количество элементов
    int size;

    // Вспомогательная функция добавления элемента
    void pushBack(char value);

    // Удаление всех элементов
    void clear();

public:

    // Конструктор без параметров
    List();

    // Конструктор копирования
    List(const List& other);

    // Деструктор
    ~List();

    // Ввод
    void Input();

    // Вывод
    void Print() const;

    // Перегрузка присваивания
    List& operator=(const List& other);

    // Перегрузка []
    char& operator[](int index);

    // Перегрузка +
    List operator+(const List& other) const;

    // Перегрузка !=
    bool operator!=(const List& other) const;
};

#endif