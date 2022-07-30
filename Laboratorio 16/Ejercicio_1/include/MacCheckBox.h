#ifndef MACCHECKBOX_H_
#define MACCHECKBOX_H_

#include <string>

#include "MacFactory.h"

class MacCheckBox: public MacFactory
{
    public:
        std::string Draw() const override;
        std::string draw(const WinFactory&) const override;
};

#endif
