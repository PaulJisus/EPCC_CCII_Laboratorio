#include "MacCheckBox.h"

//MacCheckBox::MacCheckBox()
//{
//    //ctor
//}
//
//MacCheckBox::~MacCheckBox()
//{
//    //dtor
//}

std::string MacCheckBox::Draw() const
{
    return "Dibujando CheckBox Mac";
}

std::string MacCheckBox::draw(const WinFactory& colaborador) const
{
    const std::string result = colaborador.Draw();
    return "CheckBox Mac con ayuda de " + result;
}
