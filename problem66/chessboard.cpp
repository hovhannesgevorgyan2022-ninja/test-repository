#include <iostream>
#include "chessboard.h"

Chessboard::Chessboard(): Matrix(8){
    std::cout << "Call Chessboard Constructor" << std::endl;
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            if((i+j)%2 == 0)
                m_mat[i][j] = 1;
            else
                m_mat[i][j] = 0;
        }
    }
}
Chessboard::~Chessboard(){
    std::cout << "Call Chessboard Destructor" << std::endl;
}