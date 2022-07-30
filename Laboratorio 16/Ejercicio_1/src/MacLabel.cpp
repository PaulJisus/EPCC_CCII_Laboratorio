#include "MacLabel.h"

//MacLabel::MacLabel()
//{
//    //ctor
//}
//
//MacLabel::~MacLabel()
//{
//    //dtor
//}

std::string MacLabel::Draw() const
{
    return "Dibujando Label Mac";
}

std::string MacLabel::draw(const WinFactory& colaborador) const
{
    const std::string result = colaborador.Draw();
    return "Select Label con ayuda de " + result;
}
