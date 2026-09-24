#ifndef TOBJECT_H
#define TOBJECT_H

#include <iostream>
#include <string>

using namespace std;


// ==================================================
// Базовый абстрактный класс
// ==================================================

class TObject
{
public:
    virtual void Show() = 0;

    virtual ~TObject() {}
};


// ==================================================
// Элемент связанного списка
// ==================================================

struct TItem
{
    TObject* item;
    TItem* next;

    TItem(TObject* p)
    {
        item = p;
        next = nullptr;
    }
};


// ==================================================
// Абстрактный класс-группа
// ==================================================

class TGroup : public TObject
{
protected:
    string name;
    TItem* last;

public:
    TGroup(string n);

    virtual ~TGroup();

    string GetName();

    void Insert(TObject* p);

    bool Empty();

    void ShowItems();

    virtual void ForEach() = 0;
};


// ==================================================
// Деталь
// ==================================================

class TDetail : public TObject
{
protected:
    string name;

public:
    TDetail(string n);

    string GetName();

    void Show() override;
};


// ==================================================
// Узел
// ==================================================

class TNode : public TGroup
{
public:
    TNode(string n);

    void Show() override;

    void ForEach() override;
};


// ==================================================
// Механизм
// ==================================================

class TMechanism : public TGroup
{
public:
    TMechanism(string n);

    void Show() override;

    void ForEach() override;
};


// ==================================================
// Функция для нашего варианта №11
// ==================================================

void PrintName(TObject* p);

#endif