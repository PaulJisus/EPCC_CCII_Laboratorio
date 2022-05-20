#ifndef OBJETO_H_
#define OBJETO_H_

#include <string>
#include <iostream>

#include "Color.h"
#include "Material.h"

class Objeto: public Material, public Color
{
    public:
        Objeto();
        Objeto(int, int, int, std::string, std::string);
        Objeto(const Objeto &o);
        void setNombre(const std::string);
        std::string getNombre() const;
        ~Objeto();
    private:
        std::string nombre;
};

std::ostream& operator<< (std::ostream &output, const Objeto &o);

#endif
