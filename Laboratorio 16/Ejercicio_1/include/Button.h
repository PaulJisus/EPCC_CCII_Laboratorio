#ifndef BUTTON_H_
#define BUTTON_H_

#include "GUIFactory.h"
#include "WinButton.h"
#include "MacButton.h"
#include "LinuxButton.h"

class Button: public GUIFactory
{
    public:
        WinFactory* CrearControlW() const override;
        MacFactory* CrearControlM() const override;
        LinuxFactory* CrearControlL() const override;
        virtual ~Button();
};

#endif
