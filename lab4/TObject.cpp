#include "TObject.h"


// ==================================================
// TGroup
// ==================================================

TGroup::TGroup(string n)
{
    name = n;
    last = nullptr;
}


// ==================================================
// Деструктор группы
// ==================================================

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


// ==================================================
// Получить название
// ==================================================

string TGroup::GetName()
{
    return name;
}


// ==================================================
// Добавить объект в группу
// ==================================================

void TGroup::Insert(TObject* p)
{
    TItem* newItem = new TItem(p);

    newItem->next = last;

    last = newItem;
}


// ==================================================
// Проверка: пустая ли группа
// ==================================================

bool TGroup::Empty()
{
    return last == nullptr;
}


// ==================================================
// Показать все элементы группы
// ==================================================

void TGroup::ShowItems()
{
    TItem* current = last;

    while (current != nullptr)
    {
        current->item->Show();

        current = current->next;
    }
}


// ==================================================
// TDetail
// ==================================================

TDetail::TDetail(string n)
{
    name = n;
}


string TDetail::GetName()
{
    return name;
}


void TDetail::Show()
{
    cout << "Деталь: " << name << endl;
}


// ==================================================
// TNode
// ==================================================

TNode::TNode(string n)
    : TGroup(n)
{
}


void TNode::Show()
{
    cout << "Узел: " << name << endl;
}


void TNode::ForEach()
{
    TItem* current = last;

    while (current != nullptr)
    {
        PrintName(current->item);

        current = current->next;
    }
}


// ==================================================
// TMechanism
// ==================================================

TMechanism::TMechanism(string n)
    : TGroup(n)
{
}


void TMechanism::Show()
{
    cout << "Механизм: " << name << endl;
}


void TMechanism::ForEach()
{
    TItem* current = last;

    while (current != nullptr)
    {
        PrintName(current->item);

        current = current->next;
    }
}


// ==================================================
// Функция варианта №11
// ==================================================

void PrintName(TObject* p)
{
    if (TDetail* detail = dynamic_cast<TDetail*>(p))
    {
        cout << detail->GetName() << endl;
    }
    else if (TGroup* group = dynamic_cast<TGroup*>(p))
    {
        cout << group->GetName() << endl;
    }
}