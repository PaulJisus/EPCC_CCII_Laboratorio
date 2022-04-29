#include <iostream>

using namespace std;

void datos();
void mostrar(float *, int);

float *estudiantes = nullptr;
int tam;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    //llamada a la funcion que mostrara el resultado
    mostrar(estudiantes, tam);
    //se libera la memoria.
    delete[]estudiantes;
}

void datos()
{
    std::cout << "\nPrograma para hallar el promedio de tres notas de n estudiantes.\n";
    std::cout << "\nIngrese la cantidad de estudiantes:\n";
    std::cin >> tam;
    //separamos memoria en funcion a la cantidad de numeros a ingresar para el arreglo
    estudiantes = new float[tam];
    for(int i = 0; i < tam; i++)
    {
        float a = 0, b = 0, c = 0;
        std::cout << "\nIngrese la primera nota del estudiante " << i + 1 << ": ";
        std::cin >> a;
        std::cout << "\nIngrese la segunda nota del estudiante " << i + 1 << ": ";
        std::cin >> b;
        std::cout << "\nIngrese la tercera nota del estudiante " << i + 1 << ": ";
        std::cin >> c;
        *(estudiantes + i) = (a + b + c) / 3;
    }
}

void mostrar(float *estudiantes, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        std::cout << "\nEl promedio de las tres notas del estudiante " << i+1 << " es:\t";
        std::cout << *(estudiantes + i) << '\n';
    }
}
