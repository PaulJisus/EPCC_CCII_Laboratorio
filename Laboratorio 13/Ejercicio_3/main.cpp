#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Nombre{
    std::string nombres;
    std::string apellido_p;
    std::string apellido_m;
};

struct Jugador{
    Nombre nombre;
    unsigned int edad;
    float talla;
};

void Datos();
void Mostrar(Jugador [], const unsigned int);

int main()
{
    Datos();
    return 0;
}

void Datos()
{
    const unsigned int n{10};
    Jugador jugadores[n];
    for(unsigned int i{0}; i < n; i++)
    {
        std::cout << "\n******* Jugador " << i + 1 << "********\n";
        std::cout << "Ingrese los nombres del jugador " << i+1 << ":\n";
        std::getline(std::cin, jugadores[i].nombre.nombres);
        std::cout << "Ingrese el apellido paterno del jugador " << i+1 << ":\n";
        std::getline(std::cin, jugadores[i].nombre.apellido_p);
        std::cout << "Ingrese el apellido materno del jugador " << i+1 << ":\n";
        std::getline(std::cin, jugadores[i].nombre.apellido_m);
        std::cout << "Ingrese la edad del jugador " << i+1 << ":\n";
        std::cin >> jugadores[i].edad;
        std::cout << "Ingrese la estatura del jugador " << i+1 << " (en metros):\n";
        std::cin >> jugadores[i].talla;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Mostrar(jugadores, n);
}

void Mostrar(Jugador jugadores[], const unsigned int n)
{
    std::cout << "\nJugadores menores de 20 anios y de estatura superior a 1.70 mts.\n";
    for(unsigned int i{0}; i < n; i++)
    {
        if(jugadores[i].edad < 20 && jugadores[i].talla > 1.70)
        {
            std::cout << "\nNombre: " << jugadores[i].nombre.nombres << std::endl;
            std::cout << "Apellido Paterno: " << jugadores[i].nombre.apellido_p << std::endl;
            std::cout << "Apellido Materno: " << jugadores[i].nombre.apellido_m << std::endl;
            std::cout << "Edad: " << jugadores[i].edad << std::endl;
            std::cout << "Estatura: " << jugadores[i].talla << std::endl;
        }
    }
}
