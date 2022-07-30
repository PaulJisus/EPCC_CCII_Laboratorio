#ifndef WINSWITCH_H_
#define WINSWITCH_H_

#include <string>

#include "WinFactory.h"

class WinSwitch: public WinFactory
{
    public:
         std::string Draw() const override;
};

#endif
