#ifndef GUIFACTORY_H_
#define GUIFACTORY_H_

#include "WinFactory.h"
#include "MacFactory.h"
#include "LinuxFactory.h"

class GUIFactory
{
    public:
        virtual WinFactory* CrearControlW() const = 0;
        virtual MacFactory* CrearControlM() const = 0;
        virtual LinuxFactory* CrearControlL() const = 0;
};

#endif
