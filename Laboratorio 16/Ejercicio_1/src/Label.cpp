#include "Label.h"

//Label::Label()
//{
//    //ctor
//}
//
Label::~Label() = default;

WinFactory* Label::CrearControlW() const
{
    return new WinLabel();
}

MacFactory* Label::CrearControlM() const
{
    return new MacLabel();
}

LinuxFactory* Label::CrearControlL() const
{
    return new LinuxLabel();
}
