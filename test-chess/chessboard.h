#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <vector>
#include <algorithm>

class Figure;
enum COLOR : int;

constexpr int   WIDTH = 8;
constexpr int   HEIGHT = 8;

class ChessBoard 
{
private:
    mutable Figure*   m_board[WIDTH][HEIGHT];
    std::vector<Figure*>  m_whites;
    std::vector<Figure*>  m_blacks;
protected:
    bool    read_file(const char *path);
    bool    is_valid() const;
public:
    ChessBoard(const char *path);
    ~ChessBoard();
    void    print() const;
    bool    is_check(COLOR col) const;
    bool    is_mate(COLOR col);
    void    simulate();
    bool    is_free(int x , int y) const;
    bool    is_under_attack(int x , int y , COLOR col) const;
    bool    is_placed_oppenent_figure(int x , int y , COLOR col) const;
    friend class Figure;
};

#endif