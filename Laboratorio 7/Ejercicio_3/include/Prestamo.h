#ifndef PRESTAMO_H_
#define PRESTAMO_H_

#include <string>

#include "ProductoBancario.h"

class Prestamo: protected ProductoBancario
{
    public:
        Prestamo();
        Prestamo(std::string, double);
        Prestamo(const Prestamo &o);
        void imprimir();
        ~Prestamo();
};

#endif
