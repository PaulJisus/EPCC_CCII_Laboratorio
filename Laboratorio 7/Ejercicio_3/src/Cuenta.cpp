#include "Cuenta.h"

Cuenta::Cuenta(): ProductoBancario{}
{

}

Cuenta::Cuenta(std::string cliente, double saldo): ProductoBancario(cliente, saldo)
{

}

Cuenta::Cuenta(const Cuenta &o): ProductoBancario(o)
{

}

void Cuenta::imprimir()
{
    std::cout << "\nCuenta:\n_______";
    ProductoBancario::imprimir();
}

Cuenta::~Cuenta()
{

}
