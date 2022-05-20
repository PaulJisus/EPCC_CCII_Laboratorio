#ifndef FACTORIAL_H_
#define FACTORIAL_H_

#include <iostream>

#include "Base.h"

class Factorial: public Base
{
    public:
        Factorial();
        Factorial(double);
        Factorial(const Factorial &o);
        long long devolverFactorial() const;
        ~Factorial();
};

Base operator+ (const Factorial &o, const Factorial &p);
Base operator- (const Factorial &o, const Factorial &p);
Base operator* (const Factorial &o, const Factorial &p);
Base operator/ (const Factorial &o, const Factorial &p);

std::ostream& operator<< (std::ostream &output, const Factorial &o);

#endif
