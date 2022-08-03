#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <utility>
#include <chrono>

using namespace std;

template <class T>
class Arbol;

template <class T>
class Nodo
{
    friend class Arbol<T>;
    private:
        T data;
        Nodo<T> *derecho;
        Nodo<T> *izquierdo;
    public:
        Nodo(T valor);
};

template <class T>
Nodo<T>::Nodo(T valor)
{
    data = valor;
    izquierdo = nullptr;
    derecho = nullptr;
}

template <class T>
class Arbol
{
    public:
        Arbol();
        bool Find(T data);
        void Insert(T data);
        Nodo<T> *Insert(Nodo<T> *nodo, T data);
        Nodo<T> *minNodo(Nodo<T> *nodo);
        Nodo<T> *maxNodo(Nodo<T> *nodo);
        void Delete(T data);
        Nodo<T> *Delete(Nodo<T> *nodo, T data);
        void mostrar();
        void mostrar(Nodo<T> *nodo, int nivel);
        //int remove(int data);
        void preOrder();
        void preOrder(Nodo<T> *nodo);
        void postOrder();
        void postOrder(Nodo<T> *nodo);
        void inOrder();
        void inOrder(Nodo<T> *nodo);
    private:
        Nodo<T> *raiz;
};

template <class T>
Arbol<T>::Arbol()
{
    raiz = nullptr;
}

template <class T>
bool Arbol<T>::Find(T data)
{
    Nodo<T> *aux = raiz;
    while(aux != nullptr)
    {
        if(aux->data == data)
        {
            return true;
        }
        else
        {
            aux = aux->data>data? aux->izquierdo : aux->derecho;
        }
    }
    throw std::invalid_argument("Elemento no existente.\n");
    return false;
}

template <class T>
void Arbol<T>::Insert(T data)
{
    raiz = Insert(raiz, data);
}

template <class T>
Nodo<T>* Arbol<T>::Insert(Nodo<T> *nodo, T data)
{
    if(nodo == nullptr)
    {
        return (new Nodo<T>(data));
    }
    if(data < nodo->data)
    {
        nodo->izquierdo = Insert(nodo->izquierdo, data);
    }
    else if(data > nodo->data)
    {
        nodo->derecho = Insert(nodo->derecho, data);
    }
    return nodo;
}

template <class T>
Nodo<T>* Arbol<T>::minNodo(Nodo<T> *nodo)
{
    Nodo<T> *aux = nodo;
    while(aux->izquierdo != nullptr)
    {
        aux = aux->izquierdo;
    }
    return aux;
}

template <class T>
Nodo<T>* Arbol<T>::maxNodo(Nodo<T> *nodo)
{
    Nodo<T> *aux = nodo;
    while(aux->derecho != nullptr)
    {
        aux = aux->derecho;
    }
    return aux;
}

template <class T>
void Arbol<T>::Delete(T data)
{
    raiz = Delete(raiz, data);
}

template <class T>
Nodo<T>* Arbol<T>::Delete(Nodo<T> *nodo, T data)
{
    if(nodo == nullptr)
    {
        return nodo;
    }
    if(data < nodo->data)
    {
        nodo->izquierdo = Delete(nodo->izquierdo, data);
    }
    else if(data > nodo->data)
    {
        nodo->derecho = Delete(nodo->derecho, data);
    }
    else
    {
        if((nodo->izquierdo == nullptr) || (nodo->derecho == nullptr))
        {
            Nodo<T> *tmp = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;
            if(tmp == nullptr)
            {
                tmp = nodo;
                nodo = nullptr;
            }
            else
            {
                *nodo = *tmp;
            }
            delete tmp;
        }
        else
        {
            char opc;
            std::cout << "Eliminar por Predecesor o Sucesor: " << std::endl;
            std::cout << "Predecesor (S/N)" << std::endl;
            std::cin >> opc;
            std::cin.ignore();
            if(opc == 'S'|| opc == 's' || opc == 'SI' || opc == 'si' || opc == 'Si' || opc == 'sI')
            {
                Nodo<T> *tmp = maxNodo(nodo->izquierdo);
                nodo->data = tmp->data;
                nodo->izquierdo = Delete(nodo->izquierdo, tmp->data);
            }
            else
            {
                Nodo<T> *tmp = minNodo(nodo->derecho);
                nodo->data = tmp->data;
                nodo->derecho = Delete(nodo->derecho, tmp->data);
            }
        }
    }
    return nodo;
}

template <class T>
void Arbol<T>::mostrar()
{
    std::cout << "\n";
    mostrar(raiz, 1);
    std::cout << "\n";
}

template <class T>
void Arbol<T>::mostrar(Nodo<T> *nodo, int nivel)
{
    int i;
    if(nodo != nullptr)
    {
        mostrar(nodo->derecho, nivel + 1);
        std::cout << "\n";
        if(nodo == raiz)
        {
            std::cout << "Raiz -> ";
        }
        for(i = 0; i < nivel && nodo != raiz; i++)
        {
            std::cout << "     ";
        }
        std::cout << nodo->data;
        mostrar(nodo->izquierdo, nivel + 1);
    }
}

