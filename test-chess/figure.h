#ifndef FIGURE_H
#define FIGURE_H
#include "chessboard.h"
#include <iostream>
#include <stack>

struct Point {
    int x;
    int y;
};

enum COLOR : int {
    WHITE = 1,
    BLACK
};

enum FIGURES {
    EMPTY = 0,
    KING,     // 1
    QUEEN,    // 2
    BISHOP,   // pix 3
    ROOK,     // nav 4
    KNIGHT,   // dzi 5
    PAWN      // 6
};

class Figure
{
protected:
    Point   m_coord;
    std::stack<Point> m_old_coords;
    std::stack<Figure *> m_capured_figs;
    FIGURES m_type;
    COLOR   m_color;
    ChessBoard  *m_chessboard;

public:
    Figure(const Point& p, FIGURES type, COLOR color, ChessBoard *board)
        : m_coord(p)
        , m_type(type)
        , m_color(color)
        , m_chessboard(board)
    {}
    virtual ~Figure()   {}
    int x() const   { return m_coord.x; }
    int y() const   { return m_coord.y; }
    FIGURES type()  const { return m_type; }
    COLOR color() const {return m_color;}
    void set_coords(const Point& new_coords)    { m_coord = new_coords; }  
    friend std::ostream &operator<<(std::ostream &os, const Figure &obj);
    virtual std::vector<Point> get_moves() const = 0;
    void move(const Point &new_pos);
    void undo();
};

class WhitePawn : public Figure
{
    public:
        WhitePawn(const Point& p, ChessBoard *board) : Figure(p, PAWN, WHITE, board) {}
        virtual std::vector<Point> get_moves() const;
};

class BlackPawn : public Figure
{
    public:
        BlackPawn(const Point& p, ChessBoard *board) : Figure(p, PAWN, BLACK, board) {}
        virtual std::vector<Point> get_moves() const;
};

class Queen : public Figure
{
    public:
        Queen(const Point& p, COLOR color, ChessBoard *board) : Figure(p, QUEEN, color, board) {}
        std::vector<Point> get_moves() const;
};

class King : public Figure
{
    public:
        King(const Point& p, COLOR color, ChessBoard *board) : Figure(p , KING, color, board) {}
        std::vector<Point> get_moves() const;

};

class Rook : public Figure
{
    public:
        Rook(const Point& p, COLOR color, ChessBoard *board) : Figure(p, ROOK, color, board) {}
        std::vector<Point> get_moves() const;
};

class Bishop : public Figure
{
    public:
        Bishop(const Point& p, COLOR color, ChessBoard *board) : Figure(p, BISHOP, color, board) {}
        std::vector<Point> get_moves() const;
};

class Knight : public Figure
{
    public:
        Knight(const Point& p, COLOR color, ChessBoard *board) : Figure(p, KNIGHT, color, board) {}
        std::vector<Point> get_moves() const;
};


#endif