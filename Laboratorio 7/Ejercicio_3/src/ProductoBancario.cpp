#include "ProductoBancario.h"

ProductoBancario::ProductoBancario() = default;

ProductoBancario::ProductoBancario(std::string cliente, double saldo)
{
    this->cliente = cliente;
    this->saldo = saldo;
    numProductos++;
}

ProductoBancario::ProductoBancario(const ProductoBancario &o)
{
    this->cliente = o.cliente;
    this->saldo = o.saldo;
    numProductos++;
}

void ProductoBancario::imprimir()
{
    std::cout << "\nCliente:\t" << cliente;
    std::cout << "\nSaldo:\t\t" << saldo;
    std::cout << "\nNumero:\t\t" << numProductos << std::endl;
}

ProductoBancario::~ProductoBancario()
{
    numProductos--;
}
