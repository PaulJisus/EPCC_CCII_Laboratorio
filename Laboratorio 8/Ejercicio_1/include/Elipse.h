#ifndef ELIPSE_H_
#define ELIPSE_H_

#include <cmath>
#include <iostream>

#include "Forma.h"

class Elipse: public Forma
{
    public:
        Elipse();
        Elipse(std::string, double, double, std::string, double, double);
        Elipse(const Elipse &o);
        void setRadio_mayor(const double);
        double getRadio_mayor() const;
        void setRadio_menor(const double);
        double getRadio_menor() const;
        double getPi() const;
        double getArea() const;
        double getPerimetroAprox1() const;
        double getPerimetroAprox2() const;
        void setTamEscala(const double);
        void imprimir() const;
        ~Elipse();
    private:
        double radio_mayor;
        double radio_menor;
        constexpr static double pi = 3.141592653589793238462643383279502884L;
};

std::ostream& operator<< (std::ostream &output, const Elipse &o);

#endif
