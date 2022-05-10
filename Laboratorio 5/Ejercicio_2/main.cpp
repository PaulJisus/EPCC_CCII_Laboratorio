#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void datos();
void ingresar(float *, float *, int, int, int);
float producto_punto(float *, float *, int);

int n, m;
float *a = nullptr, *b = nullptr;

int main()
{
    datos();
    return 0;
}

void datos()
{
    std::cout << "\n\tPrograma para hallar el producto punto de vectores.\n";
    std::cout << "\t===================================================\n";
    std::cout << "\nIngrese el tamaño del primer vector:\n";
    std::cin >> n;
    std::cout << "\nIngrese el tamaño del segundo vector:\n";
    std::cin >> m;
	if(n != m)
	{
		std::cout<<"Los vectores deben de tener el mismo tamaño\n";
        std::cout << "\nIngrese el tamaño del primer vector:\n";
        std::cin >> n;
        std::cout << "\nIngrese el tamaño del segundo vector:\n";
        std::cin >> m;
	}
	else
    {
        for(int i = 0; i < 1000000; i++)
        {
            a = new float[n];
            b = new float[m];
            ingresar(a, b, n, m, i);
            std::cout << "\nEl producto punto de los vectores A(" << i+1 << ") y B(" << i+1 << ") es:\t" << producto_punto(a, b, n);
            delete[]b;
            delete[]a;
        }
    }
}

void ingresar(float *a, float *b, int n, int m, int i)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(-(n + m + i), (n + m + i));

    for (int j = 0; j < (n + m); j++)
    {
        if(j % 2 == 0)
        {
            *(a + (j/2)) = distr(eng);
        }
        else
        {
            *(b + (j/2)) = distr(eng);
        }
    }
}

float producto_punto(float *a, float *b, int n)
{
    float producto_p = 0.0;
    for(int i = 0; i < n; i++)
    {
        producto_p += (*(a + i)) * (*(b + i));
    }
    return producto_p;
}
