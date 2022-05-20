#include "Alumno.h"

Alumno::Alumno(): Persona{}, CUI{}
{

}

Alumno::Alumno(int edad, std::string nombres, std::string apellidos, std::string direccion,
                 std::string correo, int DNI, long long telefono, std::string carrera, int CUI)
                : Persona(edad, nombres, apellidos, direccion, correo, DNI, telefono)
{
    this->carrera = carrera;
    this->CUI = CUI;
}

Alumno::Alumno(const Alumno &o): Persona(o)
{
    this->carrera = o.carrera;
    this->CUI = o.CUI;
}

void Alumno::setCarrera(const std::string carrera)
{
    this->carrera = carrera;
}

std::string Alumno::getCarrera() const
{
    return carrera;
}

void Alumno::setCUI(const int CUI)
{
    this->CUI = CUI;
}

int Alumno::getCUI() const
{
    return CUI;
}

Alumno::~Alumno()
{

}

std::ostream& operator<< (std::ostream &output, const Alumno &o)
{
    output << "\n---------------------------------------------------------" << std::endl
    << "\tNombres: " << o.getNombres() << std::endl
    << "\tApellidos: " << o.getApellidos() << std::endl
    << "\tD.N.I.: " << o.getDNI() << std::endl
    << "\tEdad: " << o.getEdad() << std::endl
    << "\tDireccion: " << o.getDireccion() << std::endl
    << "\tCorreo: " << o.getCorreo() << std::endl
    << "\tTelefono: " << o.getTelefono() << std::endl
    << "\tCarrera: " << o.getCarrera() << std::endl
    << "\tC.U.I.: " << o.getCUI() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
