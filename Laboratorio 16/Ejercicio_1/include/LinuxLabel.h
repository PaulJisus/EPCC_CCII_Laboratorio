#ifndef LINUXLABEL_H_
#define LINUXLABEL_H_

#include <string>

#include "LinuxFactory.h"

class LinuxLabel: public LinuxFactory
{
    public:
        std::string Draw() const override;
};

#endif
