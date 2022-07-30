#ifndef LINUXSELECT_H_
#define LINUXSELECT_H_

#include <string>

#include "LinuxFactory.h"

class LinuxSelect: public LinuxFactory
{
    public:
        std::string Draw() const override;
};

#endif
