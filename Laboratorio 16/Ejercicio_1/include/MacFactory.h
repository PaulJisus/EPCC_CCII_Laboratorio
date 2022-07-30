#ifndef MACFACTORY_H_
#define MACFACTORY_H_

#include <string>

#include "WinFactory.h"

class MacFactory
{
    public:
        virtual std::string Draw() const = 0;
        virtual std::string draw(const WinFactory& colaborador) const = 0;
        virtual ~MacFactory() {};
};

#endif
