#include <iostream>

#include "GUIFactory.h"
#include "Button.h"
#include "CheckBox.h"

using namespace std;

void Application(const GUIFactory&, int);

int main()
{
    std::cout << "Cliente: Windows\n";
    Button* f1 = new Button();
    Application(*f1, 1); // 1 - Windows
    delete f1;
    std::cout << std::endl;
    std::cout << "Cliente: Mac\n";
    Button* f2 = new Button();
    Application(*f2, 2); // 2 - Mac
    delete f2;
    return 0;
}

void Application(const GUIFactory& f, int os)
{
	if(os == 1)
    {
		const WinFactory* control_w = f.CrearControlW();
		std::cout << control_w->Draw() << "\n";
		delete control_w;
	}
	else if(os == 2)
	{
		const MacFactory* control_m = f.CrearControlM();
		std::cout << control_m->Draw() << "\n";
		delete control_m;
	}
	else if(os == 3)
	{
		const LinuxFactory* control_l = f.CrearControlL();
		std::cout << control_l->Draw() << "\n";
		delete control_l;
	}
	else
	{
		throw std::invalid_argument("SO invalido");
	}
}
