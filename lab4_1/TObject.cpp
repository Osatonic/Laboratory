#include "TObject.h"


// =====================================================
// TTransport
// =====================================================

TTransport::TTransport(const char* NAME)
{
    strcpy(name, NAME);
}


const char* TTransport::GetName() const
{
    return name;
}


// =====================================================
// TCar
// =====================================================

TCar::TCar(const char* NAME, int WHEELS)
    : TTransport(NAME)
{
    wheels = WHEELS;
}


void TCar::Show()
{
    cout << "Автомобиль: "
         << name
         << ", колёс: "
         << wheels
         << endl;
}


// =====================================================
// TTrain
// =====================================================

TTrain::TTrain(const char* NAME, int WAGONS)
    : TTransport(NAME)
{
    wagons = WAGONS;
}


void TTrain::Show()
{
    cout << "Поезд: "
         << name
         << ", вагонов: "
         << wagons
         << endl;
}


// =====================================================
// TExpress
// =====================================================

TExpress::TExpress(
    const char* NAME,
    int WAGONS,
    int SPEED
)
    : TTrain(NAME, WAGONS)
{
    speed = SPEED;
}


void TExpress::Show()
{
    cout << "Экспресс: "
         << name
         << ", вагонов: "
         << wagons
         << ", скорость: "
         << speed
         << " км/ч"
         << endl;
}


// =====================================================
// TDetail
// =====================================================

TDetail::TDetail(const char* NAME)
{
    strcpy(name, NAME);
}


const char* TDetail::GetName() const
{
    return name;
}


void TDetail::Show()
{
    cout << "Деталь: "
         << name
         << endl;
}


// =====================================================
// TGroup
// =====================================================

TGroup::TGroup(const char* NAME)
{
    strcpy(name, NAME);

    // Изначально группа пустая
    last = nullptr;
}


// =====================================================
// ДЕСТРУКТОР TGroup
// =====================================================

TGroup::~TGroup()
{
    TItem* current = last;

    while (current != nullptr)
    {
        TItem* next = current->next;

        // Удаляем только элемент списка.
        // Сам объект НЕ удаляем.
        delete current;

        current = next;
    }

    last = nullptr;
}


// =====================================================
// GET NAME
// =====================================================

const char* TGroup::GetName() const
{
    return name;
}


// =====================================================
// INSERT
// =====================================================

void TGroup::Insert(TObject* p)
{
    if (p == nullptr)
    {
        return;
    }

    TItem* newItem = new TItem(p);

    // Добавляем элемент в начало списка
    newItem->next = last;

    last = newItem;
}


// =====================================================
// EMPTY
// =====================================================

bool TGroup::Empty() const
{
    return last == nullptr;
}


// =====================================================
// SHOW ITEMS
// =====================================================

void TGroup::ShowItems() const
{
    if (Empty())
    {
        cout << "Группа пуста." << endl;
        return;
    }

    TItem* current = last;

    while (current != nullptr)
    {
        current->item->Show();

        current = current->next;
    }
}


// =====================================================
// TNode
// =====================================================

TNode::TNode(const char* NAME)
    : TGroup(NAME)
{
}


void TNode::Show()
{
    cout << "Узел: "
         << name
         << endl;
}


// =====================================================
// ИТЕРАТОР TNode
// =====================================================

void TNode::ForEach(PF action)
{
    if (action == nullptr)
    {
        return;
    }

    TItem* current = last;

    while (current != nullptr)
    {
        // Выполняем переданную функцию
        // для текущего объекта
        action(current->item);

        current = current->next;
    }
}


// =====================================================
// TMechanism
// =====================================================

TMechanism::TMechanism(const char* NAME)
    : TGroup(NAME)
{
}


void TMechanism::Show()
{
    cout << "Механизм: "
         << name
         << endl;
}


// =====================================================
// ИТЕРАТОР TMechanism
// =====================================================

void TMechanism::ForEach(PF action)
{
    if (action == nullptr)
    {
        return;
    }

    TItem* current = last;

    while (current != nullptr)
    {
        // Выполняем переданную функцию
        // для текущего объекта
        action(current->item);

        current = current->next;
    }
}


// =====================================================
// ФУНКЦИЯ ВАРИАНТА №11
// =====================================================

void PrintName(TObject* p)
{
    if (p == nullptr)
    {
        return;
    }


    // ================================================
    // Если это деталь
    // ================================================

    TDetail* detail =
        dynamic_cast<TDetail*>(p);

    if (detail != nullptr)
    {
        cout << detail->GetName() << endl;

        return;
    }


    // ================================================
    // Если это группа
    // ================================================

    TGroup* group =
        dynamic_cast<TGroup*>(p);

    if (group != nullptr)
    {
        cout << group->GetName() << endl;

        return;
    }


    // ================================================
    // Если это транспорт
    // ================================================

    TTransport* transport =
        dynamic_cast<TTransport*>(p);

    if (transport != nullptr)
    {
        cout << transport->GetName() << endl;

        return;
    }
}