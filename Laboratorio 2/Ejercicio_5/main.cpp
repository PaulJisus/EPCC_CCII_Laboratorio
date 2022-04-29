#include <iostream>

using namespace std;

void datos();
float media(float *, int);
float mayor(float *, int);
float menor(float *, int);
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
    std::cout << "\nPrograma para hallar el menor, el mayor y la media de cierta cantidad de numeros.\n";
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
    float suma = 0;
    float valor_m;
    for(int i = 0; i < tam; i++)
    {
        suma += *(num + i);
    }
    valor_m = suma / tam;
    return valor_m;
}

float mayor(float *num, int tam)
{
    float mayor = -(RAND_MAX);
    for(int i = 0; i < tam; i++)
    {
        if(*(num + i) > mayor)
            mayor = *(num + i);
    }
    return mayor;
}

float menor(float *num, int tam)
{
    float menor = RAND_MAX;
    for(int i = 0; i < tam; i++)
    {
        if(*(num + i) < menor)
            menor = *(num + i);
    }
    return menor;
}

void mostrar(float *num, int tam)
{
    std::cout << "\nDe los siguientes numeros introducidos:\n";
    for(int i = 0; i < tam; i++)
    {
        std::cout << *(num + i) << '\t';
    }
    std::cout << "\n\nEl valor de la media obtenida fue: \t" << media(num, tam) << '\n';
    std::cout << "\nEl mayor valor obtenido fue: \t" << mayor(num, tam) << '\n';
    std::cout << "\nEl menor valor obtenido fue: \t" << menor(num, tam) << '\n';
}
