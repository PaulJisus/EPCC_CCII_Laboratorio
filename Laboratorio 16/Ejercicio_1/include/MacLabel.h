#ifndef MACLABEL_H_
#define MACLABEL_H_

#include <string>

#include "MacFactory.h"

class MacLabel: public MacFactory
{
    public:
        std::string Draw() const override;
        std::string draw(const WinFactory&) const override;
};

#endif
