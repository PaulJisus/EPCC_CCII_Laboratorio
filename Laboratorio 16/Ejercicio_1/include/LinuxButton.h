#ifndef LINUXBUTTON_H_
#define LINUXBUTTON_H_

#include <string>

#include "LinuxFactory.h"

class LinuxButton: public LinuxFactory
{
    public:
        std::string Draw() const override;
};

#endif
