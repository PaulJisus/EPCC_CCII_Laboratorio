#include <iostream>
#include <sstream>

using namespace std;

string Hexadecimal(int num, std::ostringstream &ss)
{

    int x = num % 16;

    if (num == 0)
    {
        return ss.str();
    }

    switch (x)
    {
        case 10: ss << "A";  break;
        case 11: ss << "B";  break;
        case 12: ss << "C";  break;
        case 13: ss << "D";  break;
        case 14: ss << "E";  break;
        case 15: ss << "F";  break;
        default: ss << x;    break;
    }

    return Hexadecimal(num / 16, ss);

}

int main()
{
    std::ostringstream x;
    std::cout << Hexadecimal(123546, x) << "\n";
}
