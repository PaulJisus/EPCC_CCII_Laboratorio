#include <iostream>

#include "Operaciones.h"

using namespace std;

void datos();
//template <typename T>
//T suma(T, T);
//template <typename T>
//T resta(T, T);
//template <typename T>
//T multiplicacion(T, T);
//template <typename T>
//T division(T, T);
//template <typename T>
//void mostrar(T, T, T, T);

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
                Operaciones<int> op1;
                int x{}, y{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer entero:\n";
                std::cin >> x;
                op1.setValor1(x);
                std::cout << "\nIngrese el segundo entero:\n";
                std::cin >> y;
                op1.setValor2(y);
                std::cout << op1;
            }
            break;
            case 2:
            {
                Operaciones<long> op1;
                long x{}, y{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer largo:\n";
                std::cin >> x;
                op1.setValor1(x);
                std::cout << "\nIngrese el segundo largo:\n";
                std::cin >> y;
                op1.setValor2(y);
                std::cout << op1;
            }
            break;
            case 3:
            {
                Operaciones<float> op1;
                float x{}, y{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer flotante:\n";
                std::cin >> x;
                op1.setValor1(x);
                std::cout << "\nIngrese el segundo flotante:\n";
                std::cin >> y;
                op1.setValor2(y);
                std::cout << op1;
            }
            break;
            case 4:
            {
                Operaciones<double> op1;
                double x{}, y{};
                std::cout << "\n\tIngrese los valores\n";
                std::cout << "\nIngrese el primer doble:\n";
                std::cin >> x;
                op1.setValor1(x);
                std::cout << "\nIngrese el segundo doble:\n";
                std::cin >> y;
                op1.setValor2(y);
                std::cout << op1;
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
//                int x{}, y{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer entero:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo entero:\n";
//                std::cin >> y;
//                mostrar(suma(x, y), resta(x, y), multiplicacion(x, y), division (x, y));
//            }
//            break;
//            case 2:
//            {
//                long x{}, y{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer largo:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo largo:\n";
//                std::cin >> y;
//                mostrar(suma(x, y), resta(x, y), multiplicacion(x, y), division (x, y));
//            }
//            break;
//            case 3:
//            {
//                float x{}, y{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer flotante:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo flotante:\n";
//                std::cin >> y;
//                mostrar(suma(x, y), resta(x, y), multiplicacion(x, y), division (x, y));
//            }
//            break;
//            case 4:
//            {
//                double x{}, y{};
//                std::cout << "\n\tIngrese los valores\n";
//                std::cout << "\nIngrese el primer doble:\n";
//                std::cin >> x;
//                std::cout << "\nIngrese el segundo doble:\n";
//                std::cin >> y;
//                mostrar(suma(x, y), resta(x, y), multiplicacion(x, y), division (x, y));
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
//T suma(T x, T y)
//{
//    return x + y;
//}
//
//template <typename T>
//T resta(T x, T y)
//{
//    return x - y;
//}
//
//template <typename T>
//T multiplicacion(T x, T y)
//{
//    return x * y;
//}
//
//template <typename T>
//T division(T x, T y)
//{
//    return x / y;
//}
//
//template <typename T>
//void mostrar(T r1, T r2, T r3, T r4)
//{
//    std::cout << "\n\tEl valor de la suma es:\n\t" << r1 << '\n';
//    std::cout << "\n\tEl valor de la resta es:\n\t" << r2 << '\n';
//    std::cout << "\n\tEl valor de la multiplicacion es:\n\t" << r3 << '\n';
//    std::cout << "\n\tEl valor de la division es:\n\t" << r4 << '\n';
//}
