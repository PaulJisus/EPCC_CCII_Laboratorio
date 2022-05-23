#ifndef FORMA_H_
#define FORMA_H_

#include <string>
#include <iostream>

#include "Punto.h"

class Forma
{
    public:
        Forma();
        Forma(std::string, double, double, std::string);
        Forma(const Forma &o);
        void setColor(const std::string);
        std::string getColor() const;
        void setCentroX(const double);
        double getCentroX() const;
        void setCentroY(const double);
        double getCentroY() const;
        void setNombre(const std::string);
        std::string getNombre() const;
        virtual double getArea() const;
        void Mover(const double, const double);
        virtual void imprimir() const;
        virtual ~Forma();
    private:
        std::string color;
        Punto centro;
        std::string nombre;
};

std::ostream& operator<< (std::ostream &output, const Forma &o);

#endif
