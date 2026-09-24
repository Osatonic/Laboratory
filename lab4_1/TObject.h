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
    // Чистая виртуальная функция.
    // Благодаря ей TObject является абстрактным классом.
    virtual void Show() = 0;

    // Виртуальный деструктор.
    virtual ~TObject() {}
};


// =====================================================
// ТРАНСПОРТНОЕ СРЕДСТВО
// Идея из лабораторной работы №3
// =====================================================

class TTransport : public TObject
{
protected:
    char name[50];

public:
    TTransport(const char* NAME);

    virtual ~TTransport() {}

    const char* GetName() const;

    // Транспорт является абстрактным.
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
// Экспресс является поездом
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

    const char* GetName() const;

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
// УКАЗАТЕЛЬ НА ФУНКЦИЮ-ОБРАБОТЧИК
// =====================================================

// Такая функция получает один объект группы
// и выполняет над ним нужное действие.
typedef void (*PF)(TObject*);


// =====================================================
// АБСТРАКТНАЯ ГРУППА
// =====================================================

class TGroup : public TObject
{
protected:
    char name[50];

    // Начало связанного списка объектов группы
    TItem* last;

public:
    TGroup(const char* NAME);

    virtual ~TGroup();

    const char* GetName() const;

    // Добавить объект в группу
    void Insert(TObject* p);

    // Проверить, пуста ли группа
    bool Empty() const;

    // Показать непосредственные элементы группы
    void ShowItems() const;

    // Метод-итератор.
    // Для каждого элемента вызывает переданную функцию.
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


// =====================================================
// ФУНКЦИЯ ДЛЯ ВАРИАНТА №11
// =====================================================

// Выводит название любого объекта,
// который может находиться в группе.
void PrintName(TObject* p);

#endif