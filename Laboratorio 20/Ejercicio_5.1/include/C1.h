#ifndef C1_H_
#define C1_H_

#include <memory>
#include <iostream>

class C1
{
    public:
        C1();
        C1(std::shared_ptr<double>);
        C1(const C1 &);
        std::shared_ptr<double> getD() const;
        virtual ~C1();
        void print() const;
    private:
        std::weak_ptr<double> d;
};

std::ostream& operator<<(std::ostream &, const C1 &);

#endif
