#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Nota{
    float primera_fase;
    float segunda_fase;
    float tercera_fase;
    float proyecto_final;
};

struct Nombre{
    std::string nombres;
    std::string apellido_p;
    std::string apellido_m;
};

struct Alumno{
    Nombre nombre;
    Nota notas;
    char grupo;
};

void Datos();
void Mostrar(Alumno *, unsigned int);

int main()
{
    Datos();
    return 0;
}

void Datos()
{
    unsigned int n{};
    std::cout << "Ingrese la cantidad de alumnos:\n";
    std::cin >> n;
    Alumno *alumnos = new Alumno[n];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(unsigned int i{0}; i < n; i++)
    {
        std::cout << "\n******* Alumno " << i + 1 << "********\n";
        std::cout << "Ingrese los nombres del alumno " << i+1 << ":\n";
        std::getline(std::cin, alumnos[i].nombre.nombres);
        std::cout << "Ingrese el apellido paterno del alumno " << i+1 << ":\n";
        std::getline(std::cin, alumnos[i].nombre.apellido_p);
        std::cout << "Ingrese el apellido materno del alumno " << i+1 << ":\n";
        std::getline(std::cin, alumnos[i].nombre.apellido_m);
        std::cout << "Ingrese el grupo del alumno " << i+1 << ":\n";
        std::cin >> alumnos[i].grupo;
        std::cout << "Ingrese la nota de la primera fase del alumno " << i+1 << ":\n";
        std::cin >> alumnos[i].notas.primera_fase;
        std::cout << "Ingrese la nota de la segunda fase del alumno " << i+1 << ":\n";
        std::cin >> alumnos[i].notas.segunda_fase;
        std::cout << "Ingrese la nota de la tercera fase del alumno " << i+1 << ":\n";
        std::cin >> alumnos[i].notas.tercera_fase;
        std::cout << "Ingrese la nota del proyecto Final del alumno " << i+1 << ":\n";
        std::cin >> alumnos[i].notas.proyecto_final;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Mostrar(alumnos, n);
    delete[] alumnos;
}

void Mostrar(Alumno *alumnos, unsigned int n)
{
    float n_f{};
    for(unsigned int i{0}; i < n; i++)
    {
        n_f = (alumnos[i].notas.primera_fase * 0.15) + (alumnos[i].notas.segunda_fase * 0.20) + (alumnos[i].notas.tercera_fase * 0.25) + (alumnos[i].notas.proyecto_final * 0.40);
        std::cout << "\nNombre: " << alumnos[i].nombre.nombres << std::endl;
        std::cout << "Apellido Paterno: " << alumnos[i].nombre.apellido_p << std::endl;
        std::cout << "Apellido Materno: " << alumnos[i].nombre.apellido_m << std::endl;
        std::cout << "Grupo: " << alumnos[i].grupo << std::endl;
        std::cout << "Nota Final: " << n_f << std::endl;
        if(n_f >= 10.5)
        {
            std::cout << "Alumno Aprobado.\n";
        }
        else
        {
            std::cout << "Alumno Desaprobado.\n";
        }
    }
}
