#include "Hipoteca.h"

Hipoteca::Hipoteca(): Prestamo{}
{

}

Hipoteca::Hipoteca(std::string cliente, double saldo): Prestamo(cliente, saldo)
{

}

Hipoteca::Hipoteca(const Hipoteca &o): Prestamo(o)
{

}

void Hipoteca::imprimir()
{
    std::cout << "\nHipoteca:\n_________";
    ProductoBancario::imprimir();
}

Hipoteca::~Hipoteca()
{

}
