#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>
#include <iostream>

class Material
{
    public:
        Material();
        Material(std::string);
        Material(const Material &o);
        void setTipo(const std::string);
        std::string getTipo() const;
        ~Material();
    private:
        std::string tipo;
};

std::ostream& operator<< (std::ostream &output, const Material &o);

#endif
