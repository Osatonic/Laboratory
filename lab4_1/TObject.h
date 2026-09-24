#ifndef TOBJECT_H
#define TOBJECT_H

#include <iostream>
#include <cstring>

using namespace std;


// =====================================================
// БАЗОВЫЙ АБСТРАКТНЫЙ КЛАСС
// =====================================================

class TObject
{
public:
    virtual void Show() = 0;

    virtual ~TObject() {}
};


// =====================================================
// ЛАБОРАТОРНАЯ РАБОТА №3
// ТРАНСПОРТНОЕ СРЕДСТВО
// =====================================================

class TTransport : public TObject
{
protected:
    char name[50];

public:
    TTransport(const char* NAME);

    virtual ~TTransport() {}

    const char* GetName();

    void Show() override = 0;
};


// =====================================================
// АВТОМОБИЛЬ
// =====================================================

class TCar : public TTransport
{
protected:
    int wheels;

public:
    TCar(const char* NAME, int WHEELS);

    void Show() override;
};


// =====================================================
// ПОЕЗД
// =====================================================

class TTrain : public TTransport
{
protected:
    int wagons;

public:
    TTrain(const char* NAME, int WAGONS);

    void Show() override;
};


// =====================================================
// ЭКСПРЕСС
// =====================================================

class TExpress : public TTrain
{
protected:
    int speed;

public:
    TExpress(
        const char* NAME,
        int WAGONS,
        int SPEED
    );

    void Show() override;
};


// =====================================================
// ДЕТАЛЬ
// =====================================================

class TDetail : public TObject
{
protected:
    char name[50];

public:
    TDetail(const char* NAME);

    const char* GetName();

    void Show() override;
};


// =====================================================
// ЭЛЕМЕНТ СВЯЗАННОГО СПИСКА
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


// =====================================================
// АБСТРАКТНАЯ ГРУППА
// =====================================================

class TGroup : public TObject
{
protected:
    char name[50];

    // Указатель на начало списка TItem
    TItem* last;

public:
    TGroup(const char* NAME);

    virtual ~TGroup();

    const char* GetName();

    void Insert(TObject* p);

    bool Empty();

    void ShowItems();

    // Итератор
    virtual void ForEach() = 0;
};


// =====================================================
// УЗЕЛ
// =====================================================

class TNode : public TGroup
{
public:
    TNode(const char* NAME);

    void Show() override;

    void ForEach() override;
};


// =====================================================
// МЕХАНИЗМ
// =====================================================

class TMechanism : public TGroup
{
public:
    TMechanism(const char* NAME);

    void Show() override;

    void ForEach() override;
};


// =====================================================
// ФУНКЦИЯ ДЛЯ ВАРИАНТА №11
// =====================================================

void PrintName(TObject* p);

#endif