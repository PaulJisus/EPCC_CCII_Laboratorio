#ifndef LABEL_H_
#define LABEL_H_

#include "GUIFactory.h"
#include "WinLabel.h"
#include "MacLabel.h"
#include "LinuxLabel.h"

class Label: public GUIFactory
{
    public:
        WinFactory* CrearControlW() const override;
        MacFactory* CrearControlM() const override;
        LinuxFactory* CrearControlL() const override;
        virtual ~Label();
};

#endif
