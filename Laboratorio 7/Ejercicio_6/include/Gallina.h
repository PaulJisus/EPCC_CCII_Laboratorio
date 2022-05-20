#ifndef GALLINA_H_
#define GALLINA_H_

#include <string>
#include <iostream>

#include "Ave.h"

class Gallina: public Ave
{
    public:
        Gallina();
        Gallina(std::string, std::string, std::string, std::string, std::string,
            std::string, std::string, std::string, std::string, double, double);
        Gallina(const Gallina &o);
        ~Gallina();
};

std::ostream& operator<< (std::ostream &output, const Gallina &o);

#endif
