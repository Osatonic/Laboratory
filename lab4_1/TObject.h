#ifndef TOBJECT_H
#define TOBJECT_H

#include <iostream>
#include <cstring>

// В ЛР4_1 используется ИМЕННО иерархия транспорта из ЛР3.
#include "../lab3/Transport.h"

using namespace std;


// =====================================================
// ДЕТАЛЬ
// =====================================================

class TDetail : public TObject
{
protected:
    char name[50];

public:
    TDetail(const char* NAME);

    const char* GetName() const;

    void Show() override;
};


// =====================================================
// ЭЛЕМЕНТ СВЯЗАННОГО СПИСКА ГРУППЫ
// =====================================================

struct TItem
{
    TObject* item;
    TItem* next;

    TItem(TObject* ITEM)
    {
        item = ITEM;
        next = nullptr;
    }
};


// Указатель на функцию-обработчик
typedef void (*PF)(TObject*);


// =====================================================
// АБСТРАКТНАЯ ГРУППА
// =====================================================

class TGroup : public TObject
{
protected:
    char name[50];
    TItem* last;

public:
    TGroup(const char* NAME);
    virtual ~TGroup();

    const char* GetName() const;

    void Insert(TObject* p);
    bool Empty() const;
    void ShowItems() const;

    virtual void ForEach(PF action) = 0;
};


// =====================================================
// УЗЕЛ
// =====================================================

class TNode : public TGroup
{
public:
    TNode(const char* NAME);

    void Show() override;
    void ForEach(PF action) override;
};


// =====================================================
// МЕХАНИЗМ
// =====================================================

class TMechanism : public TGroup
{
public:
    TMechanism(const char* NAME);

    void Show() override;
    void ForEach(PF action) override;
};


// Запрос варианта №11:
// наименование всех деталей (узлов), входящих в заданный узел.
void PrintName(TObject* p);

#endif