template <class T>
void Arbol<T>::preOrder()
{
    std::cout << std::endl;
    preOrder(raiz);
    std::cout << std::endl;
}

template <class T>
void Arbol<T>::preOrder(Nodo<T> *nodo)
{
    if(nodo != nullptr)
    {
        std::cout << nodo->data << " -> ";
        preOrder(nodo->izquierdo);
        preOrder(nodo->derecho);
    }
}

template <class T>
void Arbol<T>::postOrder()
{
    std::cout << std::endl;
    postOrder(raiz);
    std::cout << std::endl;
}

template <class T>
void Arbol<T>::postOrder(Nodo<T> *nodo)
{
    if(nodo != nullptr)
    {
        postOrder(nodo->izquierdo);
        postOrder(nodo->derecho);
        std::cout << nodo->data << " -> ";
    }
}

template <class T>
void Arbol<T>::inOrder()
{
    std::cout << std::endl;
    inOrder(raiz);
    std::cout << std::endl;
}

template <class T>
void Arbol<T>::inOrder(Nodo<T> *nodo)
{
    if(nodo != nullptr)
    {
        inOrder(nodo->izquierdo);
        std::cout << nodo->data << " -> ";
        inOrder(nodo->derecho);
    }
}

void menu()
{
    std::cout << "\n\t\t\t|-------------------------------------------------------|\n";
    std::cout << "\t\t\t|\t\tARBOL BINARIO DE BUSQUEDA\t\t|\n";
    std::cout << "\t\t\t|-------------------------------------------------------|\n";
    std::cout << "\t\t\t|     Opcion \t\t|\tTipo de Arbol\t\t|\n";
    std::cout << "\t\t\t|-------------------------------------------------------|\n";
    std::cout << "\t\t\t|\t1\t\t|\tINT\t\t\t|\n";
    std::cout << "\t\t\t|\t2\t\t|\tDOUBLE\t\t\t|\n";
    std::cout << "\t\t\t|\t3\t\t|\tCHAR\t\t\t|\n";
    std::cout << "\t\t\t|\t4\t\t|\tSTRING\t\t\t|\n";
    std::cout << "\t\t\t|\t5\t\t|\tSalir\t\t\t|\n";
    std::cout << "\t\t\t|-------------------------------------------------------|\n\n";
}

void submenu()
{
    cout << "\n\t\t\t|-------------------------------------------------------|\n";
    cout << "\t\t\t|\t\tARBOL BINARIO DE BUSQUEDA\t\t|\n";
    cout << "\t\t\t|-------------------------------------------------------|\n";
    cout << "\t\t\t|     opcion \t\t|\toperacion\t\t|\n";
    cout << "\t\t\t|-------------------------------------------------------|\n";
    cout << "\t\t\t|\t1\t\t|\tInsertar\t\t|\n";
    cout << "\t\t\t|\t2\t\t|\tEliminar\t\t|\n";
    cout << "\t\t\t|\t3\t\t|\tBuscar\t\t\t|\n";
    cout << "\t\t\t|\t4\t\t|\tPreOrden\t\t|\n";
    cout << "\t\t\t|\t5\t\t|\tPostOrden\t\t|\n";
    cout << "\t\t\t|\t6\t\t|\tInOrden\t\t\t|\n";
    cout << "\t\t\t|\t7\t\t|\tSalir\t\t\t|\n";
    cout << "\t\t\t|-------------------------------------------------------|\n\n";
}

static auto rng = []{
    std::mt19937 rng;
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    return rng;
}();

template <typename T,
          template<typename> typename Distribution
                                      = std::uniform_int_distribution,
          typename... Args>
T random(Args&&... args)
{
    Distribution<T> dist(std::forward<Args>(args)...);
    return dist(rng);
}

