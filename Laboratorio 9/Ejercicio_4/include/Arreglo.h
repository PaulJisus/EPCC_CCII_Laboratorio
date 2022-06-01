#ifndef ARREGLO_H_
#define ARREGLO_H_

#include <iostream>

template<typename T>
class Arreglo;

template <typename T>
std::ostream& operator<< (std::ostream &output, const Arreglo<T> &o);

template <typename T>
class Arreglo
{
    public:
        Arreglo();
        Arreglo(const T arr[], int size);
        Arreglo(const Arreglo<T> &o);
        void push_back(T elem);
        void push_top(T elem);
        void insert(T elem, int pos);
        void pop_back();
        void pop_top();
        void remove(int pos);
        T mayor() const;
        T menor() const;
        int getSize() const;
        T &operator[](int pos) const;
        friend std::ostream& operator<<<>(std::ostream &output, const Arreglo<T> &o);
        void clear();
        ~Arreglo();
    private:
        int size;
        T *arr;
        void resize(int newSize);
};

template <typename T>
Arreglo<T>::Arreglo()
{
    size = 0;
    arr = new T[0];
}

template <typename T>
Arreglo<T>::Arreglo(const T arr[], int size)
{
    this->size = size;
    this->arr = new T[size];

    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

template <typename T>
Arreglo<T>::Arreglo(const Arreglo<T> &o)
{
    this->size = o.size;
    this->arr = new T[o.size];

    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

template <typename T>
void Arreglo<T>::resize(int newSize)
{
    T *tmp = new T[newSize];
    int minSize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minSize; i++)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    size = newSize;
    arr = tmp;
}

template <typename T>
void Arreglo<T>::push_back(T elem)
{
    resize(size + 1);
    arr[size - 1] = elem;
}

template <typename T>
void Arreglo<T>::push_top(T elem)
{
    resize(size + 1);
    for(int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = elem;
}

template <typename T>
void Arreglo<T>::insert(T elem, int pos)
{
    if(pos >= 0 && pos <= size)
    {
        if(pos == 0)
        {
            push_top(elem);
        }
        else if(pos == size)
        {
            push_back(elem);
        }
        else
        {
            resize(size + 1);
            for(int i = size - 1; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = elem;

        }
    }
    else
    {
        throw std::invalid_argument("Posicion no valida.");
    }
}

template <typename T>
void Arreglo<T>::pop_back()
{
    if (size >= 0)
    {
        resize(size - 1);
    }
    else
    {
        throw std::invalid_argument("Posicion no valida.");
    }
}

template <typename T>
void Arreglo<T>::pop_top()
{
    if (size >= 0)
    {
        for(int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        resize(size - 1);
    }
    else
    {
        throw std::invalid_argument("Posicion no valida.");
    }
}

template <typename T>
void Arreglo<T>::remove(int pos)
{
    if(pos >= 1 && pos <= size)
    {
        if(pos == 0)
        {
            pop_top();
        }
        else if(pos == size - 1)
        {
            pop_back();
        }
        else
        {
            for(int i = pos; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            resize(size - 1);
        }
    }
    else
    {
        throw std::invalid_argument("Posicion no valida.");
    }
}

template <typename T>
int Arreglo<T>::getSize() const
{
    return size;
}

template <typename T>
T &Arreglo<T>::operator[] (int pos) const
{
    if(pos >= 0 && pos <= size - 1)
    {
        return arr[pos];
    }
    else
    {
        throw std::invalid_argument("Posicion no valida.");
    }
}

template <typename T>
T Arreglo<T>::mayor() const
{
    T aux{};
    aux = arr[0];
    for(int i = 0; i < getSize(); i++)
    {
        if(arr[i] > aux)
        {
            aux = arr[i];
        }
    }
    return aux;
}

template <typename T>
T Arreglo<T>::menor() const
{
    T aux{};
    aux = arr[0];
    for(int i = 0; i < getSize(); i++)
    {
        if(arr[i] < aux)
        {
            aux = arr[i];
        }
    }
    return aux;
}

template <typename T>
std::ostream& operator<< (std::ostream &output, const Arreglo<T> &o)
{
    output << "\n[" << '\t';
    for(int i = 0; i < o.getSize(); i++)
    {
        output << o.arr[i] << '\t';
    }
    output << "]" << std::endl;
    output << "\nEl mayor elemento del arreglo es: "
    << o.mayor()
    << "\nEl menor elemento del arreglo es: "
    << o.menor() << std::endl;
    return output;
}

template <typename T>
void Arreglo<T>::clear()
{
    resize(0);
}

template <typename T>
Arreglo<T>::~Arreglo() {
    delete[] arr;
}

#endif
