#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void datos();
int longitud(char *);
bool comparar(char *, char *);
void mostrar();

char contrasena[50], comparable[50];

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    //llamada a la funcion que mostrara el resultado
    mostrar();
}

void datos()
{
    std::cout << "\nEstablezca su contrasena : ";
    std::cin.getline(contrasena, 50, '\n');
}

//funcion para calcular la longitud de la cadena
int longitud(char *contrasena)
{
    int tam = 0;
    //se ejecutara el siguiente bucle mientras se siga leyendo la cadena
    while(*contrasena++ != '\0')
    {
        tam++;
    }
    return tam;
}

bool comparar(char *contrasena, char *comparable)
{
    bool aux;
    //bucle para verificar la igualdad de caracter a caracter
    for(int i = 0; i < longitud(contrasena); i++)
    {
        if(*(contrasena + i) != *(comparable + i))
            aux = false;
        else
            aux = true;
    }
    return aux;
}

void mostrar()
{
    //no se saldra de este bucle si las cadenas no son iguales
    while (!comparar(contrasena, comparable))
    {
        std::cout << "\nIngrese su contrasena : ";
        std::cin.getline(comparable, 50, '\n');
    }
    std::cout << "\nContrasena correcta\n";
}

