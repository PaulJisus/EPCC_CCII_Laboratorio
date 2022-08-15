#include "Point.h"

Point::Point() = default;

Point::Point(const double x, const double y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point &o)
{
    this->x = o.x;
    this->y = o.y;
}

void Point::X(const double x)
{
    this->x = x;
}

double Point::getX() const
{
    return this->x;
}

void Point::Y(const double y)
{
    this->y = y;
}

double Point::getY() const
{
    return this->y;
}

void Point::print() const
{
    std::cout << '(' << getX() << ", " << getY() << ")\n";
}

Point::~Point() = default;

std::ostream& operator<<(std::ostream &output, const Point &o)
{
    output << '(' << o.getX() << ", " << o.getY() << ")\n";
    return output;
}
