#ifndef CUENTAJOVEN_H_
#define CUENTAJOVEN_H_

#include <string>

#include "Cuenta.h"

class CuentaJoven: private Cuenta
{
    public:
        CuentaJoven();
        CuentaJoven(std::string, double);
        CuentaJoven(const CuentaJoven &o);
        void imprimir();
        ~CuentaJoven();
};

#endif
