#include "Hospital.h"

// Конструктор без параметров
HOSPITAL::HOSPITAL()
{
    wards = 0;
    equipment = 0;
    details = 0;
    staff = 0;
    workHours = 0;
    payroll = 0.0;
    constructionState = "Не начато";

    cout << "Вызван конструктор без параметров. "
         << "Объект: " << this << endl;
}


// Конструктор с параметрами
HOSPITAL::HOSPITAL(
    int wards,
    int equipment,
    int details,
    int staff,
    int workHours,
    double payroll,
    string state
)
{
    this->wards = wards;
    this->equipment = equipment;
    this->details = details;
    this->staff = staff;
    this->workHours = workHours;
    this->payroll = payroll;
    this->constructionState = state;

    cout << "Вызван конструктор с параметрами. "
         << "Объект: " << this << endl;
}


// Конструктор копирования
HOSPITAL::HOSPITAL(const HOSPITAL& other)
{
    wards = other.wards;
    equipment = other.equipment;
    details = other.details;
    staff = other.staff;
    workHours = other.workHours;
    payroll = other.payroll;
    constructionState = other.constructionState;

    cout << "Вызван конструктор копирования. "
         << "Объект: " << this << endl;
}


// Деструктор
HOSPITAL::~HOSPITAL()
{
    cout << "Вызван деструктор. "
         << "Объект: " << this << endl;
}


// Get-функции

int HOSPITAL::GetWards() const
{
    return wards;
}

int HOSPITAL::GetEquipment() const
{
    return equipment;
}

int HOSPITAL::GetDetails() const
{
    return details;
}

int HOSPITAL::GetStaff() const
{
    return staff;
}

int HOSPITAL::GetWorkHours() const
{
    return workHours;
}

double HOSPITAL::GetPayroll() const
{
    return payroll;
}

string HOSPITAL::GetConstructionState() const
{
    return constructionState;
}


// Set-функции

void HOSPITAL::SetWards(int value)
{
    wards = value;
}

void HOSPITAL::SetEquipment(int value)
{
    equipment = value;
}

void HOSPITAL::SetDetails(int value)
{
    details = value;
}

void HOSPITAL::SetStaff(int value)
{
    staff = value;
}

void HOSPITAL::SetWorkHours(int value)
{
    workHours = value;
}

void HOSPITAL::SetPayroll(double value)
{
    payroll = value;
}

void HOSPITAL::SetConstructionState(string value)
{
    constructionState = value;
}


// Установка всех полей

void HOSPITAL::Set(
    int wards,
    int equipment,
    int details,
    int staff,
    int workHours,
    double payroll,
    string state
)
{
    this->wards = wards;
    this->equipment = equipment;
    this->details = details;
    this->staff = staff;
    this->workHours = workHours;
    this->payroll = payroll;
    this->constructionState = state;
}


// Вывод информации

void HOSPITAL::Show() const
{
    cout << endl;
    cout << "----- ИНФОРМАЦИЯ О БОЛЬНИЦЕ -----" << endl;

    cout << "Количество палат: "
         << wards << endl;

    cout << "Количество оборудования: "
         << equipment << endl;

    cout << "Количество строительных деталей: "
         << details << endl;

    cout << "Количество работников: "
         << staff << endl;

    cout << "Количество рабочих часов: "
         << workHours << endl;

    cout << "Фонд оплаты труда: "
         << payroll << endl;

    cout << "Состояние строительства: "
         << constructionState << endl;

    cout << "----------------------------------" << endl;
}


// =====================================================
// ОПЕРАТОР ВЫВОДА
// Нужен для cout << hospital
// =====================================================

ostream& operator<<(ostream& out, const HOSPITAL& hospital)
{
    out << "{"
        << "палаты=" << hospital.wards
        << ", оборудование=" << hospital.equipment
        << ", детали=" << hospital.details
        << ", работники=" << hospital.staff
        << ", часы=" << hospital.workHours
        << ", фонд=" << hospital.payroll
        << ", состояние=" << hospital.constructionState
        << "}";

    return out;
}


// =====================================================
// ОПЕРАТОР ВВОДА
// Нужен для cin >> hospital
//
// Вводится 7 значений:
// wards equipment details staff workHours payroll state
// Например:
// 50 20 1000 80 300 500000 Строительство
// =====================================================

istream& operator>>(istream& in, HOSPITAL& hospital)
{
    int wards;
    int equipment;
    int details;
    int staff;
    int workHours;
    double payroll;
    string state;

    in >> wards
       >> equipment
       >> details
       >> staff
       >> workHours
       >> payroll
       >> state;

    if (in)
    {
        hospital.Set(
            wards,
            equipment,
            details,
            staff,
            workHours,
            payroll,
            state
        );
    }

    return in;
}


// =====================================================
// ОПЕРАТОР СРАВНЕНИЯ
// Нужен для List<HOSPITAL>::operator==
// =====================================================

bool operator==(const HOSPITAL& left, const HOSPITAL& right)
{
    return
        left.wards == right.wards &&
        left.equipment == right.equipment &&
        left.details == right.details &&
        left.staff == right.staff &&
        left.workHours == right.workHours &&
        left.payroll == right.payroll &&
        left.constructionState == right.constructionState;
}
