#ifndef CORREO_H_
#define CORREO_H_

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Correo;

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream &output, const Correo<T1,T2> &o);

template <typename T1, typename T2>
class Correo
{
    public:
        Correo();
        Correo(T1, T2);
        Correo(const Correo<T1, T2> &o);
        void setLetra(const T1);
        T1 getLetra() const;
        void setApellido(const T2);
        T2 getApellido() const;
        void imprimir() const;
        ~Correo();
    private:
        T1 letra;
        T2 apellido;
};

//template class Correo <char, std::string>;
//
//template <typename T1, typename T2>
//std::ostream& operator<<<> (std::ostream &output, const Correo<T1,T2> &o);

#endif

template <typename T1, typename T2>
Correo<T1, T2>::Correo() = default;

template <typename T1, typename T2>
Correo<T1, T2>::Correo(T1 letra, T2 apellido)
{
    this->letra = letra;
    this->apellido = apellido;
}

template <typename T1, typename T2>
Correo<T1, T2>::Correo(const Correo<T1, T2> &o)
{
    this->letra = o.letra;
    this->apellido = o.apellido;
}

template <typename T1, typename T2>
void Correo<T1, T2>::setLetra(const T1 letra)
{
    this->letra = letra;
}

template <typename T1, typename T2>
T1 Correo<T1, T2>::getLetra() const
{
    return (this->letra);
}

template <typename T1, typename T2>
void Correo<T1, T2>::setApellido(const T2 apellido)
{
    this->apellido = apellido;
}

template <typename T1, typename T2>
T2 Correo<T1, T2>::getApellido() const
{
    return (this->apellido);
}

template <typename T1, typename T2>
void Correo<T1, T2>::imprimir() const
{
    std::cout << "\nEl correo es:\n";
    std::cout << getLetra() << getApellido() << "@unsa.edu.pe\n";
}

template <typename T1, typename T2>
Correo<T1, T2>::~Correo()
{

}

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream &output, const Correo<T1, T2> &o)
{
    output << "\n---------------------------------------------------------" << std::endl
    << "\nEl correo es:\n"
    << o.getLetra()
    << o.getApellido()
    << "@unsa.edu.pe\n";
    return output;
}

