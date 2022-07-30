#ifndef WINBUTTON_H_
#define WINBUTTON_H_

#include <string>

#include "WinFactory.h"

class WinButton: public WinFactory
{
    public:
        std::string Draw() const override;
};

#endif
