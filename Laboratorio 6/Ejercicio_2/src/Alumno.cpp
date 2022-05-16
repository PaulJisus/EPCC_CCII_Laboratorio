#include "Alumno.h"

Alumno::Alumno(int c, std::string n, std::string a, double n1, double n2, double n3):
CUI(c), Nombres(n), Apellidos(a), nota1(n1), nota2(n2), nota3(n3)
{

}

Alumno::~Alumno()
{

}

int Alumno::getCUI() const
{
    return CUI;
}

void Alumno::setCUI(int CUI)
{
    this->CUI = CUI;
}

std::string Alumno::getNombres() const
{
    return Nombres;
}

void Alumno::setNombres(std::string Nombres)
{
    this->Nombres = Nombres;
}

std::string Alumno::getApellidos() const
{
    return Apellidos;
}

void Alumno::setApellidos(std::string Apellidos)
{
    this->Apellidos = Apellidos;
}

double Alumno::getNota1() const
{
    return nota1;
}

void Alumno::setNota1(double nota1)
{
    this->nota1 = nota1;
}

double Alumno::getNota2() const
{
    return nota2;
}

void Alumno::setNota2(double nota2)
{
    this->nota2 = nota2;
}

double Alumno::getNota3() const
{
    return nota3;
}

void Alumno::setNota3(double nota3)
{
    this->nota3 = nota3;
}

double Alumno::getPromedio() const
{
    return (getNota1() + getNota2() + getNota3()) / 3;
}

std::ostream& operator << (std::ostream &output, const Alumno &a)
{
    output << "Nombre: " << a.getNombres() << "\tPromedio: " << a.getPromedio();
    if(a.getPromedio() >= 10.5)
        output << "\tAprobo\n";
    else
        output << "\tNo Aprobo\n";
    return output;
}
