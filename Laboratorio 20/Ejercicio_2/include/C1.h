#ifndef C1_H_
#define C1_H_

#include <memory>
#include <iostream>

class C1
{
    public:
        C1(std::shared_ptr<double>);
        virtual ~C1();
        void print() const;
    private:
        std::shared_ptr<double> d;
};

#endif
