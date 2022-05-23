#ifndef PUNTO_H_
#define PUNTO_H_

#include <iostream>

class Punto
{
    public:
        Punto();
        Punto(double, double);
        Punto(const Punto &o);
        void setX(const double);
        double getX() const;
        void setY(const double);
        double getY() const;
        void imprimir() const;
        ~Punto();
    private:
        double x;
        double y;
};

std::ostream& operator<< (std::ostream &output, const Punto &o);

#endif
