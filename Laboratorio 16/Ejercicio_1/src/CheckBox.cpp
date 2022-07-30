#include "CheckBox.h"

//CheckBox::CheckBox()
//{
//    //ctor
//}
//
CheckBox::~CheckBox() = default;

WinFactory* CheckBox::CrearControlW() const
{
    return new WinCheckBox();
}

MacFactory* CheckBox::CrearControlM() const
{
    return new MacCheckBox();
}

LinuxFactory* CheckBox::CrearControlL() const
{
    return new LinuxCheckBox();
}
