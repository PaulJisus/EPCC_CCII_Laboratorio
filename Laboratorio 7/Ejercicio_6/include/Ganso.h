#ifndef GANSO_H_
#define GANSO_H_

#include <string>
#include <iostream>

#include "Ave.h"

class Ganso: public Ave
{
    public:
        Ganso();
        Ganso(std::string, std::string, std::string, std::string, std::string,
            std::string, std::string, std::string, std::string, double, double);
        Ganso(const Ganso &o);
        ~Ganso();
};

std::ostream& operator<< (std::ostream &output, const Ganso &o);

#endif
