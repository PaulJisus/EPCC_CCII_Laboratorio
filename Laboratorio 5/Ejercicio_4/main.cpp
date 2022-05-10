#include <iostream>
#include <ctime>
#include <locale.h>

template <class T>

class Nodo
{
    public:
        Nodo();
        Nodo(T);
        ~Nodo();

        Nodo *siguiente;
        T valor;

        void eliminar_todo();
        void mostrar();
};

// Constructor por defecto
template<typename T>

Nodo<T>::Nodo()
{
    valor = nullptr;
    siguiente = nullptr;
}

// Constructor por parámetro
template<typename T>
Nodo<T>::Nodo(T valor_i)
{
    valor = valor_i;
    siguiente = nullptr;
}

// Eliminar todos los Nodos
template<typename T>
void Nodo<T>::eliminar_todo()
{
    if (siguiente)
        siguiente->eliminar_todo();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void Nodo<T>::mostrar()
{
    std::cout << valor << " -> ";
}

template<typename T>
Nodo<T>::~Nodo()
{

}

template <class T>

class Lista
{
    public:
        Lista();
        ~Lista();
        void insertar_inicio(T);
        void insertar_final(T);
        void insertar_posicion(T, int);
        void eliminar_todo();
        void eliminar_posicion(int);
        void mostrar();
        void buscar(T);
        void insertar_aleatorio(int);

    private:
        Nodo<T> *inicio;
        int size;
};

// Constructor por defecto
template<typename T>
Lista<T>::Lista()
{
    size = 0;
    inicio = nullptr;
}

// Insertar al inicio
template<typename T>
void Lista<T>::insertar_inicio(T valor_i)
{
    Nodo<T> *nuevo_nodo= new Nodo<T> (valor_i);
    Nodo<T> *aux = inicio;

    if (!inicio) {
        inicio = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = inicio;
        inicio = nuevo_nodo;

        while (aux) {
            aux = aux->siguiente;
        }
    }
    size++;
}

// Insertar al final
template<typename T>
void Lista<T>::insertar_final(T valor_i)
{
    Nodo<T> *nuevo_nodo = new Nodo<T> (valor_i);
    Nodo<T> *aux = inicio;

    if (!inicio) {
        inicio = nuevo_nodo;
    } else {
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
    size++;
}

// Insertar por posición
template<typename T>
void Lista<T>::insertar_posicion(T valor_i, int pos)
{
    Nodo<T> *nuevo_nodo = new Nodo<T> (valor_i);
    Nodo<T> *aux = inicio;
    if(pos == 1)
    {
        nuevo_nodo->siguiente = inicio;
        inicio = nuevo_nodo;
        return;
    }
    pos--;
    while(aux!= nullptr && --pos)
    {
        aux = aux->siguiente;
    }
    if(aux == nullptr)
    {
        return;
    }
    nuevo_nodo->siguiente = aux->siguiente;
    aux->siguiente = nuevo_nodo;
}

// Eliminar todos los nodos
template<typename T>
void Lista<T>::eliminar_todo()
{
    inicio->eliminar_todo();
    inicio = 0;
}

// Eliminar por posición del nodo
template<typename T>
void Lista<T>::eliminar_posicion(int pos)
{
    Nodo<T> *aux = inicio;
    Nodo<T> *aux1 = aux->siguiente;

    if (pos < 1 || pos > size) {
        std::cout << "Posición incorrecta" << std::endl;
    } else if (pos == 1) {
        inicio = aux->siguiente;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux2 = aux1;
                aux->siguiente = aux1->siguiente;
                delete aux2;
                size--;
            }
            aux = aux->siguiente;
            aux1 = aux1->siguiente;
        }
    }
}

// Imprimir la Lista
template<typename T>
void Lista<T>::mostrar()
{
    Nodo<T> *aux = inicio;
    if (!inicio) {
        std::cout << "Lista vacía " << std::endl;
    } else {
        while (aux) {
            aux->mostrar();
            if (!aux->siguiente) std::cout << "NULL";
                aux = aux->siguiente;
        }
  }
  std::cout << std::endl;
}

// Buscar el dato de un nodo
template<typename T>
void Lista<T>::buscar(T valor_i)
{
    Nodo<T> *aux = inicio;
    int contador1 = 1;
    int contador2 = 0;

    while (aux) {
        if (aux->valor == valor_i) {
            std::cout << "El valor se encuentra en la posición: " << contador1 << std::endl;
            contador2++;
        }
        aux = aux->siguiente;
        contador1++;
    }

    if (contador2 == 0) {
        std::cout << "No existe el valor " << std::endl;
    }
    std::cout << std::endl;
}

//insertar aleatoriamente
template<typename T>
void Lista<T>::insertar_aleatorio(int tam)
{
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        insertar_posicion(rand() % 100, rand()% size);
    }
}

template<typename T>
Lista<T>::~Lista()
{

}

int main()
{
    setlocale(LC_ALL, "spanish");
    Lista<int> lista_1;
    lista_1.mostrar();
    lista_1.insertar_inicio(1000);
    lista_1.mostrar();
    lista_1.insertar_inicio(100);
    lista_1.mostrar();
    lista_1.insertar_inicio(104);
    lista_1.mostrar();
    lista_1.insertar_final(105);
    lista_1.mostrar();
    lista_1.insertar_final(106);
    lista_1.mostrar();
    lista_1.insertar_inicio(23);
    lista_1.mostrar();
    lista_1.insertar_final(15);
    lista_1.mostrar();
    lista_1.insertar_aleatorio(10);
    lista_1.mostrar();
    lista_1.eliminar_posicion(1);
    lista_1.mostrar();
    lista_1.eliminar_posicion(12);
    lista_1.mostrar();
    lista_1.buscar(5);
    lista_1.insertar_posicion(8, 2);
    lista_1.mostrar();
    lista_1.insertar_aleatorio(100);
    lista_1.mostrar();
    lista_1.buscar(5);
}
