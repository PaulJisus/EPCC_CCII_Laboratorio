#include <iostream>

#include "Persona.h"
#include "Alumno.h"

using namespace std;

int main()
{
    Persona p1(24, "Clemente Ernesto", "Vegazo Soto", "av. Independencia 1024", "juanvs@hotmail.com", 75498023, 954234890);
    std::cout << p1;
    Alumno a1(25, "Pablo Joaquin", "Chire Luna", "calle Paucarpata 256", "pjchirel@gmail.com", 73672648, 963482934, "Ciencia de la Computacion", 20213478);
    std::cout << a1;
    return 0;
}
