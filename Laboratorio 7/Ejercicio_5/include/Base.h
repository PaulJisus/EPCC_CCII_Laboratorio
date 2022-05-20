#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base
{
    public:
        Base();
        Base(double);
        Base(const Base &o);
        void setOperador(const double);
        double getOperador() const;
        ~Base();
    protected:
        double operador;
};

std::ostream& operator<< (std::ostream &output, const Base &o);

#endif
