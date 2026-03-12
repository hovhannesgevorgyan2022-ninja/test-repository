#include <iostream>
#include <fstream>
#include "chessboard.h"
#include "figure.h"


ChessBoard::ChessBoard(const char *path)
{
    m_whites.reserve(16);
    m_blacks.reserve(16);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            m_board[i][j] = nullptr;
        }
    }
    read_file(path);
    if (!is_valid())
        exit(1);
}

ChessBoard::~ChessBoard()
{
    for(std::size_t i = 0 ; i < m_whites.size() ; i++)
    {
        delete m_whites[i];
    }
    for(std::size_t i = 0 ; i < m_blacks.size() ; i++)
    {
        delete m_blacks[i];
    }
}

bool    ChessBoard::is_valid() const
{
    if(m_blacks.size() > 16 || m_whites.size() > 16) 
    {
        std::cout << "Too many figures" << std::endl;
        return false;
    }
    int white_pawn_count = 0;
    int white_knight_count = 0;
    int white_bishop_count = 0;
    int white_rook_count = 0;
    int white_queen_count = 0;
    int white_king_count = 0;
    for(Figure* fig : m_whites)
    {
        if(fig->type() == PAWN)
        {
            white_pawn_count++;
        }
        if(fig->type() == KNIGHT)
        {
            white_knight_count++;
        }
        if(fig->type() == BISHOP)
        {
            white_bishop_count++;
        }
        if(fig->type() == ROOK)
        {
            white_rook_count++;
        }
        if(fig->type() == QUEEN)
        {
            white_queen_count++;
        }
        if(fig->type() == KING)
        {
            white_king_count++;
        }
    }
    if(white_bishop_count > 2 || white_knight_count > 2 || white_rook_count > 2 || white_king_count != 1 || white_queen_count > 1 || white_pawn_count > 8)
    {
        std::cout << "White figures invalid count" << std::endl;
        return false;
    }

    int black_pawn_count = 0;
    int black_knight_count = 0;
    int black_bishop_count = 0;
    int black_rook_count = 0;
    int black_queen_count = 0;
    int black_king_count = 0;
    for(Figure* fig : m_whites)
    {
        if(fig->type() == PAWN)
        {
            black_pawn_count++;
        }
        if(fig->type() == KNIGHT)
        {
            black_knight_count++;
        }
        if(fig->type() == BISHOP)
        {
            black_bishop_count++;
        }
        if(fig->type() == ROOK)
        {
            black_rook_count++;
        }
        if(fig->type() == QUEEN)
        {
            black_queen_count++;
        }
        if(fig->type() == KING)
        {
            black_king_count++;
        }
    }
    if(black_bishop_count > 2 || black_knight_count > 2 || black_rook_count > 2 || black_king_count != 1 || black_queen_count > 1 || black_pawn_count > 8)
    {
        std::cout << "Black figures invalid count" << std::endl;
        return false;
    }

    return true;
}

bool ChessBoard::read_file(const char *path)
{
    std::ifstream file(path);
    if (!file.is_open())
        return false;
    int value;
    for (int x = 0; x < 8 ; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            file >> value;
            if (value / 10 == 1) // white player
            {
                value = value % 10;
                switch(value) {
                    case KING: {
                        m_whites.push_back(new King({x, y}, WHITE, this));
                        break;
                    }
                    case QUEEN: {
                        m_whites.push_back(new Queen({x, y}, WHITE, this));
                        break;
                    }
                    case BISHOP: {
                        m_whites.push_back(new Bishop({x, y}, WHITE, this));
                        break;
                    }
                    case ROOK: {
                        m_whites.push_back(new Rook({x, y}, WHITE, this));
                        break;
                    }
                    case KNIGHT: {
                        m_whites.push_back(new Knight({x, y}, WHITE, this));
                        break;
                    }
                    case PAWN: {
                        m_whites.push_back(new WhitePawn({x, y}, this));
                        break;
                    }

                }
                m_board[x][y] = m_whites.back();
            }
            else if (value / 10 == 2) // black player
            {
                value = value % 10;
                switch(value) {
                    case KING: {
                        m_blacks.push_back(new King({x, y}, BLACK, this));
                        break;
                    }
                    case QUEEN: {
                        m_blacks.push_back(new Queen({x, y}, BLACK, this));
                        break;
                    }
                    case BISHOP: {
                        m_blacks.push_back(new Bishop({x, y}, BLACK, this));
                        break;
                    }
                    case ROOK: {
                        m_blacks.push_back(new Rook({x, y}, BLACK, this));
                        break;
                    }
                    case KNIGHT: {
                        m_blacks.push_back(new Knight({x, y}, BLACK, this));
                        break;
                    }
                    case PAWN: {
                        m_blacks.push_back(new BlackPawn({x, y}, this));
                        break;
                    }
                }
                m_board[x][y] = m_blacks.back();
            }
            // else - empty 
        }
    }
    file.close();
    return true;
}

