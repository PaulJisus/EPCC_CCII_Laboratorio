#ifndef PERSONA_H_
#define PERSONA_H_

#include <string>
#include <iostream>

class Persona
{
    public:
        Persona();
        Persona(int, std::string, std::string, std::string, std::string, int, long long);
        Persona(const Persona &o);
        void setEdad(const int);
        int getEdad() const;
        void setNombres(const std::string);
        std::string getNombres() const;
        void setApellidos(const std::string);
        std::string getApellidos() const;
        void setDireccion(const std::string);
        std::string getDireccion() const;
        void setCorreo(const std::string);
        std::string getCorreo() const;
        void setDNI(const int);
        int getDNI() const;
        void setTelefono(const long long);
        long long getTelefono() const;
        ~Persona();
    private:
        int edad;
        std::string nombres;
        std::string apellidos;
        std::string direccion;
        std::string correo;
        int DNI;
        long long telefono;
};

std::ostream& operator<< (std::ostream &output, const Persona &o);

#endif
