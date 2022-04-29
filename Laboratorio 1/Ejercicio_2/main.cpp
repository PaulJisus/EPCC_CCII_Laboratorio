#include <iostream>
#include <string>

using namespace std;

void datos();
std::string generar(std::string, std::string, std::string);

std::string nombre, apellido_p, apellido_m;

int main()
{
    //Llamada la funcion para la entrada de datos.
    datos();
    std::cout << "\nSu correo UNSA generado es: " << generar(nombre, apellido_p, apellido_m) << '\n';
    return 0;
}

void datos()
{
    std::cout << "Programa para generar su correo UNSA.\n";
    std::cout << "\nIngrese su nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "\nIngrese su apellido paterno: ";
    std::getline(std::cin, apellido_p);
    std::cout << "\nIngrese su apellido materno: ";
    std::getline(std::cin, apellido_m);
}

std::string generar(std::string nombre, std::string apellido_p, std::string apellido_m)
{
    std::string res = " ";
    //Asignamos a res el primer caracter de nombre, el apellido paterno
    //y el primer caracter del apellido materno junto con @unsa.edu.pe
    res = nombre.front() + apellido_p + apellido_m.front() + "@unsa.edu.pe";
    return res;
}
