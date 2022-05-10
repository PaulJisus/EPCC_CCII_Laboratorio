#include <iostream>
#include <ctime>

using namespace std;

void datos();
void llenar(char *, int);
void mostrar(char *, int);
void concatenar(char *, char *);

char *a = nullptr;
char *b = nullptr;
int tam, tam1;

int main()
{
    datos();
    llenar(a, tam);
    llenar(b, tam1);
    cout << "\nLa prmera cadena es :\n\n";
    mostrar(a, tam);
    cout << "\nLa segunda cadena es :\n\n";
    mostrar(b, tam1);
    cout << "\nLas cadenas concatenadas son:\n\n";
    concatenar(a, b);
    delete[]a;
    delete[]b;
    cout << endl;
    return 0;
}

void datos()
{
    cout << "\nIngrese la longitud de la primera cadena :";
    cin >> tam;
    a = new char[tam];
    cout << "\nIngrese la longitud de la segunda cadena :";
    cin >> tam1;
    b = new char[tam+tam1+1];
}

void llenar(char *aux, int t)
{
    srand(time(NULL));
    for(int i = 0; i < t; i++)
    {
        *aux++ = 97 + rand()% 26;
    }
}

void mostrar(char *aux, int t)
{
    for(int i = 0; i < t; i++)
    {
        cout << *aux++;
    }
    cout << endl;
}

void concatenar(char *a, char *b)
{
    char *ptr = nullptr;
    char *aux = nullptr;
    for(aux = b; *aux != '\0'; aux++){
    }
    for(ptr = a; *ptr != '\0'; ptr++, aux++){
        *aux = *ptr;
    }
    *aux = '\0';
    cout << b;
}
