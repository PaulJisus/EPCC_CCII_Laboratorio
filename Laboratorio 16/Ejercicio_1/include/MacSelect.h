#ifndef MACSELECT_H_
#define MACSELECT_H_

#include <string>

#include "MacFactory.h"

class MacSelect: public MacFactory
{
    public:
        std::string Draw() const override;
        std::string draw(const WinFactory&) const override;
};

#endif
