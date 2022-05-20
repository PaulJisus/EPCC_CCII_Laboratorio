#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

class Color
{
    public:
        Color();
        Color(int, int, int);
        Color(const Color &o);
        void setRed(const int);
        int getRed() const;
        void setGreen(const int);
        int getGreen() const;
        void setBlue(const int);
        int getBlue() const;
        ~Color();
    private:
        int red;
        int green;
        int blue;
};

std::ostream& operator<< (std::ostream &output, const Color &o);

#endif
