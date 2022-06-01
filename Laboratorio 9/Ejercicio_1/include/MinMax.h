#ifndef MINMAX_H_
#define MINMAX_H_

#include <iostream>

template <typename T>
class MinMax;

template <typename T>
std::ostream& operator<< (std::ostream &output, const MinMax<T> &o);

template <typename T>
class MinMax
{
    public:
        MinMax();
        MinMax(T, T, T);
        MinMax(const MinMax<T> &o);
        void setValor1(const T);
        T getValor1() const;
        void setValor2(const T);
        T getValor2() const;
        void setValor3(const T);
        T getValor3() const;
        T maximo() const;
        T minimo() const;
        ~MinMax();
    private:
        T valor1;
        T valor2;
        T valor3;
};

#endif

template <typename T>
MinMax<T>::MinMax() = default;

template <typename T>
MinMax<T>::MinMax(T valor1, T valor2, T valor3)
{
    this->valor1 = valor1;
    this->valor2 = valor2;
    this->valor3 = valor3;
}

template <typename T>
MinMax<T>::MinMax(const MinMax<T> &o)
{
    this->valor1 = o.valor1;
    this->valor2 = o.valor2;
    this->valor3 = o.valor3;
}

template <typename T>
void MinMax<T>::setValor1(const T valor1)
{
    this->valor1 = valor1;
}

template <typename T>
T MinMax<T>::getValor1() const
{
    return (this->valor1);
}

template <typename T>
void MinMax<T>::setValor2(const T valor2)
{
    this->valor2 = valor2;
}

template <typename T>
T MinMax<T>::getValor2() const
{
    return (this->valor2);
}

template <typename T>
void MinMax<T>::setValor3(const T valor3)
{
    this->valor3 = valor3;
}

template <typename T>
T MinMax<T>::getValor3() const
{
    return (this->valor3);
}

template <typename T>
T MinMax<T>::maximo() const
{
    T aux{};
    aux = getValor1();
    if(getValor2() >= aux)
    {
        aux = getValor2();
    }
    if(getValor3() >= aux)
    {
        aux = getValor3();
    }
    return aux;
}

template <typename T>
T MinMax<T>::minimo() const
{
    T aux{};
    aux = getValor1();
    if(getValor2() <= aux)
    {
        aux = getValor2();
    }
    if(getValor3() <= aux)
    {
        aux = getValor3();
    }
    return aux;
}

template <typename T>
MinMax<T>::~MinMax()
{

}

template <typename T>
std::ostream& operator<< (std::ostream &output, const MinMax<T> &o)
{
    output << "De los numeros ingresado se obtuvo:\n"
    << "Mayor: " << o.maximo()
    << "\nMenor: " << o.minimo() << '\n';
    return output;
}
