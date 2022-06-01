#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <iostream>

template <typename T>
class Operaciones;

template <typename T>
std::ostream& operator<< (std::ostream &output, const Operaciones<T> &o);

template <typename T>
class Operaciones
{
    public:
        Operaciones();
        Operaciones(T, T);
        Operaciones(const Operaciones<T> &o);
        void setValor1(const T);
        T getValor1() const;
        void setValor2(const T);
        T getValor2() const;
        T suma() const;
        T resta() const;
        T multiplicacion() const;
        T division() const;
        ~Operaciones();
    private:
        T valor1;
        T valor2;
};

#endif

template <typename T>
Operaciones<T>::Operaciones() = default;

template <typename T>
Operaciones<T>::Operaciones(T valor1, T valor2)
{
    this->valor1 = valor1;
    this->valor2 = valor2;
}

template <typename T>
Operaciones<T>::Operaciones(const Operaciones<T> &o)
{
    this->valor1 = o.valor1;
    this->valor2 = o.valor2;
}

template <typename T>
void Operaciones<T>::setValor1(const T valor1)
{
    this->valor1 = valor1;
}

template <typename T>
T Operaciones<T>::getValor1() const
{
    return (this->valor1);
}

template <typename T>
void Operaciones<T>::setValor2(const T valor2)
{
    this->valor2 = valor2;
}

template <typename T>
T Operaciones<T>::getValor2() const
{
    return (this->valor2);
}

template <typename T>
T Operaciones<T>::suma() const
{
    return (getValor1() + getValor2());
}

template <typename T>
T Operaciones<T>::resta() const
{
    return (getValor1() - getValor2());
}

template <typename T>
T Operaciones<T>::multiplicacion() const
{
    return (getValor1() * getValor2());
}

template <typename T>
T Operaciones<T>::division() const
{
    return (getValor1() / getValor2());
}

template <typename T>
Operaciones<T>::~Operaciones()
{

}

template <typename T>
std::ostream& operator<< (std::ostream &output, const Operaciones<T> &o)
{
    output << "El valor de las operaciones elementales es:\n"
    << o.getValor1() << " + " << o.getValor2() << " = " << o.suma() << '\n'
    << o.getValor1() << " - " << o.getValor2() << " = " << o.resta() << '\n'
    << o.getValor1() << " * " << o.getValor2() << " = " << o.multiplicacion() << '\n'
    << o.getValor1() << " / " << o.getValor2() << " = " << o.division() << '\n';
    return output;
}
