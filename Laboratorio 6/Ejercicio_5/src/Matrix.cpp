#include "Matrix.h"

Matrix::Matrix(unsigned row, unsigned column)
{
    this->row = row;
    this->column = column;
    matrix = new double*[row];
    for(unsigned i = 0; i < row; i++)
    {
        matrix[i] = new double[column];
    }
}

Matrix::~Matrix()
{
    for(unsigned i = 0; i < row; i++)
    {
        delete matrix[i];
    }
    delete []matrix;
}

void Matrix::insert()
{
    std::cout<< "\nIngrese los elementos de la matriz:\n";
    for(unsigned i = 0; i < row; i++)
    {
        for(unsigned j = 0; j < column; j++)
        {
            std::cout << "\nElemento de la posicion [" << i << "][" << j << "]: ";
            std::cin >> *( *(matrix + i) + j);
        }
    }
}

double Matrix::random(unsigned n)
{
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);
    std::uniform_real_distribution<double> urd(0, (row*column) + n);
    return urd(eng);
}

void Matrix::insert_random()
{
    for(unsigned i = 0; i < row; i++)
    {
        for(unsigned j = 0; j < column; j++)
        {
            *( *(matrix + i) + j) = random(i*j);
        }
    }
}

void Matrix::find()
{
    for(unsigned i = 0; i < row; i++)
    {
        for(unsigned j = 0; j < column; j++)
        {
            std::cout << "\nElemento de la posicion [" << i << "][" << j << "]: ";
            std::cout << *( *(matrix + i) + j) << '\n';
        }
    }
}

void Matrix::find_position(unsigned r, unsigned c)
{
    for(unsigned i = 0; i < row; i++)
    {
        for(unsigned j = 0; j < column; j++)
        {
            if(i == r && j == c)
            {
                std::cout << "\nElemento encontrado en la posicion [" << i << "][" << j << "]: ";
                std::cout << *( *(matrix + i) + j) << '\n';
            }
        }
    }
}

void Matrix::find_value(double value)
{
    for(unsigned i = 0; i < row; i++)
    {
        for(unsigned j = 0; j < column; j++)
        {
            if(*( *(matrix + i) + j) == value)
            {
                std::cout << "\nElemento encontrado en la posicion [" << i << "][" << j << "]: ";
                std::cout << *( *(matrix + i) + j) << '\n';
            }
        }
    }
}

void Matrix::print()
{
    for(unsigned i = 0; i < row; i++)
    {
        std::cout << "\n[ ";
        for(unsigned j = 0; j < column; j++)
        {
            std::cout << *( *(matrix + i) + j) << '\t';
        }
        std::cout << " ]\n";
    }
}
