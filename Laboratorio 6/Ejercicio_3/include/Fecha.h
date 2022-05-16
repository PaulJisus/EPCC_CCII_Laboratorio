#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>
#include <string>

using namespace std;

class Fecha
{
    public:
        Fecha(std::string, std::string, int, int, int, int, int, int);
        ~Fecha();
        std::string getNombres() const;
        void setNombres(std::string);
        std::string getApellidos() const;
        void setApellidos(std::string);
        int getDayB() const;
        void setDayB(int);
        int getMonthB() const;
        void setMonthB(int);
        int getYearB() const;
        void setYearB(int);
        int getDayA() const;
        void setDayA(int);
        int getMonthA() const;
        void setMonthA(int);
        int getYearA() const;
        void setYearA(int);
        int getDaysOfAge();
        int getMonthsOfAge();
        int getYearsOfAge();
        friend std::ostream& operator << (std::ostream &output, Fecha &f);
    private:
        std::string Nombres;
        std::string Apellidos;
        int DayB, MonthB, YearB, DayA, MonthA, YearA;
};

#endif
