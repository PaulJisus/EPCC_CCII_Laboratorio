#ifndef WINSELECT_H_
#define WINSELECT_H_

#include <string>

#include "WinFactory.h"

class WinSelect: public WinFactory
{
    public:
         std::string Draw() const override;
};

#endif
