#include <iostream>
#include <ctime>

using namespace std;

void datos();
void llenar(char *, int);
void mostrar(char *, int);
void invertir(char *, int);

char *palabra = nullptr;
char *aux = nullptr;
int tam;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    llenar(palabra, tam);
    //llamada a la funcion que mostrara el resultado
    mostrar(palabra, tam);
    invertir(palabra, tam);
    delete[]palabra;
}

void datos()
{
    std::cout << "\n\tPrograma para invertir una palabra.\n";
    std::cout << "\t__________________________________\n";
    std::cout << "\nIngrese el tamaño de la palabra: ";
    std::cin >> tam;
    palabra = new char [tam];
}

void llenar(char *palabra, int tam)
{
    srand(time(NULL));
    for(int i = 0; i < tam; i++)
    {
        *palabra++ = 97 + rand()% 26;
    }
}

void mostrar(char *palabra, int tam)
{
    std::cout << "La palabra inicial es:\n";
    for(int i = 0; i < tam; i++)
    {
        cout << *(palabra + i);
    }
    cout << endl;
}

void invertir(char *palabra, int tam)
{
    std::cout << "La palabra invertida es:\n";
    for(int i = tam - 1; i >= 0; i--)
    {
        cout << *(palabra + i);
    }
    cout << endl;
}
