#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <iostream>
#include <string>

class Producto
{
    public:
        Producto();
        Producto(std::string, std::string, double, int);
        Producto(const Producto &);
        void setCodigo(const std::string);
        std::string getCodigo() const;
        void setNombre(const std::string);
        std::string getNombre() const;
        void setPrecio(const double);
        double getPrecio() const;
        void setStock(const int);
        int getStock() const;
        void setDisponibilidad(const bool);
        bool getDisponibilidad() const;
        ~Producto();
    private:
        std::string codigo;
        std::string nombre;
        double precio;
        int stock;
        bool disponibilidad;
};

std::ostream& operator<<(std::ostream &output, const Producto &o);

#endif
