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

    // Если список пуст
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        // Идём до последнего элемента
        while (current->next != nullptr)
        {
            current = current->next;
        }

        // Последний элемент теперь указывает на новый
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
    // Защита от A = A
    if (this == &other)
    {
        return *this;
    }

    // Удаляем старые данные
    clear();

    // Копируем новый список
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
    if (index < 0 || index >= size)
    {
        throw out_of_range("Индекс находится за пределами списка.");
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

    // Копируем первый список
    while (current != nullptr)
    {
        result.pushBack(current->data);

        current = current->next;
    }

    current = other.head;

    // Добавляем второй список
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
    // Если размеры разные,
    // списки точно не равны
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