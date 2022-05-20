#include "Prestamo.h"

Prestamo::Prestamo(): ProductoBancario{}
{

}

Prestamo::Prestamo(std::string cliente, double saldo): ProductoBancario(cliente, saldo)
{

}

Prestamo::Prestamo(const Prestamo &o): ProductoBancario(o)
{

}

void Prestamo::imprimir()
{
    std::cout << "\nPrestamo:\n_________";
    ProductoBancario::imprimir();
}

Prestamo::~Prestamo()
{

}

