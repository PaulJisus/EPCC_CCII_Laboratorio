#include <iostream>

#include "ProductoBancario.h"
#include "Cuenta.h"
#include "Prestamo.h"
#include "CuentaJoven.h"
#include "Hipoteca.h"

using namespace std;

int main()
{
    ProductoBancario pb1("Jose", 2345.50);
    pb1.imprimir();
    Cuenta c1("Alfonso", 3450.70);
    c1.imprimir();
    Prestamo p1("Alexia", 1500.00);
    p1.imprimir();
    CuentaJoven cj1("Rocio", 2050.75);
    cj1.imprimir();
    Hipoteca h1("Pedro", 5250.25);
    h1.imprimir();
    return 0;
}
