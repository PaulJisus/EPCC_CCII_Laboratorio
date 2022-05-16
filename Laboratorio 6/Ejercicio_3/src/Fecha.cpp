#include "Fecha.h"

Fecha::Fecha(std::string n, std::string a, int db, int mb, int yb, int da, int ma, int ya):
Nombres(n), Apellidos(a), DayB(db), MonthB(mb), YearB(yb), DayA(da), MonthA(ma), YearA(ya)
{

}

Fecha::~Fecha()
{

}

std::string Fecha::getNombres() const
{
    return Nombres;
}

void Fecha::setNombres(std::string Nombres)
{
    this->Nombres = Nombres;
}

std::string Fecha::getApellidos() const
{
    return Apellidos;
}

void Fecha::setApellidos(std::string Apellidos)
{
    this->Apellidos = Apellidos;
}

int Fecha::getDayB() const
{
    return DayB;
}

void Fecha::setDayB(int DayB)
{
    this->DayB = DayB;
}

int Fecha::getMonthB() const
{
    return MonthB;
}

void Fecha::setMonthB(int MonthB)
{
    this->MonthB = MonthB;
}

int Fecha::getYearB() const
{
    return YearB;
}

void Fecha::setYearB(int YearB)
{
    this->YearB = YearB;
}

int Fecha::getDayA() const
{
    return DayA;
}

void Fecha::setDayA(int DayA)
{
    this->DayA = DayA;
}

int Fecha::getMonthA() const
{
    return MonthA;
}

void Fecha::setMonthA(int MonthA)
{
    this->MonthA = MonthA;
}

int Fecha::getYearA() const
{
    return YearA;
}

void Fecha::setYearA(int YearA)
{
    this->YearA = YearA;
}

int Fecha::getDaysOfAge()
{
    if(getDayA() < getDayB())
    {
        setDayA(getDayA() + 30);
        setMonthA(getMonthA() - 1);
        return getDayA() - getDayB();
    }
    else
    {
        return getDayA() - getDayB();
    }
}

int Fecha::getMonthsOfAge()
{
    if(getMonthA() < getMonthB())
    {
        setMonthA(getMonthA() + 12);
        setYearA(getYearA() - 1);
        return getMonthA() - getMonthB();
    }
    else
    {
        return getMonthA() - getMonthB();
    }
}

int Fecha::getYearsOfAge()
{
    return getYearA() - getYearB();
}

std::ostream& operator << (std::ostream &output, Fecha &f)
{
    output << "Nombres:\t" << f.getNombres() << "\nApellidos:\t" << f.getApellidos()
    << "\nEdad:\t" << f.getYearsOfAge() << " a" << char(164) << "os, " << f.getMonthsOfAge()
    << " meses y " << f.getDaysOfAge() << " dias.\n";
    return output;
}
