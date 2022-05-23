#ifndef CIRCULO_H_
#define CIRCULO_H_

#include <iostream>

#include "Elipse.h"

class Circulo: public Elipse
{
    public:
        Circulo();
        Circulo(std::string, double, double, std::string, double, double);
        Circulo(const Circulo &o);
        double getRadio() const;
        double getDiametro() const;
        double getArea() const;
        double getPerimetro() const;
        void setTamEscala(const double);
        void imprimir() const;
        ~Circulo();
};

std::ostream& operator<< (std::ostream &output, const Circulo &o);

#endif
