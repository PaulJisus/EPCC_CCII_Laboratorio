#include "CuentaJoven.h"

CuentaJoven::CuentaJoven(): Cuenta{}
{

}

CuentaJoven::CuentaJoven(std::string cliente, double saldo): Cuenta(cliente, saldo)
{

}

CuentaJoven::CuentaJoven(const CuentaJoven &o): Cuenta(o)
{

}

void CuentaJoven::imprimir()
{
    std::cout << "\nCuenta Joven:\n_____________";
    ProductoBancario::imprimir();
}

CuentaJoven::~CuentaJoven()
{

}
