#include <iostream>

#include "Ave.h"
#include "Ganso.h"
#include "Gallina.h"
#include "Pato.h"

using namespace std;

int main()
{
    Ganso g1("Anseriformes", "Anatidae", "Anserinae", "Anser", "A. anser", "Anser anser domesticus", "Rusia", "Oca domestica", "Macho", 3204.78, 103.5);
    std::cout << g1;
    Gallina ga1("Galliformes", "Phasianidae", "Phasianinae Horsfield", "Gallus", "G. gallus", "G. g. domesticus", "España", "Gallina serrana de Teruel", "Hembra", 2457.6, 39.6);
    std::cout << ga1;
    Pato p1("Anseriformes", "Anatidae", "Anatinae", "Anas", "A. platyrhynchos", "A. p. domesticus", "Anade real", "Nepal", "Macho", 1442.62, 29.46);
    std::cout << p1;
    return 0;
}
