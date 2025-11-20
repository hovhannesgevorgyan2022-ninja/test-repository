#include <iostream>
#include <fstream>
#include "matrix.h"
#include "reader.h"

int main()
{
    Reader read_obj("input.txt");
    Matrix* mat1 = read_obj.read_matrix();
    mat1->print();
    return 0;
}

