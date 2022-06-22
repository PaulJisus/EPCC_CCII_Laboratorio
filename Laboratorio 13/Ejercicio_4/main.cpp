#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Nombre{
    std::string nombres;
    std::string apellido_p;
    std::string apellido_m;
};

struct Empleado{
    Nombre nombre;
    std::string sexo;
    float sueldo;
};

void Datos();
void Mostrar(Empleado *, unsigned int);

int main()
{
    Datos();
    return 0;
}

void Datos()
{
    unsigned int n{};
    std::cout << "Ingrese la cantidad de empleados:\n";
    std::cin >> n;
    Empleado *empleados = new Empleado[n];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(unsigned int i{0}; i < n; i++)
    {
        std::cout << "\n******* Empleado " << i + 1 << "********\n";
        std::cout << "Ingrese los nombres del empleado " << i+1 << ":\n";
        std::getline(std::cin, empleados[i].nombre.nombres);
        std::cout << "Ingrese el apellido paterno del empleado " << i+1 << ":\n";
        std::getline(std::cin, empleados[i].nombre.apellido_p);
        std::cout << "Ingrese el apellido materno del empleado " << i+1 << ":\n";
        std::getline(std::cin, empleados[i].nombre.apellido_m);
        std::cout << "Ingrese el sexo del empleado " << i+1 << ":\n";
        std::getline(std::cin, empleados[i].sexo);
        std::cout << "Ingrese el sueldo del empleado " << i+1 << ":\n";
        std::cin >> empleados[i].sueldo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Mostrar(empleados, n);
    delete[] empleados;
}

void Mostrar(Empleado* empleados, unsigned int n)
{
    float mayor{empleados[0].sueldo}, menor{empleados[0].sueldo};
    unsigned temp1{}, temp2{};
    for(unsigned int i{0}; i < n; i++)
    {
        if(empleados[i].sueldo < menor)
        {
            menor = empleados[i].sueldo;
            temp1 = i;
        }
        if(empleados[i].sueldo > mayor)
        {
            mayor = empleados[i].sueldo;
            temp2 = i;
        }
    }
    std::cout << "\nEl empleado con mayor sueldo es:\n";
    std::cout << "\nNombre: " << empleados[temp2].nombre.nombres << std::endl;
    std::cout << "Apellido Paterno: " << empleados[temp2].nombre.apellido_p << std::endl;
    std::cout << "Apellido Materno: " << empleados[temp2].nombre.apellido_m << std::endl;
    std::cout << "Sexo: " << empleados[temp2].sexo << std::endl;
    std::cout << "Sueldo: " << empleados[temp2].sueldo << std::endl;
    std::cout << "\nEl empleado con menor sueldo es:\n";
    std::cout << "\nNombre: " << empleados[temp1].nombre.nombres << std::endl;
    std::cout << "Apellido Paterno: " << empleados[temp1].nombre.apellido_p << std::endl;
    std::cout << "Apellido Materno: " << empleados[temp1].nombre.apellido_m << std::endl;
    std::cout << "Sexo: " << empleados[temp1].sexo << std::endl;
    std::cout << "Sueldo: " << empleados[temp1].sueldo << std::endl;
}
