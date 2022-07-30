#ifndef SELECT_H_
#define SELECT_H_

#include "GUIFactory.h"
#include "WinSelect.h"
#include "MacSelect.h"
#include "LinuxSelect.h"

class Select: public GUIFactory
{
    public:
        WinFactory* CrearControlW() const override;
        MacFactory* CrearControlM() const override;
        LinuxFactory* CrearControlL() const override;
        virtual ~Select();
};

#endif
