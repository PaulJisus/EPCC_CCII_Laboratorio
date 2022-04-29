#include <iostream>
#include <ctime>
#include <string>
#include <locale>

using namespace std;

void datos();
void mostrar(struct tm*, int);

struct tm* tmP;
int x;
//Arreglo de strings para los dias de la semana
std::string dS[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

int main() {
    datos();
    mostrar(tmP, x);
    return 0;
}

void datos()
{
    //inicializacion de una variable tipo time_t
    time_t tSac = time(NULL);
    //se inicializa la estructura con el tiempo actual
    tmP = localtime(&tSac);
    std::cout << "\nIngrese los minutos para ser disminuido: ";
    std::cin >> x;
}

void mostrar(struct tm* tmP, int x)
{
    setlocale(LC_ALL, "");
    //condicional para verificar si los minutos aumentados son mayores a 59
    if(x > 59)
    {
        tmP->tm_hour -= x/60;
        tmP->tm_min -= x%60;
    }
    else
    {
        tmP->tm_min -= x;
    }
    //condicional para verificar si los minutos se decrementaron hasta llegar a ser negativos
    if(tmP->tm_min < 0)
    {
        tmP->tm_min +=59;
        tmP->tm_hour -= 1;
    }
    //condicional para verificar si las horas se decrementaron hasta llegar a ser negativos
    if(tmP->tm_hour < 0)
    {
        tmP->tm_hour += 24;
        tmP->tm_mday -= 1;
        tmP->tm_wday -= 1;
        tmP->tm_yday -= 1;
    }
    cout << "hh:mm:ss " << tmP->tm_hour << ":" << tmP->tm_min << ":"
                       << tmP->tm_sec << endl;
    cout << "dd-mm-aaaa: " << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"
                          << tmP->tm_year+1900 << endl;
    cout << "Día de semana: " << dS[tmP->tm_wday] << endl;
    cout << "Día del año: " << tmP->tm_yday << endl;
}
