#include "MacSelect.h"

//MacSelect::MacSelect()
//{
//    //ctor
//}
//
//MacSelect::~MacSelect()
//{
//    //dtor
//}

std::string MacSelect::Draw() const
{
    return "Dibujando Select Mac";
}

std::string MacSelect::draw(const WinFactory& colaborador) const
{
    const std::string result = colaborador.Draw();
    return "Select Mac con ayuda de " + result;
}
