#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include <string>
#include <iostream>

#include "Forma.h"

class Rectangulo: public Forma
{
    public:
        Rectangulo();
        Rectangulo(std::string, double, double, std::string, double, double);
        Rectangulo(const Rectangulo &o);
        void setLado_mayor(const double);
        double getLado_mayor() const;
        void setLado_menor(const double);
        double getLado_menor() const;
        double getArea() const;
        double getPerimetro() const;
        void setTamEscala(const double);
        void imprimir() const;
        ~Rectangulo();
    private:
        double lado_mayor;
        double lado_menor;
};

std::ostream& operator<< (std::ostream &output, const Rectangulo &o);

#endif
