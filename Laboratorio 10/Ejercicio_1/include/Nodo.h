#ifndef NODO_H_
#define NODO_H_


class Nodo
{
    public:
        Nodo();
        Nodo(int);
        void setValor(const int);
        int getValor() const;
        void setSiguiente(Nodo *);
        Nodo *getSiguiente() const;
        ~Nodo();
    private:
        int valor;
        Nodo *siguiente;
};

#endif
