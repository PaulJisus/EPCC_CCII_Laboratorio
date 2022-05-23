#include <iostream>

#include "Punto.h"
#include "Forma.h"
#include "Rectangulo.h"
#include "Elipse.h"
#include "Cuadrado.h"
#include "Circulo.h"

using namespace std;

void Mayor(Forma *[], int);

int main()
{
    Punto p1(4.5, 3.67);
    p1.imprimir();
    std::cout << p1;
    Forma f1("Azul", 3.4, 5.6, "Redondo");
    f1.imprimir();
    f1.Mover(2, 2);
    std::cout << f1;
    Rectangulo r1("Amarillo", 2.8, 3.9, "Rectangulo", 7.5, 5.3);
    r1.imprimir();
    r1.Mover(3, 2.5);
    r1.setTamEscala(2);
    std::cout << r1;
    Elipse e1("Verde", 12.5, 8.6, "Elipse", 10, 5);
    e1.imprimir();
    e1.Mover(2, 6);
    e1.setTamEscala(1.8);
    std::cout << e1;
    Cuadrado c1("Rojo", 9.6, 8.7, "Cuadrado", 9.6, 0);
    c1.imprimir();
    c1.Mover(1.8, 3.5);
    c1.setTamEscala(2.65);
    std::cout << c1;
    Circulo ci1("Purpura", 5.3, 2.5, "Circulo", 0, 7.8);
    ci1.imprimir();
    ci1.Mover(2.3, 9.4);
    ci1.setTamEscala(2.75);
    std::cout << ci1;
    Forma *ptrforma[4];
    ptrforma[0] = new Rectangulo("Anaranjado", 3.8, 4.9, "Rectangulo", 6.5, 4.3);
    ptrforma[1] = new Elipse("Violeta", 11.5, 9.6, "Elipse", 20, 10);
    ptrforma[2] = new Cuadrado("Magenta", 10.6, 8.7, "Cuadrado", 10.6, 0);
    ptrforma[3] = new Circulo("Carmin", 6.3, 3.4, "Circulo", 0, 8.7);
    for(int i = 0; i < 4; i++)
    {
        ptrforma[i]->setColor("Negro");
        ptrforma[i]->Mover(2.2, 3.3);
        ptrforma[i]->imprimir();
        std::cout << "¡¡¡Area!!! " << ptrforma[i]->getArea() << std::endl;;
    }
    Mayor(ptrforma, 4);
    return 0;
}

void Mayor(Forma *ptrforma[], int n)
{
    double mayor{0};
    int aux{0};
    for(int i = 0; i < n; i++)
    {
        if(ptrforma[i]->getArea() > mayor)
        {
            mayor = ptrforma[i]->getArea();
            aux = i;
        }
    }
    std::cout << "\n\nForma con la mayor area.\n";
    ptrforma[aux]->imprimir();
}

