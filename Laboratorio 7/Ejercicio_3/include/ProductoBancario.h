#ifndef PRODUCTOBANCARIO_H_
#define PRODUCTOBANCARIO_H_

#include <string>
#include <iostream>

class ProductoBancario
{
    public:
        ProductoBancario();
        ProductoBancario(std::string, double);
        ProductoBancario(const ProductoBancario &o);
        void imprimir();
        ~ProductoBancario();
    private:
        std::string cliente;
    protected:
        double saldo;
    public:
        inline static int numProductos;
};

#endif
