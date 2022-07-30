#ifndef MACSWITCH_H_
#define MACSWITCH_H_

#include <string>

#include "MacFactory.h"

class MacSwitch: public MacFactory
{
    public:
        std::string Draw() const override;
        std::string draw(const WinFactory&) const override;
};

#endif
