#include "MacSwitch.h"

//MacSwitch::MacSwitch()
//{
//    //ctor
//}
//
//MacSwitch::~MacSwitch()
//{
//    //dtor
//}

std::string MacSwitch::Draw() const
{
    return "Dibujando Switch Mac";
}

std::string MacSwitch::draw(const WinFactory& colaborador) const
{
    const std::string result = colaborador.Draw();
    return "Switch Mac con ayuda de " + result;
}
