#ifndef WINCHECKBOX_H_
#define WINCHECKBOX_H_

#include <string>

#include "WinFactory.h"

class WinCheckBox: public WinFactory
{
    public:
        std::string Draw() const override;
};

#endif
