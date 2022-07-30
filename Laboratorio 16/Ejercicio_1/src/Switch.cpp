#include "Switch.h"

//Switch::Switch()
//{
//    //ctor
//}
//
Switch::~Switch() = default;

WinFactory* Switch::CrearControlW() const
{
    return new WinSwitch();
}

MacFactory* Switch::CrearControlM() const
{
    return new MacSwitch();
}

LinuxFactory* Switch::CrearControlL() const
{
    return new LinuxSwitch();
}
