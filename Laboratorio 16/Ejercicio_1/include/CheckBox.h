#ifndef CHECKBOX_H_
#define CHECKBOX_H_

#include "GUIFactory.h"
#include "WinCheckBox.h"
#include "MacCheckBox.h"
#include "LinuxCheckBox.h"

class CheckBox: public GUIFactory
{
    public:
        WinFactory* CrearControlW() const override;
        MacFactory* CrearControlM() const override;
        LinuxFactory* CrearControlL() const override;
        virtual ~CheckBox();
};

#endif
