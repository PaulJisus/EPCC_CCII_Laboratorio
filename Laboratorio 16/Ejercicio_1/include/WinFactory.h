#ifndef WINFACTORY_H_
#define WINFACTORY_H_

#include <string>

class WinFactory
{
    public:
        virtual std::string Draw() const = 0;
        virtual ~WinFactory() {};
};

#endif
