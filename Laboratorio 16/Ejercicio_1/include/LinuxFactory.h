#ifndef LINUXFACTORY_H_
#define LINUXFACTORY_H_

#include <string>

class LinuxFactory
{
    public:
        virtual std::string Draw() const = 0;
        virtual ~LinuxFactory() {};
};

#endif
