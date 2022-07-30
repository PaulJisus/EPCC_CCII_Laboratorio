#ifndef MACBUTTON_H_
#define MACBUTTON_H_

#include <string>

#include "MacFactory.h"

class MacButton: public MacFactory
{
    public:
        std::string Draw() const override;
        std::string draw(const WinFactory&) const override;
};

#endif
