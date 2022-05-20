#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>

#include "ProductoBancario.h"

class Cuenta: public ProductoBancario
{
    public:
        Cuenta();
        Cuenta(std::string, double);
        Cuenta(const Cuenta &o);
        void imprimir();
        ~Cuenta();
};

#endif
