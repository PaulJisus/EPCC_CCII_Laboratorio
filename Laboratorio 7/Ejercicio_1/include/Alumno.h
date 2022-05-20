#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <iostream>
#include <string>

#include "Persona.h"

class Alumno: public Persona
{
    public:
        Alumno();
        Alumno(int, std::string, std::string, std::string, std::string, int, long long, std::string, int);
        Alumno(const Alumno &o);
        void setCarrera(const std::string);
        std::string getCarrera() const;
        void setCUI(const int);
        int getCUI() const;
        ~Alumno();
    private:
        std::string carrera;
        int CUI;
};

std::ostream& operator<< (std::ostream &output, const Alumno &o);

#endif
