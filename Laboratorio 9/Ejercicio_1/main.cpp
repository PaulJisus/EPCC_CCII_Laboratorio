#include <iostream>

#include "MinMax.h"

using namespace std;

void datos();
//template <typename T>
//T maximo(T, T, T);
//template <typename T>
//T minimo(T, T, T);
//template <typename T>
//void mostrar(T, T);

int main()
{
    datos();
    return 0;
}

void datos()
{
    int op{};
    do {
        std::cout << "\n\n\t\t\tMENU\n";
        std::cout << "\t ===============================\n";
        std::cout << "\t|Numero |Tipo de dato\t\t|\n";
        std::cout << "\t ===============================\n";
        std::cout << "\t|1.\t|Entero.\t\t|\n";
        std::cout << "\t|2.\t|Largo.\t\t\t|\n";
        std::cout << "\t|3.\t|Flotante.\t\t|\n";
        std::cout << "\t|4.\t|Doble.\t\t\t|\n";
        std::cout << "\t|5.\t|Salir.\t\t\t|\n";
        std::cout << "\t ===============================\n\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> op;
        switch (op) {
            case 1:
            {
                MinMax<int> mm1;
                int x{}, y{}, z{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer entero:\n";
                std::cin >> x;
                mm1.setValor1(x);
                std::cout << "\nIngrese el segundo entero:\n";
                std::cin >> y;
                mm1.setValor2(y);
                std::cout << "\nIngrese el tercer entero:\n";
                std::cin >> z;
                mm1.setValor3(z);
                std::cout << mm1;
            }
            break;
            case 2:
            {
                MinMax<long> mm1;
                long x{}, y{}, z{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer largo:\n";
                std::cin >> x;
                mm1.setValor1(x);
                std::cout << "\nIngrese el segundo largo:\n";
                std::cin >> y;
                mm1.setValor2(y);
                std::cout << "\nIngrese el tercer largo:\n";
                std::cin >> z;
                mm1.setValor3(z);
                std::cout << mm1;
            }
            break;
            case 3:
            {
                MinMax<float> mm1;
                float x{}, y{}, z{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer flotante:\n";
                std::cin >> x;
                mm1.setValor1(x);
                std::cout << "\nIngrese el segundo flotante:\n";
                std::cin >> y;
                mm1.setValor2(y);
                std::cout << "\nIngrese el tercer flotante:\n";
                std::cin >> z;
                mm1.setValor3(z);
                std::cout << mm1;
            }
            break;
            case 4:
            {
                MinMax<double> mm1;
                double x{}, y{}, z{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer doble:\n";
                std::cin >> x;
                mm1.setValor1(x);
                std::cout << "\nIngrese el segundo doble:\n";
                std::cin >> y;
                mm1.setValor2(y);
                std::cout << "\nIngrese el tercer doble:\n";
                std::cin >> z;
                mm1.setValor3(z);
                std::cout << mm1;
            }
            break;
            default:
                std::cout << "\n¡¡¡Seleccione una opcion correcta!!!\n";
            break;
        }
    } while (op != 5);
}

//void datos()
//{
//    int op{};
//    do {
//        std::cout << "\n\n\t\t\tMENU\n";
//        std::cout << "\t ===============================\n";
//        std::cout << "\t|Numero |Tipo de dato\t\t|\n";
//        std::cout << "\t ===============================\n";
//        std::cout << "\t|1.\t|Entero.\t\t|\n";
//        std::cout << "\t|2.\t|Largo.\t\t\t|\n";
//        std::cout << "\t|3.\t|Flotante.\t\t|\n";
//        std::cout << "\t|4.\t|Doble.\t\t\t|\n";
//        std::cout << "\t|5.\t|Salir.\t\t\t|\n";
//        std::cout << "\t ===============================\n\n";
//        std::cout << "Ingrese su opcion: ";
//        std::cin >> op;
//        switch (op) {
//            case 1:
//            {
//                int x{}, y{}, z{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer entero:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo entero:\n";
//                std::cin >> y;
//                std::cout << "\nIngrese el tercer entero:\n";
//                std::cin >> z;
//                mostrar(maximo(x, y, z), minimo(x, y, z));
//            }
//            break;
//            case 2:
//            {
//                long x{}, y{}, z{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer largo:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo largo:\n";
//                std::cin >> y;
//                std::cout << "\nIngrese el tercer largo:\n";
//                std::cin >> z;
//                mostrar(maximo(x, y, z), minimo(x, y, z));
//            }
//            break;
//            case 3:
//            {
//                float x{}, y{}, z{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer flotante:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo flotante:\n";
//                std::cin >> y;
//                std::cout << "\nIngrese el tercer flotante:\n";
//                std::cin >> z;
//                mostrar(maximo(x, y, z), minimo(x, y, z));
//            }
//            break;
//            case 4:
//            {
//                double x{}, y{}, z{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer doble:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo doble:\n";
//                std::cin >> y;
//                std::cout << "\nIngrese el tercer doble:\n";
//                std::cin >> z;
//                mostrar(maximo(x, y, z), minimo(x, y, z));
//            }
//            break;
//            default:
//                std::cout << "\n¡¡¡Seleccione una opcion correcta!!!\n";
//            break;
//        }
//    } while (op != 5);
//}
//
//template <typename T>
//T maximo(T x, T y, T z)
//{
//    T aux{};
//    aux = x;
//    if(y >= aux)
//    {
//        aux = y;
//    }
//    if(z >= aux)
//    {
//        aux = z;
//    }
//    return aux;
//}
//
//template <typename T>
//T minimo(T x, T y, T z)
//{
//    T aux{};
//    aux = x;
//    if(y <= aux)
//    {
//        aux = y;
//    }
//    if(z <= aux)
//    {
//        aux = z;
//    }
//    return aux;
//}
//
//template <typename T>
//void mostrar(T n1, T n2)
//{
//    std::cout << "\n\tEl mayor valor es:\n\t" << n1 << '\n';
//    std::cout << "\n\tEl menor valor es:\n\t" << n2 << '\n';
//}
