#include <iostream>
#include "matrix.h"
#include "chessboard.h"

int main()
{
    // Chessboard obj;
    // obj.print();
    // Chessboard obj2 = obj;

    Matrix m1(5);
    Matrix m2 = std::move(m1);

    Matrix m3(3);

    m3 = std::move(m1);

    Chessboard c1;
    Chessboard c2 = std::move(c1);


    return 0;
}