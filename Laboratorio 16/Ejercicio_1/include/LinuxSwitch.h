#ifndef LINUXSWITCH_H_
#define LINUXSWITCH_H_

#include <string>

#include "LinuxFactory.h"

class LinuxSwitch: public LinuxFactory
{
    public:
        std::string Draw() const override;
};

#endif
