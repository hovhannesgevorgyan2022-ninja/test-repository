#include <iostream>
int** matrix_creator(int x , int y)
{
    int** matrix = new int*[x];
    for(int i =0 ; i < x ; i++)
    {
        matrix[i] = new int[y];
    }
    return matrix;
}

void matrix_printer(int** matrix , int x , int y)
{
    srand(time(0));
    for(int i =0 ; i < x ; i++)
    {
        for(int j =0 ; j < y ; j++)
        {
            matrix[i][j] = rand()%100;
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

int main(int argc , char* argv[])
{
    int x , y;
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    int** matrix;
    matrix = matrix_creator(x , y);
    matrix_printer(matrix , x , y);
    return 0;
}