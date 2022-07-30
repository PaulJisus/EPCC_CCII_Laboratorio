#include "Button.h"

//Button::Button()
//{
//    //ctor
//}
//
Button::~Button() = default;

WinFactory* Button::CrearControlW() const
{
    return new WinButton();
}

MacFactory* Button::CrearControlM() const
{
    return new MacButton();
}

LinuxFactory* Button::CrearControlL() const
{
    return new LinuxButton();
}
