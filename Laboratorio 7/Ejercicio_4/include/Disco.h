#ifndef DISCO_H_
#define DISCO_H_

#include <string>
#include <iostream>

#include "Multimedia.h"

class Disco: public Multimedia
{
    public:
        Disco();
        Disco(std::string, std::string, std::string, std::string, std::string, int, std::string, std::string, int);
        Disco(const Disco &o);
        void setTitulo(const std::string);
        std::string getTitulo() const;
        void setTipod(const std::string);
        std::string getTipod() const;
        void setFormato(const std::string);
        std::string getFormato() const;
        void setAnio(const int);
        int getAnio() const;
        void setAutor(const std::string);
        std::string getAutor() const;
        void setCopyright(const std::string);
        std::string getCopyright() const;
        void setVolumen(const int);
        int getVolumen() const;
        ~Disco();
    private:
        std::string titulo;
        std::string tipod;
        std::string formato;
        int anio;
        std::string autor;
        std::string copyright;
        int volumen;
};

std::ostream& operator<< (std::ostream &output, const Disco &o);

#endif
