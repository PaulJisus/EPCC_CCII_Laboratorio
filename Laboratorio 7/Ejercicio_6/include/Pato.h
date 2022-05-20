#ifndef PATO_H_
#define PATO_H_

#include <string>
#include <iostream>

#include "Ave.h"

class Pato: public Ave
{
    public:
        Pato();
        Pato(std::string, std::string, std::string, std::string, std::string,
            std::string, std::string, std::string, std::string, double, double);
        Pato(const Pato &o);
        ~Pato();
};

std::ostream& operator<< (std::ostream &output, const Pato &o);

#endif
