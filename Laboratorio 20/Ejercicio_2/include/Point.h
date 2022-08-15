#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point
{
    public:
        Point();
        Point(const double, const double);
        Point(const Point &);
        void X(const double);
        void Y(const double);
        double getX() const;
        double getY() const;
        void print() const;
        ~Point();
    private:
        double x{};
        double y{};
};

std::ostream& operator<<(std::ostream &, const Point &);

#endif

