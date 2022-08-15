#ifndef C2_H_
#define C2_H_

#include <memory>
#include <iostream>

class C2
{
    public:
        C2();
        C2(std::shared_ptr<double>);
        C2(const C2 &);
        std::shared_ptr<double> getD() const;
        virtual ~C2();
        void print() const;
    private:
        std::weak_ptr<double> d;
};

std::ostream& operator<<(std::ostream &, const C2 &);

#endif
