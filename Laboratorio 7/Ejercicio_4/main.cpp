#include <iostream>

#include "Disco.h"

using namespace std;

int main()
{
    Disco d1("audio", "musica", "Collage", "cd", "m4a", 2016, "The Chainsmokers", "Disruptor Records and Columbia Records", 1);
    std::cout << d1;
    return 0;
}
