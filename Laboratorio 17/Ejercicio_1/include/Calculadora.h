#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#include <iostream>

template <typename T>
class Calculadora
{
    public:
        Calculadora();
        Calculadora(T, T);
        Calculadora(const Calculadora &);
        void setX(T);
        T getX();
        void setY(T);
        T getY();
        T suma();
        T resta();
        T multiplicacion();
        T division();
        void resultado();
        ~Calculadora();
    private:
        T x, y;
};

template <typename T>
Calculadora<T>::Calculadora()
{
    this->x = 0;
    this->y = 0;
}

template <typename T>
Calculadora<T>::Calculadora(T x, T y)
{
    this->x = x;
    this->y = y;
}

template <typename T>
Calculadora<T>::Calculadora(const Calculadora &o)
{
    this->x = o.x;
    this->y = o.y;
}

template <typename T>
void Calculadora<T>::setX(T x)
{
    this->x = x;
}

template <typename T>
T Calculadora<T>::getX()
{
    return (this->x);
}

template <typename T>
void Calculadora<T>::setY(T y)
{
    this->y = y;
}

template <typename T>
T Calculadora<T>::getY()
{
    return (this->y);
}

template <typename T>
T Calculadora<T>::suma()
{
    return (this->x + this->y);
}

template <typename T>
T Calculadora<T>::resta()
{
    return (this->x - this->y);
}

template <typename T>
T Calculadora<T>::multiplicacion()
{
    return (this->x * this->y);
}

template <typename T>
T Calculadora<T>::division()
{
    if(this->y == 0)
    {
        throw std::logic_error("Imposible division entre cero\n");
    }
    else
    {
        return (this->x / this->y);
    }
}

template <typename T>
void Calculadora<T>::resultado()
{
    std::cout << "Teniendo los siguiente numeros:\t" << getX() << " y " << getY() << ".\n";
    std::cout << "El resultado de las operaciones es.\n";
    std::cout << getX() << " + " << getY() << " = " << suma() << std::endl;
    std::cout << getX() << " - " << getY() << " = " << resta() << std::endl;
    std::cout << getX() << " * " << getY() << " = " << multiplicacion() << std::endl;
    try{
        std::cout << getX() << " / " << getY() << " = " << division() << std::endl;
    }catch(const std::exception& e)
    {
        std::cout << e.what();
    }
}

template <typename T>
Calculadora<T>::~Calculadora() = default;

#endif
