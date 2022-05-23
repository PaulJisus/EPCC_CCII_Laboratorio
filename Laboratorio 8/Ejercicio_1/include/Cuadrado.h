#ifndef CUADRADO_H_
#define CUADRADO_H_

#include <iostream>

#include "Rectangulo.h"

class Cuadrado: public Rectangulo
{
    public:
        Cuadrado();
        Cuadrado(std::string, double, double, std::string, double, double);
        Cuadrado(const Cuadrado &o);
        double getLado() const;
        double getArea() const;
        double getPerimetro() const;
        void setTamEscala(const double);
        void imprimir() const;
        ~Cuadrado();
};

std::ostream& operator<< (std::ostream &output, const Cuadrado &o);

#endif
