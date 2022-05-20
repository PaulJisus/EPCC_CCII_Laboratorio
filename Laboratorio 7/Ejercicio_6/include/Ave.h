#ifndef AVE_H_
#define AVE_H_

#include <string>
#include <iostream>

class Ave
{
    public:
        Ave();
        Ave(std::string, std::string, std::string, std::string, std::string,
            std::string, std::string, std::string, std::string, double, double);
        Ave(const Ave &o);
        void setOrden(const std::string);
        std::string getOrden() const;
        void setFamilia(const std::string);
        std::string getFamilia() const;
        void setSubfamilia(const std::string);
        std::string getSubfamilia() const;
        void setGenero(const std::string);
        std::string getGenero() const;
        void setEspecie(const std::string);
        std::string getEspecie() const;
        void setSubespecie(const std::string);
        std::string getSubespecie() const;
        void setNombre(const std::string);
        std::string getNombre() const;
        void setHabitat(const std::string);
        std::string getHabitat() const;
        void setSexo(const std::string);
        std::string getSexo() const;
        void setPeso(const double);
        double getPeso() const;
        void setSize(const double);
        double getSize() const;
        ~Ave();
    private:
        std::string orden;
        std::string familia;
        std::string subfamilia;
        std::string genero;
        std::string especie;
        std::string subespecie;
        std::string nombre;
        std::string habitat;
        std::string sexo;
        double peso;
        double size;
};

std::ostream& operator<< (std::ostream &output, const Ave &o);

#endif
