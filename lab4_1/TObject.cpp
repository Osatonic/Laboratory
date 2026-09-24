#include "TObject.h"


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
    cout << "Деталь: " << name << endl;
}


// =====================================================
// TGroup
// =====================================================

TGroup::TGroup(const char* NAME)
{
    strcpy(name, NAME);
    last = nullptr;
}


TGroup::~TGroup()
{
    TItem* current = last;

    while (current != nullptr)
    {
        TItem* next = current->next;

        // Группа не владеет объектами.
        // Она удаляет только элементы служебного списка.
        delete current;

        current = next;
    }

    last = nullptr;
}


const char* TGroup::GetName() const
{
    return name;
}


void TGroup::Insert(TObject* p)
{
    if (p == nullptr)
    {
        return;
    }

    TItem* newItem = new TItem(p);

    newItem->next = last;
    last = newItem;
}


bool TGroup::Empty() const
{
    return last == nullptr;
}


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
    cout << "Узел: " << name << endl;
}


void TNode::ForEach(PF action)
{
    if (action == nullptr)
    {
        return;
    }

    TItem* current = last;

    while (current != nullptr)
    {
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
    cout << "Механизм: " << name << endl;
}


void TMechanism::ForEach(PF action)
{
    if (action == nullptr)
    {
        return;
    }

    TItem* current = last;

    while (current != nullptr)
    {
        action(current->item);
        current = current->next;
    }
}


// =====================================================
// ВАРИАНТ №11
// =====================================================

void PrintName(TObject* p)
{
    if (p == nullptr)
    {
        return;
    }

    // Для деталей выводим название детали.
    TDetail* detail = dynamic_cast<TDetail*>(p);

    if (detail != nullptr)
    {
        cout << detail->GetName() << endl;
        return;
    }

    // Для узлов/механизмов выводим название группы.
    TGroup* group = dynamic_cast<TGroup*>(p);

    if (group != nullptr)
    {
        cout << group->GetName() << endl;
        return;
    }

    // Для объектов из ЛР3 (Car/Train/Express)
    // используем их общий базовый класс Transport.
    Transport* transport = dynamic_cast<Transport*>(p);

    if (transport != nullptr)
    {
        cout << "Транспорт: " << transport->GetName() << endl;
    }
}