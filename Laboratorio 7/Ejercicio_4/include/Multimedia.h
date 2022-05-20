#ifndef MULTIMEDIA_H_
#define MULTIMEDIA_H_

#include <string>
#include <iostream>

class Multimedia
{
    public:
        Multimedia();
        Multimedia(std::string, std::string);
        void setTipom(const std::string);
        std::string getTipom() const;
        void setCategoria(const std::string);
        std::string getCategoria() const;
        Multimedia(const Multimedia &o);
        ~Multimedia();
    private:
        std::string tipom;
        std::string categoria;
};

std::ostream& operator<< (std::ostream &output, const Multimedia &o);

#endif
