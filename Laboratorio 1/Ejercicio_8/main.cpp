#include <iostream>

using namespace std;

void datos();
float media(float *, int);
void mostrar(float *, int);

float *num = nullptr;
int tam;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    //llamada a la funcion que mostrara el resultado
    mostrar(num, tam);
    //se libera la memoria.
    delete[]num;
}

void datos()
{
    std::cout << "\nPrograma para hallar la media de cierta cantidad de numeros.\n";
    std::cout << "\nIngrese la cantidad de numeros:\n";
    std::cin >> tam;
    //separamos memoria en funcion a la cantidad de numeros a ingresar para el arreglo
    num = new float[tam];
    for(int i = 0; i < tam; i++)
    {
        std::cout << "\nIngrese el numero " << i + 1 << ": ";
        std::cin >> *(num + i);
    }
}

float media(float *num, int tam)
{
    float suma;
    float valor_m;
    for(int i = 0; i < tam; i++)
    {
        suma += *(num + i);
    }
    valor_m = suma / tam;
    return valor_m;
}

void mostrar(float *num, int tam)
{
    std::cout << "\nDe los siguientes numeros introducidos:\n";
    for(int i = 0; i < tam; i++)
    {
        std::cout << *(num + i) << '\t';
    }
    std::cout << "\nEl valor de la media obtenida fue: \t" << media(num, tam) << '\n';
}
