#include <iostream>

using namespace std;

void datos(int [][5]);
void mostrar(int [][5]);
void rotarderecha(int [][5]);
void rotarizquierda(int [][5]);
void moverarriba(int [][5]);
void moverabajo(int [][5]);

int numeros[5][5], aux[5][5];

int main()
{
    int op;
    do {
        std::cout << "\n\n\t\t\tMENU\n";
        std::cout << "\t ===============================\n";
        std::cout << "\t|Numero |Opciones\t\t|\n";
        std::cout << "\t ===============================\n";
        std::cout << "\t|1.\t|Introducir valores.\t|\n";
        std::cout << "\t|2.\t|Mostrar Matriz.\t|\n";
        std::cout << "\t|3.\t|Rotar Matriz Derecha.  |\n";
        std::cout << "\t|4.\t|Rotar Matriz Izquierda.|\n";
        std::cout << "\t|5.\t|Mover Filas Arriba.\t|\n";
        std::cout << "\t|6.\t|Mover Filas Abajo.\t|\n";
        std::cout << "\t|7.\t|Salir.\t\t\t|\n";
        std::cout << "\t ===============================\n\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> op;
        switch (op) {
            case 1:
                std::cout << "\nOpcion 1\n";
                datos(numeros);
            break;
            case 2:
                std::cout << "\nOpcion 2\n";
                mostrar(numeros);
            break;
            case 3:
                std::cout << "\nOpcion 3\n";
                rotarderecha(numeros);
            break;
            case 4:
                std::cout << "\nOpcion 4\n";
                rotarizquierda (numeros);
            break;
            case 5:
                std::cout << "\nOpcion 5\n";
                moverarriba (numeros);
            break;
            case 6:
                std::cout << "\nOpcion 6\n";
                moverabajo (numeros);
            break;
            default:
                std::cout << "\n¡¡¡Seleccione una opcion correcta!!!\n";
            break;
        }
    } while (op != 7);
    return 0;
}


void datos(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cout << "Ingrese el elemento de la posicion[" << i << "][" << j << "]: ";
            std::cin >> numeros[i][j];
        }
    }
}

void mostrar(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cout << numeros[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void rotarderecha(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j == 4)
            {
                aux[i][0] = numeros[i][j];
            }
            else
            {
                aux[i][j+1] = numeros[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            numeros[i][j] = aux[i][j];
        }
    }
}

void rotarizquierda(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j == 0)
            {
                aux[i][4] = numeros[i][j];
            }
            else
            {
                aux[i][j-1] = numeros[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            numeros[i][j] = aux[i][j];
        }
    }
}

void moverarriba(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == 0)
            {
                aux[4][j] = numeros[i][j];
            }
            else
            {
                aux[i-1][j] = numeros[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            numeros[i][j] = aux[i][j];
        }
    }
}

void moverabajo(int numeros[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == 4)
            {
                aux[0][j] = numeros[i][j];
            }
            else
            {
                aux[i+1][j] = numeros[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            numeros[i][j] = aux[i][j];
        }
    }
}
