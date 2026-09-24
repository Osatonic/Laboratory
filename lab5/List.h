#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;


template <class T>
class List
{
private:

    // =========================================
    // Узел списка
    // =========================================

    struct Node
    {
        T data;
        Node* next;

        Node(const T& value)
        {
            data = value;
            next = nullptr;
        }
    };


    // Первый элемент списка
    Node* head;

    // Количество элементов
    int size;


    // =========================================
    // Очистка списка
    // =========================================

    void clear()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* next = current->next;

            delete current;

            current = next;
        }

        head = nullptr;
        size = 0;
    }


public:

    // =========================================
    // Конструктор
    // =========================================

    List()
    {
        head = nullptr;
        size = 0;
    }


    // =========================================
    // Конструктор копирования
    // =========================================

    List(const List& other)
    {
        head = nullptr;
        size = 0;

        Node* current = other.head;

        while (current != nullptr)
        {
            addToEnd(current->data);

            current = current->next;
        }
    }


    // =========================================
    // Деструктор
    // =========================================

    ~List()
    {
        clear();
    }


    // =========================================
    // Добавление в конец
    // Вспомогательная функция
    // =========================================

    void addToEnd(const T& value)
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


    // =========================================
    // Ввод списка
    // =========================================

    void Input()
    {
        clear();

        int n;

        cout << "Введите количество элементов: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            T value;

            cout << "Введите элемент "
                 << i + 1
                 << ": ";

            cin >> value;

            addToEnd(value);
        }
    }


    // =========================================
    // Вывод списка
    // =========================================

    void Print() const
    {
        Node* current = head;

        cout << "[";

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << "]" << endl;
    }


    // =========================================
    // Оператор присваивания
    // =========================================

    List& operator=(const List& other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();

        Node* current = other.head;

        while (current != nullptr)
        {
            addToEnd(current->data);

            current = current->next;
        }

        return *this;
    }


    // =========================================
    // ВАРИАНТ №11
    //
    // + — добавить элемент в начало
    // =========================================

    List operator+(const T& value) const
    {
        List result(*this);

        Node* newNode = new Node(value);

        newNode->next = result.head;

        result.head = newNode;

        result.size++;

        return result;
    }


    // =========================================
    // ВАРИАНТ №11
    //
    // -- — удалить элемент из начала
    // =========================================

    List& operator--()
    {
        if (head != nullptr)
        {
            Node* oldHead = head;

            head = head->next;

            delete oldHead;

            size--;
        }

        return *this;
    }


    // =========================================
    // ВАРИАНТ №11
    //
    // == — проверка на равенство
    // =========================================

    bool operator==(const List& other) const
    {
        if (size != other.size)
        {
            return false;
        }

        Node* first = head;
        Node* second = other.head;

        while (first != nullptr)
        {
            if (!(first->data == second->data))
            {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }


    // =========================================
    // Дополнительная функция
    // =========================================

    int getSize() const
    {
        return size;
    }
};

#endif