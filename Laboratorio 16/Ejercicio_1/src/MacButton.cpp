#include "MacButton.h"

//MacButton::MacButton()
//{
//    //ctor
//}
//
//MacButton::~MacButton()
//{
//    //dtor
//}

std::string MacButton::Draw() const
{
    return "Dibujando Button Mac";
}

std::string MacButton::draw(const WinFactory& colaborador) const
{
    const std::string result = colaborador.Draw();
    return "Button Mac con ayuda de " + result;
}
