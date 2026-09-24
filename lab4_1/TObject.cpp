#include "TObject.h"


// =====================================================
// TTransport
// =====================================================

TTransport::TTransport(const char* NAME)
{
    strcpy(name, NAME);
}


const char* TTransport::GetName()
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


const char* TDetail::GetName()
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

    // Вначале группа пустая
    last = nullptr;
}


// =====================================================
// ДЕСТРУКТОР ГРУППЫ
// =====================================================

TGroup::~TGroup()
{
    TItem* current = last;

    while (current != nullptr)
    {
        TItem* next = current->next;

        delete current;

        current = next;
    }

    last = nullptr;
}


// =====================================================
// ПОЛУЧИТЬ НАЗВАНИЕ ГРУППЫ
// =====================================================

const char* TGroup::GetName()
{
    return name;
}


// =====================================================
// ДОБАВИТЬ ОБЪЕКТ В ГРУППУ
// =====================================================

void TGroup::Insert(TObject* p)
{
    TItem* newItem = new TItem(p);

    newItem->next = last;

    last = newItem;
}


// =====================================================
// ПРОВЕРИТЬ, ПУСТА ЛИ ГРУППА
// =====================================================

bool TGroup::Empty()
{
    return last == nullptr;
}


// =====================================================
// ПОКАЗАТЬ ВСЕ ОБЪЕКТЫ
// =====================================================

void TGroup::ShowItems()
{
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
// ИТЕРАТОР УЗЛА
// =====================================================

void TNode::ForEach()
{
    TItem* current = last;

    while (current != nullptr)
    {
        PrintName(current->item);

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
// ИТЕРАТОР МЕХАНИЗМА
// =====================================================

void TMechanism::ForEach()
{
    TItem* current = last;

    while (current != nullptr)
    {
        PrintName(current->item);

        current = current->next;
    }
}


// =====================================================
// ФУНКЦИЯ ВАРИАНТА №11
// =====================================================

void PrintName(TObject* p)
{
    TDetail* detail =
        dynamic_cast<TDetail*>(p);

    if (detail != nullptr)
    {
        cout << detail->GetName() << endl;

        return;
    }


    TGroup* group =
        dynamic_cast<TGroup*>(p);

    if (group != nullptr)
    {
        cout << group->GetName() << endl;

        return;
    }


    TTransport* transport =
        dynamic_cast<TTransport*>(p);

    if (transport != nullptr)
    {
        cout << transport->GetName() << endl;
    }
}