#include <iostream>
#include "chessboard.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        std::cout << "Please specify coordinates file path: " << std::endl;
    ChessBoard board(argv[1]);
    board.simulate();
    
    // board.print();

    return 0;
}