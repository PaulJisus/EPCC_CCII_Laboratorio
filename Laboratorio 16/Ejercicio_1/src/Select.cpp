#include "Select.h"
//
//Select::Select()
//{
//    //ctor
//}
//
Select::~Select() = default;

WinFactory* Select::CrearControlW() const
{
    return new WinSelect();
}

MacFactory* Select::CrearControlM() const
{
    return new MacSelect();
}

LinuxFactory* Select::CrearControlL() const
{
    return new LinuxSelect();
}
