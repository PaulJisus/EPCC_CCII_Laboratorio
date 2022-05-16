#ifndef MATRIX_H_
#define MATRIX_H_

#include <random>
#include <iostream>
#include <chrono>

class Matrix
{
    public:
        Matrix(unsigned, unsigned);
        ~Matrix();
        void insert();
        double random(unsigned);
        void insert_random();
        void find();
        void find_position(unsigned, unsigned);
        void find_value(double);
        void print();
    private:
        unsigned row, column;
        double **matrix;
};

#endif
