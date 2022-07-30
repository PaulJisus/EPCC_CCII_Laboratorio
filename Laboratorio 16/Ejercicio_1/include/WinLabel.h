#ifndef WINLABEL_H_
#define WINLABEL_H_

#include <string>

#include "WinFactory.h"

class WinLabel: public WinFactory
{
    public:
        std::string Draw() const override;
};

#endif
