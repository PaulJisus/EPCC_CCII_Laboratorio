#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Fecha{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
};

struct Nombre{
    std::string nombres;
    std::string apellido_p;
    std::string apellido_m;
};

struct Persona{
    Nombre nombre;
    Fecha fecha;
};

void Datos();
void Mostrar(Persona *, unsigned int);

int main()
{
    Datos();
    return 0;
}

void Datos()
{
    unsigned int n{};
    std::cout << "Ingrese la cantidad de personas:\n";
    std::cin >> n;
    Persona *companieros = new Persona[n];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(unsigned int i{0}; i < n; i++)
    {
        std::cout << "\n******* Persona " << i + 1 << " ********\n";
        std::cout << "Ingrese los nombres de la persona " << i+1 << ":\n";
        std::getline(std::cin, companieros[i].nombre.nombres);
        std::cout << "Ingrese el apellido paterno de la persona " << i+1 << ":\n";
        std::getline(std::cin, companieros[i].nombre.apellido_p);
        std::cout << "Ingrese el apellido materno de la persona " << i+1 << ":\n";
        std::getline(std::cin, companieros[i].nombre.apellido_m);
        std::cout << "Ingrese el anio de nacimiento de la persona " << i+1 << ":\n";
        std::cin >> companieros[i].fecha.anio;
        std::cout << "Ingrese el mes de nacimiento de la persona " << i+1 << ":\n";
        std::cin >> companieros[i].fecha.mes;
        std::cout << "Ingrese el dia de nacimiento de la persona " << i+1 << ":\n";
        std::cin >> companieros[i].fecha.dia;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Mostrar(companieros, n);
    delete[] companieros;
}

void Mostrar(Persona *companieros, unsigned int n)
{
    unsigned int m{}, cont{};
    std::string meses[12]{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Setiembre", "Octubre", "Noviembre", "Diciembre"};
    std::cout << "\nIngrese el numero del mes:\n";
    std::cin >> m;
    std::string mes_m = meses[m];
    for(unsigned int i{0}; i < n; i++)
    {
        if(companieros[i].fecha.mes == m)
        {
            std::cout << "\nNombre: " << companieros[i].nombre.nombres << std::endl;
            std::cout << "Apellido Paterno: " << companieros[i].nombre.apellido_p << std::endl;
            std::cout << "Apellido Materno: " << companieros[i].nombre.apellido_m << std::endl;
            std::cout << "Fecha de Nacimiento: " << companieros[i].fecha.dia << " - " << companieros[i].fecha.mes <<
            " - " << companieros[i].fecha.anio << std::endl << std::endl;
            cont++;
        }
    }
    std::cout << "\nEn total cumplen anios " << cont << " personas en el mes de " << mes_m << ".\n";
}
