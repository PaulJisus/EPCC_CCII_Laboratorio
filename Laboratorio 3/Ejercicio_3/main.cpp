#include <iostream>

using namespace std;

void datos();
void mostrar(int, int, int, int, int, int);

int a, m, d, a_n, m_n, d_n;

int main()
{
    //Llamada a la funcion datos(), para ingresar los datos.
    datos();
    mostrar(a, m, d, a_n, m_n, d_n);
    return 0;
}

void datos()
{
    std::cout << "\n\tPrograma para hallar su edad.\n" << '\n';
    std::cout << "\nIngrese el a" << (char)164 << "o actual:\n";
    std::cin >> a;
    std::cout << "\nIngrese el mes actual:\n";
    std::cin >> m;
    std::cout << "\nIngrese el dia actual:\n";
    std::cin >> d;
    std::cout << "\nIngrese el a" << (char)164 << "o de su nacimiento:\n";
    std::cin >> a_n;
    std::cout << "\nIngrese el mes de su nacimiento:\n";
    std::cin >> m_n;
    std::cout << "\nIngrese el dia de su nacimiento:\n";
    std::cin >> d_n;
}

void mostrar(int a, int m, int d, int a_n, int m_n, int d_n)
{
    int aux, aux1;
    if ( d < d_n  )
    {
        d = d + 30;
        m = m - 1;
        aux =  d - d_n;
    }
    else
    {
        aux =  d - d_n;
    }

    if( m < m_n )
    {
        m = m + 12;
        a = a - 1 ;
        aux1 = m - m_n;
    }
    else
    {
        aux1 = m - m_n;
    }

    std::cout << "\n\tUsted tiene:\n";
    std::cout << a - a_n << " a" << (char)164 << "os con " << aux1 << " meses y " << aux << " dias.\n";
}
