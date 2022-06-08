#include "Nodo.h"

Nodo::Nodo() = default;

Nodo::Nodo(int valor)
{
    this->valor = valor;
    siguiente = nullptr;
}

void Nodo::setValor(const int valor)
{
    this->valor = valor;
}

int Nodo::getValor() const
{
    return (this->valor);
}

void Nodo::setSiguiente(Nodo *siguiente)
{
    this->siguiente= siguiente;
}

Nodo *Nodo::getSiguiente() const
{
    return siguiente;
}

Nodo::~Nodo()
{
    delete siguiente;
}
