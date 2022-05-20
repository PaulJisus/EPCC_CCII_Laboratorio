#include "Color.h"

Color::Color() = default;

Color::Color(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Color::Color(const Color &o)
{
    this->red = o.red;
    this->green = o.green;
    this->blue = o.blue;
}

void Color::setRed(const int red)
{
    this->red = red;
}

int Color::getRed() const
{
    return red;
}

void Color::setGreen(const int green)
{
    this->green = green;
}

int Color::getGreen() const
{
    return green;
}

void Color::setBlue(const int blue)
{
    this->blue = blue;
}

int Color::getBlue() const
{
    return blue;
}

Color::~Color()
{

}

std::ostream& operator<< (std::ostream &output, const Color &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "Color en RGB:" << std::endl
    << "\tRed:\t" << o.getRed() << std::endl
    << "\tGreen:\t" << o.getGreen() << std::endl
    << "\tBlue:\t" << o.getBlue() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