void ChessBoard::print() const
{
    for (int x = 0; x < WIDTH ; x++ )
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            std::cout << m_board[x][y] << "\t";
        }
        std::cout << std::endl;

    } 
}

bool ChessBoard::is_check(COLOR col) const
{
    auto player = (col == WHITE) ? m_whites : m_blacks; // std::vector<Figure *>
    auto enemy = (col == WHITE) ? m_blacks :  m_whites;
    
    Figure *king;
    for (Figure *fig : player) // find the king
        if (fig->type() == KING)
        {
            king = fig;
            break;
        }
    for (Figure *fig : enemy) // check whether any one piece is attacking the king 
        for (Point &p : fig->get_moves())
        {
            if (p.x == king->x() && p.y == king->y())
                return true;
        }
    return false;
}

bool ChessBoard::is_mate(COLOR col)
{
    if (!is_check(col))
        return false;
    auto player = (col == WHITE) ? m_whites : m_blacks; // std::vector<Figure *>
    auto enemy = (col == WHITE) ? m_blacks :  m_whites;
    
    Figure *king;
    for (Figure *fig : player) // find the king
        if (fig->type() == KING)
        {
            king = fig;
            break;
        }
    auto king_moves = king->get_moves();
    for (auto p : king_moves)
    {
        king->move(p);
        if (!is_check(col))
            return false; // if there is a capture by king without check, not mate
        king->undo();
    }
    for (auto *fig : player)
    {
        if (fig->type() == FIGURES::KING)
            continue;
        for (auto &p : fig->get_moves())
        {
            fig->move(p);
            if (!is_check(col))
                return false;
            fig->undo();
        }
    }
    return true;
}

void ChessBoard::simulate()
{
    // for (auto *fig : m_whites) {            //print white available moves
    //     std::cout << *fig << ": ";
    //     for (Point &p : fig->get_moves())
    //         std::cout << "(" << p.x << " " << p.y << ") ";
    //     std::cout << std::endl;
    // }
    //  for (auto *fig : m_blacks) {            //print black available moves
    //     std::cout << *fig << ": ";
    //     for (Point &p : fig->get_moves())
    //         std::cout << "(" << p.x << " " << p.y << ") ";
    //     std::cout << std::endl;
    // }
    for (auto *fig : m_whites)
    {
        for (auto m : fig->get_moves())
        {
            // move the figure and check if mate
            fig->move(m);
            if (is_mate(COLOR::BLACK)) {
                std::cout << "mate in 1 move" << std::endl;
                exit(0); 
            }
            fig->undo();
        }
    }
}

bool ChessBoard::is_free(int x , int y) const
{
    if (m_board[x][y] == nullptr)
        return true;
    return false;
}

bool ChessBoard::is_placed_oppenent_figure(int x , int y , COLOR col) const
{
    if (m_board[x][y] && m_board[x][y]->color() != col)
        return true;
    return false;
}

bool ChessBoard::is_under_attack(int x , int y , COLOR col) const
{
    auto &enemy = (col == WHITE) ? m_blacks : m_whites;
    for (auto *fig : enemy)
    {
        if (fig->type() == FIGURES::KING) continue;
        for (Point &p : fig->get_moves())
            if (p.x == x && p.y == y)
                return true;
    }
    return false;
}