int main()
{
    Arbol<int> arbol1;
    Arbol<double> arbol2;
    Arbol<char> arbol3;
    Arbol<string> arbol4;
    int opcion;
    int subopcion;
    int entero1;
    double real1;
    char caracter1;
    string cadena1;

/* Parte del codigo para utilizar en el ejemplo del problema */
//    for(int i{0}; i < 100; i++)
//    {
//        arbol2.Insert(random<double, std::normal_distribution>(-100, 100));
//    }
//    std::cout << "\nArbol Original.\n";
//    arbol2.mostrar();
//    std::cout << "\nRecorrido inOrder.\n";
//    arbol2.inOrder();
//    std::cout << "\nRecorrido postOrder.\n";
//    arbol2.postOrder();
//    std::cout << "\nRecorrido preOrder.\n";
//    arbol2.preOrder();

    menu();
    cout << "\nIngresar el numero del tipo de arbol:" << endl;
    cin >> opcion;
    while(opcion != 5)
    {
        switch(opcion)
        {
            case 1: cout << "Arbol de enteros" << endl;
                    submenu();
                    cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                    cin >> subopcion;
                    while(subopcion != 7)
                    {
                        switch(subopcion)
                        {
                            case 1: cout << "Elemento a Insertar:" << endl;
                                    cin >> entero1;
                                    arbol1.Insert(entero1);
                                    arbol1.mostrar();
                                    break;
                            case 2: cout << "Elemento a Eliminar:" << endl;
                                    cin >> entero1;
                                    arbol1.Delete(entero1);
                                    arbol1.mostrar();
                                    break;
                            case 3: cout << "Elemento a Buscar:" << endl;
                                    cin >> entero1;
                                    arbol1.Find(entero1);
                                    arbol1.mostrar();
                                    break;
                            case 4: cout << "PreOrden:" << endl;
                                    arbol1.preOrder();
                                    break;
                            case 5: cout << "PostOrden:" << endl;
                                    arbol1.postOrder();
                                    break;
                            case 6: cout << "InOrden:" << endl;
                                    arbol1.inOrder();
                                    break;
                            default: cout << "Opcion Invalida." << endl;
                        }
                        cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                        cin >> subopcion;
                    }
                    cout << "\nPrograma Finalizado." << endl;
                    break;
            case 2: cout << "Arbol de reales" << endl;
                    submenu();
                    cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                    cin >> subopcion;
                    while(subopcion != 7)
                    {
                        switch(subopcion)
                        {
                            case 1: cout << "Elemento a Insertar:" << endl;
                                    cin >> real1;
                                    arbol2.Insert(real1);
                                    arbol2.mostrar();
                                    break;
                            case 2: cout << "Elemento a Eliminar:" << endl;
                                    cin >> real1;
                                    arbol2.Delete(real1);
                                    arbol2.mostrar();
                                    break;
                            case 3: cout << "Elemento a Buscar:" << endl;
                                    cin >> real1;
                                    arbol2.Find(real1);
                                    arbol2.mostrar();
                                    break;
                            case 4: cout << "PreOrden:" << endl;
                                    arbol2.preOrder();
                                    break;
                            case 5: cout << "PostOrden:" << endl;
                                    arbol2.postOrder();
                                    break;
                            case 6: cout << "InOrden:" << endl;
                                    arbol2.inOrder();
                                    break;
                            default: cout << "Opcion Invalida." << endl;
                        }
                        cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                        cin >> subopcion;
                    }
                    cout << "\nPrograma Finalizado." << endl;
                    break;
            case 3: cout << "Arbol de caracteres" << endl;
                    submenu();
                    cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                    cin >> subopcion;
                    while(subopcion != 7)
                    {
                        switch(subopcion)
                        {
                            case 1: cout << "Elemento a Insertar:" << endl;
                                    cin >> caracter1;
                                    arbol2.Insert(caracter1);
                                    arbol2.mostrar();
                                    break;
                            case 2: cout << "Elemento a Eliminar:" << endl;
                                    cin >> caracter1;
                                    arbol2.Delete(caracter1);
                                    arbol2.mostrar();
                                    break;
                            case 3: cout << "Elemento a Buscar:" << endl;
                                    cin >> caracter1;
                                    arbol2.Find(caracter1);
                                    arbol2.mostrar();
                                    break;
                            case 4: cout << "PreOrden:" << endl;
                                    arbol2.preOrder();
                                    break;
                            case 5: cout << "PostOrden:" << endl;
                                    arbol2.postOrder();
                                    break;
                            case 6: cout << "InOrden:" << endl;
                                    arbol2.inOrder();
                                    break;
                            default: cout << "Opcion Invalida." << endl;
                        }
                        cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                        cin >> subopcion;
                    }
                    cout << "\nPrograma Finalizado." << endl;
                    break;
            case 4: cout << "Arbol de cadenas" << endl;
                    submenu();
                    cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                    cin >> subopcion;
                    while(subopcion != 7)
                    {
                        switch(subopcion)
                        {
                            case 1: cout << "Elemento a Insertar:" << endl;
                                    cin >> cadena1;
                                    arbol3.Insert(cadena1);
                                    arbol3.mostrar();
                                    break;
                            case 2: cout << "Elemento a Eliminar:" << endl;
                                    cin >> cadena1;
                                    arbol3.Delete(cadena1);
                                    arbol3.mostrar();
                                    break;
                            case 3: cout << "Elemento a Buscar:" << endl;
                                    cin >> cadena1;
                                    arbol3.Find(cadena1);
                                    arbol3.mostrar();
                                    break;
                            case 4: cout << "PreOrden:" << endl;
                                    arbol3.preOrder();
                                    break;
                            case 5: cout << "PostOrden:" << endl;
                                    arbol3.postOrder();
                                    break;
                            case 6: cout << "InOrden:" << endl;
                                    arbol3.inOrder();
                                    break;
                            default: cout << "Opcion Invalida." << endl;
                        }
                        cout << "\nIngresar el numero de la operacion a realizar:" << endl;
                        cin >> subopcion;
                    }
                    cout << "\nPrograma Finalizado." << endl;
                    break;
            default: cout << "Opcion Invalida." << endl;
        }
        menu();
        cout << "\nIngresar el numero del tipo de arbol:" << endl;
        cin >> opcion;
    }
    cout << "\nPrograma Finalizado." << endl;
    return 0;
}
