#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include <string>
#include <iostream>

using namespace std;

class Rectangulo
{
    public:
        Rectangulo(int, int);
        ~Rectangulo();
        int getBase() const;
        void setBase(int);
        int getAltura() const;
        void setAltura(int);
        int Perimetro() const;
        int Area() const;
        friend std::ostream& operator << (std::ostream &output, const Rectangulo &r);
    private:
        int base;
        int altura;
};

#endif
