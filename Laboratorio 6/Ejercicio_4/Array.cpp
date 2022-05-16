#include "Array.h"

template <typename T>
Array<T>::Array()
{
    size = 0;
    arr = new T[0];
}

template <typename T>
Array<T>::Array(const T arr[], int size)
{
    this->size = size;
    this->arr = new T[size];
    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

template <typename T>
Array<T>::Array(const Array<T> &o)
{
    this->size = o.size;
    this->arr = new T[o.size];
    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

template <typename T>
void Array<T>::resize(int newSize)
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
void Array<T>::push_back(T elem)
{
    resize(size + 1);
    arr[size - 1] = elem;
}

template <typename T>
void Array<T>::push_top(T elem)
{
    resize(size + 1);
    for(int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = elem;
}

template <typename T>
void Array<T>::insert(T elem, int pos)
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
        std::cout << "Posicion no valida.\n";
    }
}

template <typename T>
void Array<T>::pop_back()
{
    if (size >= 0)
    {
        resize(size - 1);
    }
    else
    {
        std::cout << "Posicion no valida.\n";
    }
}

template <typename T>
void Array<T>::pop_top()
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
        std::cout << "Posicion no valida.\n";
    }
}

template <typename T>
void Array<T>::remove(int pos)
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
        std::cout << "Posicion no valida.\n";
    }
}

template <typename T>
int Array<T>::getSize() const
{
    return size;
}

template <typename T>
T &Array<T>::operator[] (int pos) const
{
    if(pos >= 0 && pos <= size - 1)
    {
        return arr[pos];
    }
    else
    {
        std::cout << "Posicion no valida.\n";
    }
}

template <typename T>
void Array<T>::clear()
{
    resize(0);
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
std::ostream& operator<< (std::ostream &output, const Array<T> &o)
{
    output << "[" << std::endl;
    for(int i = 0; i < o.getSize(); i++)
    {
        output << o.arr[i] << std::endl;
    }
    output << "]" << std::endl;
    return output;
}
