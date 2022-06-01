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
        void merge_a(T *, int, int, int);
        void mergeSort_a(T *, int, int);
        void merge_d(T *, int, int, int);
        void mergeSort_d(T *, int, int);
        void ordenarAscendentemente();
        void ordenarDescendentemente();
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
void Arreglo<T>::merge_a(T *num, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

    T *L = new T[n1];
	T *R = new T[n2];

	for (int i = 0; i < n1; i++)
    {
        *(L + i) = *(num + l + i);
    }
	for (int j = 0; j < n2; j++)
	{
	    *(R + j) = *(num + m + 1 + j);
	}
	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2)
    {
		if (*(L + i) <= *(R + j))
		{
			*(num + k) = *(L + i);
			i++;
		}
		else
		{
			*(num + k) = *(R + j);
			j++;
		}
		k++;
	}

	while (i < n1)
    {
		*(num + k) = *(L + i);
		i++;
		k++;
	}

	while (j < n2)
    {
		*(num + k) = *(R + j);
		j++;
		k++;
	}
	delete []L;
	delete []R;
}

template <typename T>
void Arreglo<T>::mergeSort_a(T *num,int l,int r)
{
	if(l >= r)
    {
		return;
	}
	int m = l + (r - l)/2;
	mergeSort_a(num,l,m);
	mergeSort_a(num,m+1,r);
	merge_a(num,l,m,r);
}

template <typename T>
void Arreglo<T>::merge_d(T *num, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

    T *L = new T[n1];
	T *R = new T[n2];

	for (int i = 0; i < n1; i++)
    {
        *(L + i) = *(num + l + i);
    }
	for (int j = 0; j < n2; j++)
	{
	    *(R + j) = *(num + m + 1 + j);
	}
	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2)
    {
		if (*(L + i) >= *(R + j))
		{
			*(num + k) = *(L + i);
			i++;
		}
		else
		{
			*(num + k) = *(R + j);
			j++;
		}
		k++;
	}

	while (i < n1)
    {
		*(num + k) = *(L + i);
		i++;
		k++;
	}

	while (j < n2)
    {
		*(num + k) = *(R + j);
		j++;
		k++;
	}
	delete []L;
	delete []R;
}

template <typename T>
void Arreglo<T>::mergeSort_d(T *num,int l,int r)
{
	if(l >= r)
    {
		return;
	}
	int m = l + (r - l)/2;
	mergeSort_d(num,l,m);
	mergeSort_d(num,m+1,r);
	merge_d(num,l,m,r);
}

template <typename T>
void Arreglo<T>::ordenarAscendentemente()
{
    mergeSort_a(arr, 0, getSize() - 1);
}

template <typename T>
void Arreglo<T>::ordenarDescendentemente()
{
    mergeSort_d(arr, 0, getSize() - 1);
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
//    output << "\nEl mayor elemento del arreglo es: "
//    << o.mayor()
//    << "\nEl menor elemento del arreglo es: "
//    << o.menor() << std::endl;
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
