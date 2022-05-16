#include <iostream>

#include "Matrix.h"

using namespace std;

int main()
{
    Matrix m1(3, 3);
    m1.insert_random();
    m1.find();
    m1.find_position(2, 2);
    return 0;
}
