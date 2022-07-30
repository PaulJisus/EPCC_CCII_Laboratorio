#ifndef LINUXCHECKBOX_H_
#define LINUXCHECKBOX_H_

#include <string>

#include "LinuxFactory.h"

class LinuxCheckBox: public LinuxFactory
{
    public:
        std::string Draw() const override;
};

#endif
