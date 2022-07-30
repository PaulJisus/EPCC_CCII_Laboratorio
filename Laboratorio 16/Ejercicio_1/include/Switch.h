#ifndef SWITCH_H_
#define SWITCH_H_

#include "GUIFactory.h"
#include "WinSwitch.h"
#include "MacSwitch.h"
#include "LinuxSwitch.h"

class Switch: public GUIFactory
{
    public:
        WinFactory* CrearControlW() const override;
        MacFactory* CrearControlM() const override;
        LinuxFactory* CrearControlL() const override;
        virtual ~Switch();
};

#endif
