#include "List.h"

using namespace std;


// ============================================
// КОНСТРУКТОР
// ============================================

List::List()
{
    head = nullptr;
    size = 0;
}


// ============================================
// КОНСТРУКТОР КОПИРОВАНИЯ
// ============================================

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


// ============================================
// ДЕСТРУКТОР
// ============================================

List::~List()
{
    clear();
}


// ============================================
// ДОБАВЛЕНИЕ В КОНЕЦ
// ============================================

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


// ============================================
// УДАЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ
// ============================================

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


// ============================================
// ВВОД
// ============================================

void List::Input()
{
    clear();

    char value;

    cout << "Введите символы списка." << endl;
    cout << "Для окончания ввода введите #." << endl;

    while (true)
    {
        cin >> value;

        // Если произошла ошибка ввода
        if (cin.fail())
        {
            throw runtime_error(
                "Ошибка ввода данных."
            );
        }

        if (value == '#')
        {
            break;
        }

        pushBack(value);
    }
}


// ============================================
// ВЫВОД
// ============================================

void List::Print() const
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


// ============================================
// ОПЕРАТОР ПРИСВАИВАНИЯ
// ============================================

List& List::operator=(const List& other)
{
    if (this == &other)
    {
        return *this;
    }

    clear();

    Node* current = other.head;

    while (current != nullptr)
    {
        pushBack(current->data);

        current = current->next;
    }

    return *this;
}


// ============================================
// ОПЕРАТОР []
// ============================================

char& List::operator[](int index)
{
    // Проверяем границы массива/списка
    if (index < 0 || index >= size)
    {
        throw out_of_range(
            "Индекс находится за пределами списка."
        );
    }

    Node* current = head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}


// ============================================
// ОПЕРАТОР +
// ============================================

List List::operator+(const List& other) const
{
    List result;

    Node* current = head;

    while (current != nullptr)
    {
        result.pushBack(current->data);

        current = current->next;
    }

    current = other.head;

    while (current != nullptr)
    {
        result.pushBack(current->data);

        current = current->next;
    }

    return result;
}


// ============================================
// ОПЕРАТОР !=
// ============================================

bool List::operator!=(const List& other) const
{
    if (size != other.size)
    {
        return true;
    }

    Node* first = head;
    Node* second = other.head;

    while (first != nullptr)
    {
        if (first->data != second->data)
        {
            return true;
        }

        first = first->next;
        second = second->next;
    }

    return false;
}


// ============================================
// ПОЛУЧИТЬ РАЗМЕР
// ============================================

int List::GetSize() const
{
    return size;
}


// ============================================
// ПОЛУЧИТЬ ПЕРВЫЙ ЭЛЕМЕНТ
// ============================================

char& List::Front()
{
    if (head == nullptr)
    {
        throw out_of_range(
            "Нельзя получить первый элемент пустого списка."
        );
    }

    return head->data;
}


// ============================================
// УДАЛЕНИЕ ПО ИНДЕКСУ
// ============================================

void List::RemoveAt(int index)
{
    // Проверка индекса
    if (index < 0 || index >= size)
    {
        throw out_of_range(
            "Невозможно удалить элемент: "
            "индекс находится за пределами списка."
        );
    }

    // Удаление первого элемента
    if (index == 0)
    {
        Node* oldHead = head;

        head = head->next;

        delete oldHead;

        size--;

        return;
    }

    // Поиск предыдущего элемента
    Node* current = head;

    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    Node* nodeToDelete = current->next;

    current->next = nodeToDelete->next;

    delete nodeToDelete;

    size--;
}