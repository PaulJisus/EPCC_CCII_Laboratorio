#ifndef HIPOTECA_H_
#define HIPOTECA_H_

#include <string>

#include "Prestamo.h"

class Hipoteca: public Prestamo
{
    public:
        Hipoteca();
        Hipoteca(std::string, double);
        Hipoteca(const Hipoteca &o);
        void imprimir();
        ~Hipoteca();
};

#endif
