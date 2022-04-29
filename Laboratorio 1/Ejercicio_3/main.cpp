#include <iostream>

using namespace std;

void datos();
void hora(int, int, int);

int h, m, x;

int main()
{
    //Llamada a la funcion de datos de entrada
    datos();
    //Llamada a la funcion que mostrara el resultado
    hora(h, m, x);
    return 0;
}

void datos()
{
    char a;
    std::cout << "Programa para calcular la hora aumentada segun x minutos.\n";
    std::cout << "\nIngrese la hora: ";
    std::cin >> h >> a >> m;
    std::cout << "\nIngrese los minutos para ser aumentados: ";
    std::cin >> x;
}

void hora(int h, int m, int x)
{
    //condicional para verificar si el tiempo incrementado es mayor a una hora
    if(x > 59)
    {
        //si el tiempo incrementado es mayor a una hora
        //se aumenta el resultado de la divison a las horas
        h += x/60;
        //se aumenta el resultado del modulo a los minutos
        m += x%60;
    }
    else
    {
        m += x;
    }
    //condicional para verificar si el tiempo resutltante en los minutos es mayor a 59.
    if(m > 59)
    {
        m -=60;
        h += 1;
    }
    //condicional para verificar si el tiempo resutltante en las horas es mayor a 12.
    if(h > 12){
        h -= 12;
        std::cout << "\n" << h << ":" << m << " PM\n";
    }
    else if (h <= 12)
    {
        std::cout << "\n" << h << ":" << m << " AM\n";
    }
}
