#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <string>
#include <iostream>

using namespace std;

class Alumno
{
    public:
        Alumno(int, std::string, std::string, double, double, double);
        ~Alumno();
        int getCUI() const;
        void setCUI(int);
        std::string getNombres() const;
        void setNombres(std::string);
        std::string getApellidos() const;
        void setApellidos(std::string);
        double getNota1() const;
        void setNota1(double);
        double getNota2() const;
        void setNota2(double);
        double getNota3() const;
        void setNota3(double);
        double getPromedio() const;
        friend std::ostream& operator << (std::ostream &output, const Alumno &a);
    private:
        int CUI;
        std::string Nombres;
        std::string Apellidos;
        double nota1;
        double nota2;
        double nota3;
};

#endif
