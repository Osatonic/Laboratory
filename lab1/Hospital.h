#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

using namespace std;

class HOSPITAL
{
private:
    int wards;                  // количество палат
    int equipment;              // количество единиц оборудования
    int details;                // количество строительных деталей
    int staff;                  // количество работников
    int workHours;              // количество рабочих часов
    double payroll;             // фонд оплаты труда
    string constructionState;   // состояние строительства

public:
    // Конструктор без параметров
    HOSPITAL();

    // Конструктор с параметрами
    HOSPITAL(
        int wards,
        int equipment,
        int details,
        int staff,
        int workHours,
        double payroll,
        string state
    );

    // Конструктор копирования
    HOSPITAL(const HOSPITAL& other);

    // Деструктор
    ~HOSPITAL();

    // Функции получения данных
    int GetWards() const;
    int GetEquipment() const;
    int GetDetails() const;
    int GetStaff() const;
    int GetWorkHours() const;
    double GetPayroll() const;
    string GetConstructionState() const;

    // Функции установки данных
    void SetWards(int value);
    void SetEquipment(int value);
    void SetDetails(int value);
    void SetStaff(int value);
    void SetWorkHours(int value);
    void SetPayroll(double value);
    void SetConstructionState(string value);

    // Установка всех данных сразу
    void Set(
        int wards,
        int equipment,
        int details,
        int staff,
        int workHours,
        double payroll,
        string state
    );

    // Вывод информации
    void Show() const;
};

#endif